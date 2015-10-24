/*************************************************************************
	> File Name: dlist.c
	> Brief: 简单双向链表程序 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月06日 星期二 06时55分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "dlist.h"
/**
 * @brief 内部使用函数，用于释放数据内存
 *
 * @param[in] thiz  双向链表指针
 * @param[in] data  需要释放的数据
 *
 * @return void
* */
static void dlist_destroy_data(dlist_s *thiz, void *data)
{
    if(thiz->data_destroy != NULL)
    {
        thiz->data_destroy(thiz->data_destroy_ctx, data);
    }

    return;
}

/**
 * @brief 内部使用函数，用于创建节点
 *
 * @param[in]   thiz  双向链表指针
 * @param[in]   data  创建节点内容的指针
 *
 * @return 创建节点的指针
* */
static dlist_node_s * dlist_create_node(dlist_s *thiz, void *data)
{
    dlist_node_s *node = (dlist_node_s *)malloc(sizeof(dlist_node_s));

    if(node != NULL)
    {
        node->prev = NULL;
        node->next = NULL;
        node->data = data;
    }

    return node;
}

/**
 * @brief 内部使用函数，用于释放节点
 *
 * @param[in]  thiz  双链表指针
 * @param[in]  node  释放的节点指针
* */
static void dlist_destroy_node(dlist_s *thiz, dlist_node_s *node)
{
    if(node != NULL)
    {
        node->next = NULL;
        node->prev = NULL;
        dlist_destroy_data(thiz, node->data);
        SAFE_FREE(node);
    }

    return;
}

/**
 * @brief 创建双向链表
 *
* */
dlist_s *dlist_create(dlist_data_destroy_func data_destroy, void *ctx)
{
    dlist_s *thiz = malloc(sizeof(dlist_s));

    if(thiz != NULL)
    {
        thiz->first = NULL;
        thiz->data_destroy = data_destroy;
        thiz->data_destroy_ctx = ctx;
    }

    return thiz;
}
/**
 * @brief 内部使用函数用于获取节点
* */
static dlist_node_s *dlist_get_node(dlist_s *thiz, size_t index, int fail_return_last)
{
    dlist_node_s *iter = NULL;
    size_t t_index = index;
    return_val_if_fail(thiz != NULL, NULL);

    iter = thiz->first;

    while(iter != NULL && iter->next != NULL && t_index > 0)
    {
        iter = iter->next;
        t_index--;
    }

    if(!fail_return_last)
    {
        iter = t_index > 0 ? NULL : iter;
    }
    
    return iter;
}
/**
 * @brief 插入节点函数
 * 
 * @param[in] thiz  双链表指针
 * @param[in] index 插入的位置，从0开始，-1表示在尾部进行插入
 * @param[in] data  插入节点的数据
 *
 * @return RET_OK  插入成功
 * @return 其他    插入失败
* */
ret_e dlist_insert(dlist_s *thiz, size_t index, void *data)
{
    ret_e ret = RET_OK;

    dlist_node_s *node = NULL;
    dlist_node_s *cursor = NULL;

    return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

    do
    {
        /* 创建一个新的节点*/
        if((node = dlist_create_node(thiz, data)) == NULL)
        {
            ret = RET_OUT_OF_MEM;
            break;
        }
        /* 查看是否为空链表*/
        if(thiz->first == NULL)
        {
            thiz->first = node;
            break;
        }
        
        /* 获取插入位置*/
        cursor = dlist_get_node(thiz, index, TRUE);
        
        if(index < dlist_length(thiz))
        {
            /* 处理在头部和中间插入的情况*/
            node->next = cursor;
            if(cursor->prev != NULL)
            {
                cursor->prev->next = node;
            }
            
            cursor->prev = node;
            
            if(thiz->first == cursor)
            {
                thiz->first = node;
            }
        }
        else
        {
            /* 处理在尾部插入的情况*/
            cursor->next = node;
            node->prev = cursor;
        }

    }while(0);

    return ret;
}

/**
 * @breif 在链表头部插入节点
* */
ret_e dlist_prepend(dlist_s *thiz, void *data)
{
    return dlist_insert(thiz, 0, data);
}

/**
 * @brief 在链表尾部插入节点
* */
ret_e dlist_append(dlist_s *thiz, void *data)
{
    return dlist_insert(thiz, -1, data);
}

/**
 * @brief 删除节点
* */
ret_e dlist_delete(dlist_s *thiz, size_t index)
{
    ret_e ret = RET_OK;

    dlist_node_s *cursor = NULL;

    return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

    cursor = dlist_get_node(thiz, index, 0);

    do
    {
        if(cursor == NULL)
        {
            ret = RET_INVALID_PARAMS;
            break;
        }

        if(cursor != NULL)
        {
            if(cursor == thiz->first)
            {
                /* 删除头节点*/
                thiz->first = cursor->next;
            }

            if(cursor->next != NULL)
            {
                cursor->next->prev = cursor->prev;
            }

            if(cursor->prev != NULL)
            {
                cursor->prev->next = cursor->next;
            }

            dlist_destroy_node(thiz, cursor);
        }
    }while(0);

    return ret;
}

/**
 * @brief 通过index获取节点内容，注意只是获取的指针，不是获取的拷贝信息
* */
ret_e dlist_get_by_index(dlist_s *thiz, size_t index, void **data)
{
    dlist_node_s *cursor = NULL;

    return_val_if_fail(thiz != NULL && data != NULL, RET_INVALID_PARAMS);

    cursor = dlist_get_node(thiz, index, 0);

    if(cursor != NULL)
    {
        *data = cursor->data;
    }

    return cursor != NULL ? RET_OK : RET_INVALID_PARAMS;
}

/**
 * @brief 通过index设置节点内容
 *
 * @param[in]  thiz 双链表指针
 * @param[in]  index 设置位置的索引
 * @param[in]  data 设置位置的数据
* */
ret_e dlist_set_by_index(dlist_s *thiz, size_t index, void *data)
{
    dlist_node_s *cursor = NULL;

    return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

    cursor = dlist_get_node(thiz, index, 0);

    if(cursor != NULL)
    {
        /* 先释放原节点内容*/
        dlist_destroy_data(thiz, cursor->data);

        /* 改变本节点指向内容*/
        cursor->data = data;
    }

    return cursor != NULL ? RET_OK : RET_INVALID_PARAMS;
}

/**
 * @brief 获取双向链表的长度
* */
size_t dlist_length(dlist_s *thiz)
{
    size_t length = 0;
    dlist_node_s *iter = NULL;

    iter = thiz->first;

    while(iter != NULL)
    {
        length++;
        iter = iter->next;
    }

    return length;
}

/**
* @brief foreach实现函数
*
* @param[in] thiz 双向链表的指针
* @param[in] visit 轮询执行函数
* @param[in] ctx   上下文
*
* @return RET_OK 执行成功
* @return 其他   执行失败
* */
ret_e dlist_foreach(dlist_s *thiz, dlist_data_visit_func visit, void *ctx)
{
    ret_e ret = RET_OK;
    dlist_node_s *iter = NULL;

    return_val_if_fail(thiz != NULL && visit != NULL, RET_INVALID_PARAMS);

    iter = thiz->first;

    while(iter != NULL && ret != RET_STOP)
    {
        ret = visit(ctx, iter->data);
        iter = iter->next;
    }

    return ret;
}

/**
 * @brief 通过cmp回调函数判断链表中是否有数据
 *
 * @param[in]  thiz  双向链表指针
 * @param[in]  cmp   比较函数指针
 * @param[in]  ctx   比较内容
* */
int dlist_find(dlist_s *thiz, dlist_data_compare_func cmp, void *ctx)
{
    int i = 0;
    dlist_node_s *iter = NULL;

    return_val_if_fail(thiz != NULL && cmp != NULL, RET_INVALID_PARAMS);

    iter = thiz->first;
    while(iter != NULL)
    {
        if(cmp(ctx, iter->data) == 0)
        {
            break;
        }

        i++;
        iter = iter->next;
    }

    return i;
}
/**
 * @brief 释放双向链表
* */
void dlist_destroy(dlist_s *thiz)
{
    dlist_node_s *iter = NULL;
    dlist_node_s *next = NULL;

    return_if_fail(thiz != NULL);

    iter = thiz->first;
    while(iter != NULL)
    {
        next = iter->next;
        dlist_destroy_node(thiz, iter);
        iter = next;
    }

    thiz->first = NULL;
    SAFE_FREE(thiz);

    return;
}
