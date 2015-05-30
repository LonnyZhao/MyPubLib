/*************************************************************************
	> File Name: struct_bit_fragment.c
	> Author: 
	> Mail: 
	> Created Time: 2015年05月26日 星期二 22时32分57秒
 ************************************************************************/

#include<stdio.h>

struct bs
{
    unsigned int a:1;
    unsigned int b:3;
    unsigned int c:4;
};
int main()
{
    struct bs bit;
    struct bs *pbit;
    
    bit.a = 1;
    bit.b = 7;
    bit.c = 15;

    printf("%d, %d, %d \n", bit.a, bit.b, bit.c);

    pbit = &bit;

    pbit->a = 0;
    pbit->b &= 3;
    pbit->c |= 1;
    printf("%d, %d, %d \n",pbit->a, pbit->b, pbit->c);

    printf("sizeof struct:%ld\n",sizeof(bit));
}
