/*************************************************************************
	> File Name: debug.h
	> Author: 
	> Mail: 
	> Created Time: 2015年10月05日 星期一 16时17分47秒
 ************************************************************************/

#ifndef _DEBUG_H
#define _DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

#define return_if_fail(p) if(!(p))  \
    {printf("%s:%d Warning: "#p" failed.\n", \
    __func__,__LINE__); return;}

#define return_val_if_fail(p, ret) if(!(p)) \
    {printf("%s:%d Warning:"#p" failed.\n",    \
    __func__,__LINE__); return (ret);}

#ifdef __cplusplus
}
#endif
#endif /* end of DEBUG_H*/
