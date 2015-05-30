/*************************************************************************
	> File Name: big_or_little_endian.c
	> Author: 
	> Mail: 
	> Created Time: 2015年05月26日 星期二 22时57分14秒
 ************************************************************************/

#include<stdio.h>

union Student{
    int i;
    unsigned char ch[2];
};
int main()
{
    union Student student;
    student.i = 0x1420;
    printf("%d %d", student.ch[0], student.ch[1]);
    return 0;
}
