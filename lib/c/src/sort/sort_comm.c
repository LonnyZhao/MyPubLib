/*************************************************************************
	> File Name: sort_common.c
	> Brief: 本文件中的内容是辅助sort库的，主要提供如cmp功能的实现等 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月05日 星期一 19时34分40秒
 ************************************************************************/

#include <stdio.h>

int int_cmp(void *a, void *b)
{
    return (int)(a) - (int)(b);
}

int int_cmp_invert(void *a, void *b)
{
    return (int)(b) - (int)(a);
}
