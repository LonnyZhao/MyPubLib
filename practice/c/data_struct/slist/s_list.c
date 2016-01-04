/*
 * s_list.c
 *
 *  Created on: 2016年1月2日
 *      Author: Lonny
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "s_list.h"

/**
 * @brief 内部用释放数据内存函数
 * */
static void slist_destroy_data(slist_s *thiz, void *data)
{
	if(NULL != thiz->data_destroy)
	{
		thiz->data_destroy(thiz->data_destroy_ctx, data);
	}

	return ;
}
/*
 * @brief 内部用创建节点函数
 *
 * */
static slist_node_s *slist_create_node(slist_s *thiz, void *data)
{
	slist_node_s *node = (slist_node_s *)malloc(sizeof(slist_node_s));

	if(NULL != node)
	{
		node->data = data;
		node->next = NULL;
	}

	return node;
}
/*
 * @brief 内部用释放节点函数
 *
 * */
static void slist_destroy_node(slist_s *thiz, slist_node_s  *node)
{
	if(NULL != node)
	{
		node->next = NULL;
		slist_destroy_data(thiz, node->data);
		SAFE_FREE(node);
	}
	return ;
}
/*
 * @brief 创建单链表函数
 *
 * ＠param[in] data_destroy 链表回收节点内容函数
 * ＠param[in] ctx                链表描述上下文
 *
 * @return  链表指针
 * */
slist_s *slist_create(slist_data_destroy_func data_destroy, void *ctx)
{
	slist_s *thiz = (slist_s *)malloc(sizeof(slist_s));
	if(NULL != thiz)
	{
		thiz->data_destroy_ctx = ctx;
		thiz->data_destroy = data_destroy;
		thiz->first = NULL;
	}

	return thiz;
}

/*
 *@brief 内部使用函数，用于获取节点
 * */
static slist_node_s *slist_get_node(slist_s *thiz, size_t index, int fail_return_last)
{
	slist_node_s  *iter = NULL;
	size_t t_index = index;
	return_val_if_fail(thiz != NULL, NULL);

	 iter = thiz->first;

	 while(iter != NULL  && iter->next != NULL && t_index > 0)
	 {
		 iter = iter->next;
		 t_index--;
	 }

	 if(!fail_return_last)
	 {
		 iter = t_index> 0 ? NULL : iter;
	 }

	 return iter;
}

/*
 * @brief 单链表插入函数
 *
 *＠param[in]  thiz 链表指针
 *＠param[in]  index 插入位置，从０开始，－１表示在尾部插入
 *＠param[in]  data 插入的数据
 * */
ret_e slist_insert(slist_s *thiz, size_t index, void *data)
{
	ret_e ret = RET_OK;
	slist_node_s *node = NULL;
	slist_node_s *cursor = NULL;

	return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

	do
	{
		/*创建一个节点*/
		if((node = slist_create_node(thiz, data)) == NULL)
		{
			ret = RET_OUT_OF_MEM;
			break;
		}

		/* 判断是否为空链表*/
		if(NULL == thiz->first)
		{
			thiz->first = node;
			break;
		}

		/* 获取插入位置*/
        if(index >= 1)
        {
		    cursor = slist_get_node(thiz, index-1, TRUE);
        }
        else
        {
            cursor = thiz->first;
            node->next = cursor;
            thiz->first =  node;
            break;
        }

		node->next = cursor->next;
		cursor->next = node;
	}while(0);

	return ret;
}

/*
 *@brief 单链表按序插入函数，注意使用中，需要保证原链表为有序链表
 *
 *@param[in] thiz 链表指针
 *@param[in] cmp 比较函数
 *@param[in] data 插入数据
 *@param[in] order 排序方式
 *
 *＠return 是否插入成功
 * */
ret_e slist_insert_in_order(slist_s *thiz, slist_data_compare_func cmp,void *data,  slist_order_e order)
{
	ret_e ret = RET_OK;
	slist_node_s *prev = NULL;
	slist_node_s *iter = NULL;
	slist_node_s *node = NULL;
	return_val_if_fail(thiz != NULL && cmp != NULL, RET_INVALID_PARAMS);
	return_val_if_fail(order < SLIST_SORT_MAX, RET_INVALID_PARAMS);

	/* 处理特殊情形*/
	if(thiz->first == NULL)
	{
		slist_prepend(thiz, data);
		return ret;
	}
	/*根据排序顺序查找插入位置*/
	prev = thiz->first;
	iter =  prev;
	while(iter != NULL)
	{
		if(SLIST_SORT_ASC_ORDER == order)
		{
			/*根据升序进行排序*/
			if(cmp(iter->data, data) >= 0)
			{
				prev = iter;
				iter = iter->next;
			}
			else
			{
				break;
			}
		}
		else if(SLIST_SORT_DESC_ORDER == order)
		{
			/*根据降序进行排序*/
			if(cmp(iter->data, data) <= 0)
			{
				prev = iter;
				iter = iter->next;
			}
			else
			{
				break;
			}
		}
	}

	if((node = slist_create_node(thiz, data)) == NULL)
	{
		ret = RET_OUT_OF_MEM;
		return ret;
	}

	if(iter == prev)
	{
		node->next = iter;
		thiz->first = node;
	}
	else
	{
		node->next = iter;
		prev->next = node;
	}

 	return ret;
}

/*
 * @brief 在链表头部插入节点
 * */
ret_e slist_prepend(slist_s *thiz, void *data)
{
	return slist_insert(thiz, 0 , data);
}

/*
 * @brief 在链表尾部插入节点
 * */
ret_e slist_append(slist_s *thiz, void *data)
{
	return slist_insert(thiz, -1 , data);
}

/*
 * @brief 删除链表指定index元素
 *
 * ＠param[in] thiz　链表指针
 * @param[in] index 删除链表所在索引
 * */
ret_e slist_delete(slist_s *thiz, size_t index)
{
    ret_e ret = RET_OK;
    slist_node_s *cursor = NULL;
    slist_node_s *del_node = NULL;
	return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

    do
    {
        if(0 == index)
        {
            cursor  = thiz->first;
            thiz->first = thiz->first->next;
            slist_destroy_node(thiz, cursor);
            break;
        }
        
        cursor = slist_get_node(thiz, index-1, 0);

        if(NULL == cursor || NULL == cursor->next)
        {
            ret = RET_INVALID_PARAMS;
            break;
        }

        del_node = cursor->next;
        cursor->next = del_node->next;
        
        slist_destroy_node(thiz ,del_node);
    }while(0);

    return ret;
}
/*
 * @brief 单链表查找函数
 *
 * ＠param[in] thiz 链表指针
 * @param[in] cmp 比较函数
 * ＠param[in] ctx   比较上下文
 *
 * @return 查找到的节点所在的索引位置，若未查找到则返回－１
 * */
int slist_find(slist_s*thiz, slist_data_compare_func cmp, void *ctx)
{
    int index = 0;
    slist_node_s *iter = NULL;

    return_val_if_fail(thiz != NULL && cmp != NULL , RET_INVALID_PARAMS);

    iter = thiz->first;
    while(iter != NULL)
    {
        if(cmp(ctx, iter->data) == 0)
        {
            break;
        }
        iter = iter->next;
        index++;
    }
    
    return index >= slist_length(thiz) ? -1 : index;
}

/*
 *@brief　通过index获取链表数据
 *
 *＠param[in] thiz    链表指针
 *＠param[in] index 获取的索引位置
 *＠param[in] data  获取到数据时的data域内容
 *
 *＠return 是否获取成功
 * */
ret_e slist_get_by_index(slist_s *thiz, size_t index, void **data)
{
    slist_node_s *cursor = NULL;

    return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

    cursor = slist_get_node(thiz, index, 0);
    
    if(cursor != NULL)
    {
        *data = cursor->data;
    }

    return cursor != NULL ? RET_OK : RET_INVALID_PARAMS;
}

/*
 * ＠brief　通过index设置链表数据
 *
 *＠param[in] thiz 链表指针
 *＠param[in] index 设置的索引位置
 *＠param[in] data 设置的数据内容
 * */
ret_e slist_set_by_index(slist_s *thiz, size_t index, void *data)
{
    slist_node_s *cursor = NULL;

    return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

    cursor = slist_get_node(thiz, index, 0);

    if(cursor != NULL)
    {
        slist_destroy_data(thiz, cursor->data);

        cursor->data = data;
    }

    return cursor != NULL ? RET_OK : RET_INVALID_PARAMS;
}

/*
 *@brief foreach实现函数
 *
 *@param[in] thiz 单链表指针
 *@param[in] visit 轮询执行函数
 *@param[in] ctx 执行上下文
 * */
ret_e slist_foreach(slist_s *thiz, slist_data_visit_func visit, void *ctx)
{
    ret_e ret = RET_OK;
    slist_node_s *iter = NULL;

    return_val_if_fail(thiz != NULL && visit != NULL, RET_INVALID_PARAMS);

    iter = thiz->first;
    while(iter != NULL)
    {
        ret = visit(ctx, iter->data);
        if(ret != RET_OK)
        {
        	break;
        }
        iter = iter->next;
    }

    return ret;
}

/**
 * @brief 获取链表长度
 *
 * @param[in] thiz 链表指针
 *
 *@return 链表长度
 * */
size_t slist_length(slist_s *thiz)
{
    size_t len = 0;
    slist_node_s *iter = NULL;

    return_val_if_fail(thiz != NULL, 0);

    iter = thiz->first;
    while(iter != NULL)
    {
        len++;
        iter = iter->next;
    }
    
    return len;
}

/*
 * @brief 单链表排序函数
 * */
ret_e slist_sort(slist_s *thiz,  slist_data_compare_func cmp,  slist_order_e order)
{
	ret_e ret = RET_OK;
	slist_node_s *iter = NULL;
	slist_s *t_list;

	return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

	/* 创建一个临时链表*/
	t_list = slist_create(thiz->data_destroy, thiz->data_destroy_ctx);
	if(t_list == NULL)
	{
		ret = RET_OUT_OF_MEM;
		return ret;
	}

	/*将链表中的元素逐个按续插入到临时链表中*/
	iter = thiz->first;
	while(iter != NULL)
	{
		ret = slist_insert_in_order(t_list, cmp, iter->data, order);
		if(ret != RET_OK)
		{
			break;
		}
		iter = iter->next;
	}

	if(ret != RET_OK)
	{
		return ret;
	}

	thiz->first = t_list->first;
	SAFE_FREE(t_list);

	return ret;
}
/*
 * @brief　释放链表
 * */
void slist_destroy(slist_s *thiz)
{
	slist_node_s *iter = NULL;
	slist_node_s *next = NULL;

	return_if_fail(thiz != NULL);

	iter = thiz->first;
	while(iter != NULL)
	{
		next = iter->next;
		slist_destroy_node(thiz, iter);
		iter = next;
	}

	thiz->first = NULL;

	SAFE_FREE(thiz);
}

