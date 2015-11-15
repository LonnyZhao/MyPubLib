/*************************************************************************
	> File Name: error_print.c
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年11月08日 星期日 18时01分53秒
 ************************************************************************/

#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[])
{
    fprintf(stderr,"EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}

