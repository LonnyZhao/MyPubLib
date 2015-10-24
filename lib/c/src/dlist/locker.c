/*************************************************************************
	> File Name: locker.c
	> Brief: 锁接口的部分实现 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月06日 星期二 04时02分36秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "locker.h"

inline ret_e locker_lock(locker_s *thiz)
{
    return_val_if_fail(thiz != NULL && thiz->lock != NULL, RET_INVALID_PARAMS);

    return thiz->lock(thiz);
}

inline ret_e locker_unlock(locker_s *thiz)
{
    return_val_if_fail(thiz != NULL && thiz->lock != NULL, RET_INVALID_PARAMS);

    return thiz->unlock(thiz);
}

inline void locker_destroy(locker_s *thiz)
{
    return_if_fail(thiz != NULL && thiz->destroy != NULL);

    thiz->destroy(thiz);
    
    return;
}
