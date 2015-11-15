/*************************************************************************
	> File Name: file_stat.c
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年11月15日 星期日 12时53分41秒
 ************************************************************************/

#include "apue.h"

int main(int argc, char *argv[])
{
    int i;
    struct stat buf = {0};

    char *ptr;

    for(i = 1; i < argc; i++)
    {
        printf("%s:",argv[i]);
        if(lstat(argv[i], &buf) < 0)
        {
            err_ret("lstat error");
            continue;
        }

        if(S_ISREG(buf.st_mode))
        {
            ptr = "regular";
        }
        else if(S_ISDIR(buf.st_mode))
        {
            ptr = "directory";
        }
        else if(S_ISBLK(buf.st_mode))
        {
            ptr = "block special";
        }
        else if(S_ISFIFO(buf.st_mode))
        {
            ptr = "fifo";
        }
        else if(S_ISLNK(buf.st_mode))
        {
            ptr = "symbolic link";
        }
        else if(S_ISSOCK(buf.st_mode))
        {
            ptr = "socket";
        }
        else
        {
            ptr = "*** unknown mode ***";
        }
        printf("%s\n",ptr);
    }
    exit(0);
}

