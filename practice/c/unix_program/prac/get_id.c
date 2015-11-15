/*************************************************************************
	> File Name: get_id.c
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年11月08日 星期日 18时14分29秒
 ************************************************************************/

#include "apue.h"

int main(void)
{
    printf("uid=%d, gid=%d\n", getuid(), getgid());
    exit(0);
}

