/*************************************************************************
	> File Name: dlist.h
	> Brief:  双向链表 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月06日 星期二 05时19分46秒
 ************************************************************************/

#ifndef _DLIST_H
#define _DLIST_H
#ifdef __cplusplus
extern "C" {
#endif

typedef int (*dlist_data_compare_func)(void *ctx, void *data);
typedef ret_e (*dlist_data_visit_func)(void *ctx, void *data);
typedef void (*dlist_data_destroy_func)(void *ctx, void *data);
/**
 * 双向链表节点定义
 *
**/
typedef struct dlist_node_t
{
    struct dlist_node_t *prev; /**< 前一个节点的指针*/
    struct dlist_node_t *next; /**< 后一个节点的指针*/
    void *data;                /**< 节点中存储的数据*/
}dlist_node_s;

/**
 * 双向链表定义
* */
typedef struct dlist_t
{
    rw_locker_s *rw_locker;
    dlist_node_s *first;
    dlist_data_destroy_func data_destroy;
    void *data_destroy_ctx;
}dlist_s;


/**
 * @brief 创建双向链表
 *
* */
dlist_s *dlist_create(dlist_data_destroy_func data_destroy, void *ctx, rw_locker_s *rw_locker);
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
ret_e dlist_insert(dlist_s *thiz, size_t index, void *data);

/**
 * @breif 在链表头部插入节点
* */
ret_e dlist_prepend(dlist_s *thiz, void *data);

/**
 * @brief 在链表尾部插入节点
* */
ret_e dlist_append(dlist_s *thiz, void *data);

/**
 * @brief 删除节点
* */
ret_e dlist_delete(dlist_s *thiz, size_t index);


/**
 * @brief 通过index获取节点内容，注意只是获取的指针，不是获取的拷贝信息
* */
ret_e dlist_get_by_index(dlist_s *thiz, size_t index, void **data);

/**
 * @brief 通过index设置节点内容
 *
 * @param[in]  thiz 双链表指针
 * @param[in]  index 设置位置的索引
 * @param[in]  data 设置位置的数据
* */
ret_e dlist_set_by_index(dlist_s *thiz, size_t index, void *data);

/**
 * @brief 获取双向链表的长度，不加锁进行获取
* */
size_t dlist_length_nolock(dlist_s *thiz);


/**
 * @brief 通过加锁获取双向链表的长度
* */
size_t dlist_length(dlist_s *thiz);
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
ret_e dlist_foreach(dlist_s *thiz, dlist_data_visit_func visit, void *ctx);
/**
 * @brief 通过cmp回调函数判断链表中是否有数据
 *
 * @param[in]  thiz  双向链表指针
 * @param[in]  cmp   比较函数指针
 * @param[in]  ctx   比较内容
* */
int dlist_find(dlist_s *thiz, dlist_data_compare_func cmp,void *ctx);
/**
 * @brief 释放双向链表
* */
void dlist_destroy(dlist_s *thiz);
#ifdef __cplusplus
}
#endif 
#endif