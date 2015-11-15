/*************************************************************************
	> File Name: mod_change.c
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年11月15日 星期日 16时26分06秒
 ************************************************************************/

#include<stdio.h>
#include "apue.h"

int main(void)
{
    struct stat statbuf;

    if(stat("foo", &statbuf) < 0)
    {
        err_sys("stat error for fooo");
    }

    if(chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
    {
        err_sys("chmod error for foo");
    }

    if(chmod("bar", S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH))
    {
        err_sys("chmod error for bar");
    }

    exit(0);
}
