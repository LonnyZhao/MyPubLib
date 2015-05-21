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
typedef struct Node * LinkList;			/*����LinkList*/
/*��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)*/
/*�����������e����L�е�i������Ԫ�ص�ֵ*/
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
/*��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)*/
/*�����������L�е�i�����ڵ�λ��֮ǰ�����µ�����Ԫ��e,L�ĳ��ȼ�1*/
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)		/*Ѱ�ҵ�i-1���ڵ�*/
	{
		p = p->next;
		++j;
	}
	if (!p || j>i)
	{
		return ERROR;			/*��i���ڵ㲻����*/
	}
	s = (LinkList)malloc(sizeof(Node));			//����һ���µĽڵ�
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
/*��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)*/
/*���������ɾ��L�ĵ�i���ڵ㣬������e������ֵ��L�ĳ��ȼ�1*/
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i)			/*����Ѱ�ҵ�i-1���ڵ�*/
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
/*�������n��Ԫ�ص�ֵ����������ͷ�ڵ�ĵ������Ա�L��ͷ�巨��*/
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0));						/*��ʼ�����������*/
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;					/*�Ƚ���һ����ͷ���ĵ�����*/
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;			/*�������100���ڵ�����*/
		p->next = (*L)->next;
		(*L)->next = p;						/*�����ͷ*/
	}
}
/*�������n��Ԫ�ص�ֵ����������ͷ�ڵ�ĵ������Ա�L��β�巨��*/
void CreateListTail(LinkList *L, int n)
{

	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;				/*rΪָ��β���Ľڵ�*/
	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;				/*��ʾ��ǰ�������*/
}
/*��ʼ������˳�����Ա�L�Ѵ��ڣ������������L����Ϊ�ձ�*/
Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;			/*�ʵ�����������ʵ�ʾ�����һ����ɱͷ���ˣ�̫Ѫ����*/
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}