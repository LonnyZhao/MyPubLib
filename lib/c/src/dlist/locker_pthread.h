/*************************************************************************
	> File Name: locker_pthread.h
	> Brief:  Linux平台下的锁操作实现 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月06日 星期二 04时19分56秒
 ************************************************************************/

#ifndef _LOCKER_PTHREAD_H
#define _LOCKER_PTHREAD_H
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif
/**
 * Linux 平台下锁结构私有数据
 *
**/
typedef struct private_info_t
{
    pthread_mutex_t mutex;  /**< Linux平台下互斥量*/
}private_info_s;
/**
 * Linux平台创建锁函数，会创建私有数据并且挂接Linux平台下locker的实现接口
* **/
locker_s *locker_pthread_create(void);
#ifdef __cplusplus
}
#endif
#endif
