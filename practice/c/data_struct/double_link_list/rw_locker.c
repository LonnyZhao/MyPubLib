/*************************************************************************
	> File Name: rw_locker.c
	> Brief: 读写锁实现
    读写锁基本要求：写的时候不允许其他线程读或写，读的时候允许其他线程读，但是
    不允许其他线程写。
    读写锁充分发挥作用的条件：
    （1）读写不对称性，读的次数远远大于写的次数
    （2）处于临界区的时间比较长
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月06日 星期二 06时11分27秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "locker.h"
#include "rw_locker.h"

rw_locker_s *rw_locker_create(locker_s *rw_locker, locker_s *rd_locker)
{
    rw_locker_s *thiz = NULL;
    return_val_if_fail(rw_locker != NULL && rd_locker != NULL, NULL);

    thiz = (rw_locker_s *)malloc(sizeof(rw_locker_s));
    if(thiz != NULL)
    {
        thiz->readers = 0;
        thiz->mode = RW_LOCKER_NONE;
        thiz->rw_locker = rw_locker;
        thiz->rd_locker = rd_locker;
    }

    return thiz;
}
/**
 * 加写锁过程：直接加用来保护受保护对象的锁，修改锁状态为已加写锁
 * 后面其他线程如果想写或者读，需要等待
* */
ret_e rw_locker_wrlock(rw_locker_s *thiz)
{
    ret_e ret = RET_OK;

    return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

    if((ret = locker_lock(thiz->rw_locker)) == RET_OK)
    {
        thiz->mode = RW_LOCKER_WR;
    }

    return ret;
}
/**
 * 加读锁过程：
 * （1）先尝试加用来保护引用计数的锁，激昂引用计数加1；
 * （2）若当前线程是第一个读操作线程，加用来保护受保护对象的锁
 * （3）若此时已有线程在执行写，则等待，知道加锁成功
 * （4）然后把锁的状态设置成已加读锁
 * （5）解开受保护引用计数的锁
* */
ret_e rw_locker_rdlock(rw_locker_s *thiz)
{
    ret_e ret = RET_OK;
    return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

    if((ret = locker_lock(thiz->rd_locker)) == RET_OK)
    {
        thiz->readers++;
        /*第一个加读锁的线程还要加写锁，即有人读则禁止写*/
        if(thiz->readers == 1)
        {
            ret = locker_lock(thiz->rw_locker);
            thiz->mode = RW_LOCKER_RD;
        }
        locker_unlock(thiz->rd_locker);
    }

    return ret;
}

/**
 * 解锁过程：
 * 根据状态来决定解写锁还是解读锁
* */
ret_e rw_locker_unlock(rw_locker_s *thiz)
{
    ret_e ret = RET_OK;
    return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

    if(thiz->mode == RW_LOCKER_WR)
    {
        /* 解写锁*/
        thiz->mode =  RW_LOCKER_NONE;
        ret = locker_unlock(thiz->rw_locker);
    }
    else
    {
        /* 解读锁,需检查是否有其他线程在读*/
        assert(thiz->mode == RW_LOCKER_RD);
        if((ret = locker_lock(thiz->rd_locker)) == RET_OK)
        {
            thiz->readers--;
            if(thiz->readers == 0)
            {
                thiz->mode = RW_LOCKER_NONE;
                ret = locker_unlock(thiz->rw_locker);
            }
            locker_unlock(thiz->rd_locker);
        }
    }

    return ret;
}

void rw_locker_destory(rw_locker_s *thiz)
{
    if(thiz != NULL)
    {
        locker_destroy(thiz->rd_locker);
        locker_destroy(thiz->rw_locker);
        thiz->rd_locker = NULL;
        thiz->rw_locker = NULL;
        SAFE_FREE(thiz);
    }

    return;
}

