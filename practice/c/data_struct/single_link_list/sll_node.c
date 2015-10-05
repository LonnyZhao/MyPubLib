/*************************************************************************
	> File Name: sll_node.c
    > Brief: 维护一个有序单链表
	> Author: Lonny
	> Mail: 
	> Created Time: 2015年10月02日 星期五 02时42分43秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "sll_node.h"

/*
 * 函数功能：插入一个有序链表中
* */
int sll_insert(Node *current, int new_value)
{
    Node *previous = NULL;
    Node *new = NULL;
    
    /*
     * 寻找正确的插入位置
     * 方法：按顺序访问链表，直到到达其值大于或等于新插入值的节点
    *
    * */

    while(current->vlaue < new_value){
        previous = current;
        current = current->link;
    } 

    /*
     * 为新节点分配内存，并把新值存储到新的节点中，如果内存分配失败
     * 函数返回FALSE
    */
    new = (Node *)malloc(sizeof(Node));
    if(new == NULL)
        return FALSE;
    new->value = new_value;

    /*
     *将新节点插入到链表中，并返回TRUE
    * */
    new->link = current;
    previous->link = new;
    return TRUE;
}
