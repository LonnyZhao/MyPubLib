/*************************************************************************
	> File Name: typedef.h
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月05日 星期一 17时19分37秒
 ************************************************************************/

#ifndef _TYPEDEF_H
#define _TYPEDEF_H
typedef enum ret_t
{
    RET_OK,
    RET_ERROR,
    RET_FAIL,
    RET_STOP,
    RET_INVALID_PARAMS,
    RET_OUT_OF_MEM,
    RET_MAX
}ret_e;

#define TRUE 1
#define FALSE 0

typedef void (*data_destroy_func)(void *ctx, void *data);
typedef int (*data_compare_func)(void *ctx, void *data);
typedef ret_e (*data_visit_func)(void *ctx, void *data);
typedef int (*data_hash_func)(void *data);
#endif

