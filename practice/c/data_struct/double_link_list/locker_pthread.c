/*************************************************************************
	> File Name: locker_pthread.c
	> Brief:  用于实现locker接口中的Linux平台下相应函数 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月06日 星期二 04时28分43秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "locker.h"
#include "locker_pthread.h"

static ret_e locker_pthread_lock(locker_s *thiz)
{
    int ret = 0;
    
    private_info_s *priv = (private_info_s *)thiz->priv;

    ret = pthread_mutex_lock(&priv->mutex);

    return ret == 0 ? RET_OK : RET_FAIL;
}

static ret_e locker_pthread_unlock(locker_s *thiz)
{
    int ret = 0;

    private_info_s *priv = (private_info_s *)thiz->priv;

    ret = pthread_mutex_unlock(&priv->mutex);

    return ret == 0 ? RET_OK : RET_FAIL;
}

static void locker_pthread_destroy(locker_s *thiz)
{
    int ret = 0;

    private_info_s *priv = (private_info_s *)thiz->priv;

    ret = pthread_mutex_destroy(&priv->mutex);

    SAFE_FREE(thiz);

    return;
}

locker_s *locker_pthread_create(void)
{
    locker_s *thiz = (locker_s *)malloc(sizeof(locker_s) + sizeof(private_info_s));

    if(thiz != NULL)
    {
        private_info_s *priv = (private_info_s *)thiz->priv;

        thiz->lock = locker_pthread_lock;
        thiz->unlock = locker_pthread_unlock;
        thiz->destroy = locker_pthread_destroy;

        pthread_mutex_init(&priv->mutex, NULL);
    }

    return thiz;
}
