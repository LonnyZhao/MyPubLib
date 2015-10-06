/*************************************************************************
	> File Name: rw_locker.h
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月06日 星期二 05时58分22秒
 ************************************************************************/

#ifndef _RW_LOCKER_H
#define _RW_LOCKER_H
#ifdef __cplusplus
#include "locker.h"

extern "C" {
#endif

/**
 * 读写锁模式枚举类型
* */
typedef enum rw_locker_mode_t
{
    RW_LOCKER_NONE,   /**< 不加锁*/
    RW_LOCKER_WR,     /**< 加写锁*/
    RW_LOCKER_RD,     /**< 加读锁*/
    RW_LOCKER_NR,     /**< 非上述任何类型的锁*/
    RW_LOCKER_MAX
}rw_locker_mode_e;

typedef struct rw_locker_t
{
    int readers;
    rw_locker_mode_e mode;
    locker_s *rw_locker;
    locker_s *rd_locker;
}rw_locker_s;

/**
 * @breif 创建读写锁
 * */
rw_locker_s *rw_locker_create(locker_s *rw_locker, locker_s *rd_locker);

/**
 * @brief 加写锁
 * */
ret_e rw_locker_wrlock(rw_locker_s *thiz);

/**
 * @brief 加读锁
 * */
ret_e rw_locker_rdlock(rw_locker_s *thiz);

/**
 * @brief 解锁过程
 * */
ret_e rw_locker_unlock(rw_locker_s *thiz);

/**
 * @brief 释放锁
 * */
void rw_locker_destory(rw_locker_s *thiz);
#ifdef __cplusplus
}
#endif
#endif
