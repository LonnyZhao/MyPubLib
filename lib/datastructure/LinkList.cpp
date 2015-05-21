#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
};
typedef struct Node * LinkList;			/*定义LinkList*/
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：用e返回L中第i个数据元素的值*/
Status GetElem(LinkList  L, int i, ElemType *e)
{
	int j;
	LinkList p;			
	p = L->next;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i)
	{
		return ERROR;
	}
	else
	{
		*e = p->data;
	}
	return OK;
}
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：在L中第i个将节点位置之前插入新的数据元素e,L的长度加1*/
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)		/*寻找第i-1个节点*/
	{
		p = p->next;
		++j;
	}
	if (!p || j>i)
	{
		return ERROR;			/*第i个节点不存在*/
	}
	s = (LinkList)malloc(sizeof(Node));			//生成一个新的节点
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：删除L的第i个节点，并且用e返回其值，L的长度减1*/
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i)			/*遍历寻找第i-1个节点*/
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j>i)
	{
		return ERROR;
	}

	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}
/*随机产生n个元素的值，建立带表头节点的单链线性表L（头插法）*/
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0));						/*初始化随机数种子*/
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;					/*先建立一个带头结点的单链表*/
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;			/*随机生成100以内的数字*/
		p->next = (*L)->next;
		(*L)->next = p;						/*插入表头*/
	}
}
/*随机产生n个元素的值，建立带表头节点的单链线性表L（尾插法）*/
void CreateListTail(LinkList *L, int n)
{

	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;				/*r为指向尾部的节点*/
	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;				/*表示当前链表结束*/
}
/*初始条件：顺序线性表L已存在，操作结果：将L重置为空表*/
Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;			/*皇帝立的遗嘱：实际就是下一个待杀头的人，太血腥了*/
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}