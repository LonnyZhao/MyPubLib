/*************************************************************************
	> File Name: common.h
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月05日 星期一 17时06分44秒
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H
#ifdef __cplusplus
extern "C" {
#endif

#define SAFE_FREE(p) if(p != NULL) {free(p); p = NULL;}
#ifdef __cplusplus
}
#endif /*  end of __cplusplus*/
#endif  /*end of _COMMON_H*/
