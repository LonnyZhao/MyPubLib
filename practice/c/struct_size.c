/*************************************************************************
	> File Name: struct_size.c
	> Author: 
	> Mail:
    > Brief Des:各类结构体大小示例
	> Created Time: 2015年06月01日 星期一 22时03分19秒
    > Ref:王道程序员求职宝典
 ************************************************************************/

#include<stdio.h>
/*
*计算结构体空间大小的原则：
*1.整体空间是占用空间最大的成员类型所占字节数的整数倍，但在linux+gcc环境下，若最大
*成员类型所占字节数超过4，如double是8，则整体空间是4的倍数
*2.数据对齐原则--内存按结构体成员的先后顺序排列，当排到该成员变量时，其前面已摆放
*的空间大小必须是该成员类型大小的整数倍
*3.存在位域的结构体大小计算：
*1）如果相邻位域字段的类型相同，且其位宽之和小于类型的sizeof大小，则后面的字段将紧邻
*前一个字段存储，直到不能容纳为止
*2）如果相邻位域字段的类型相同，但其位宽之和大于类型的sizeof大小，则后面的字段将从新的
*存储单元开始，其偏移量为其类型大小的整数倍
*3）如果相邻位域字段的类型不同，则各编译器的具体实现有差异，vc6采取不压缩方式，Dev-C++
*与gcc采取压缩方式
*4）如果位域字段之间穿插着非位域字段，则不进行压缩
*5）整个结构提的总大小为最宽基本类型成员大小的整数倍
*
*
*
*使用伪指令改变默认对齐方式：
*1）#pragma pack(n),编译器将按照n个字节对齐
*2）#pragma pack(),取消自定义字节对齐
*
*
* */

/*结构体中有数组时的大小*/
typedef struct st_with_array{
    char a[8];
    int b;
}StWithArray;


/*结构中有结构体*/
struct s1{
    char a[8];
};
struct s2{
    double d;
};
struct s3{ //整体空间是自结构体与父结构体中占用空间最大的成员（的类型）所占字节数的整数倍
    char a;
    struct s1 s;
};
struct s4{
    struct s2 s;
    char a;
};


/*含位域结构体的空间计算*/
typedef struct st_with_bit{
    int f1:3;
    char b;
    char c;
}StWithBit;
typedef struct st_with_bit2{
    char f1:3;
    char f2:4;
    char f3:5;
}StWithBit2;
typedef struct st_with_bit3{
    char f1:3;
    short f2:4;
    char f3:5;
}StWithBit3;
/*使用pack*/
#pragma pack(push)//将当前pack设置压栈
#pragma pack(2) //必须在结构体定义之前使用
struct S1{
    char c;
    int i;
};
struct S3{
    char c1;
    struct S1 s;
    char c2;
};
#pragma pack(pop)
typedef struct st_empty{

}StEmpty;
int main(void)
{
    /*结构体中有数组时的大小测试*/
    printf("结构体中有数组：%d\n",sizeof(StWithArray));//结果为12
    printf("sizeof s1:%d\n",sizeof(struct s1)); //8
    printf("szieof s2:%d\n",sizeof(struct s2)); //8
    printf("sizeof s3:%d\n",sizeof(struct s3));//9
    printf("sizeof s4:%d\n",sizeof(struct s4));//16
    printf("sizeof st_with_bit:%d\n",sizeof(StWithBit));//4
    printf("sizeof st_with_bit2:%d\n",sizeof(StWithBit2));//2
    printf("sizeof st_with_bit3:%d\n",sizeof(StWithBit3));//2
    printf("sizeof prama S1:%d\n",sizeof(struct S1));//6
    printf("szieof prama S2:%d\n",sizeof(struct S3));//10
    printf("empty struct:%d\n",sizeof(StEmpty));//1
    return 0;
}
