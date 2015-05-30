/*************************************************************************
	> File Name: big_or_little_endian_judge.c
	> Author: 
	> Mail: 
	> Created Time: 2015年05月26日 星期二 23时09分29秒
 ************************************************************************/

#include<stdio.h>

#define BIG_ENDIAN 0
#define LITTLE_ENDIAN 1

int TestByteOrder()
{

    short int word = 0x0001;
    char *byte = (char *)&word;
    return (byte[0] ? LITTLE_ENDIAN : BIG_ENDIAN);
}
int main()
{
    if(LITTLE_ENDIAN == TestByteOrder())
    {
        printf("This computer is a little endian one!\n");
    }
    else
    {
        printf("This computer is a big endian one!\n");
    }
}
