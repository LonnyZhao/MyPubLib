/*************************************************************************
	> File Name: locker.h
	> Brief:  锁接口声明 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月06日 星期二 03时51分56秒
 ************************************************************************/

#ifndef _LOCKER_H
#define _LOCKER_H
#ifdef __cplusplus
extern "C" {
#endif

/**
 *锁类型描述
 *
**/
typedef struct locker_t
{
    ret_e (*lock)(struct locker_t *thiz);       /**< 加锁函数接口*/
    ret_e (*unlock)(struct locker_t *thiz);     /**< 解锁函数接口*/
    void (*destroy)(struct locker_t *thiz);    /**< 销毁函数接口*/

    char priv[0];                        /**< 存放上下问信息，即具体实现用到的数据结构*/
}locker_s;


/**
 *创建锁基本函数，封装判断参数有效性部分
 *
 * @param[in]  thiz 外部创建锁
 * 
 * @return RET_OK 创建成功
 * @return 其他   创建失败
 *
 **/
ret_e locker_lock(locker_s *thiz);

/**
 * 解除锁基本函数，封装判断参数有效性部分
 *
 * @param[in] thiz 外部创建锁
 *
 * @return RET_OK 解锁成功
 * @return 其他   解锁失败
 **/
ret_e locker_unlock(locker_s *thiz);
/**
 * 销毁锁基本函数，封装判断参数有效性部分
 * 
 * @param[in] thiz 外部创建锁
 * 
 * @return void
 **/
void locker_destroy(locker_s *thiz);
#ifdef __cplusplus
}
#endif
#endif
