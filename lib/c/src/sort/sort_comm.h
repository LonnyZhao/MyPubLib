/*************************************************************************
	> File Name: sort_comm.h
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月05日 星期一 19时29分54秒
 ************************************************************************/

#ifndef _SORT_COMM_H
#define _SORT_COMM_H
#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief 整数逆排序使用
 * 
 * @param[in] a 第一个值
 * @param[in] b 第二个值
 * @return   a - b的值
**/
int int_cmp_invert(void *a, void *b);
/**
 * @brief 整数升序排序使用
 * 
 * @param[in] a 第一个数
 * @param[in] b 第二个数
 * @return   b - a的值
**/
int int_cmp(void *a, void *b);
typedef int (*DataCompareFunc)(void* ctx, void* data);
#ifdef __cplusplus
}
#endif
#endif
