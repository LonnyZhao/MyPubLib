/*************************************************************************
	> File Name: umask.c
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年11月15日 星期日 16时10分31秒
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(void)
{
    umask(0);
    if(creat("foo",RWRWRW) < 0)
    {
        err_sys("create error for foo");
    }

    umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);

    if(creat("bar",RWRWRW) < 0)
    {
        err_sys("create error for bar");
    }

    exit(0);
}

