/*
 * s_list.h
 *
 *  Created on: 2016年1月2日
 *      Author: Lonny
 */

#ifndef S_LIST_H_
#define S_LIST_H_
#ifdef __cplusplus
extern "C" {
#endif

/*
 *使用函数类型定义
 * */
typedef  void (*slist_data_destroy_func)(void *ctx, void *data);
typedef  int (*slist_data_compare_func)(void *ctx, void *data);
typedef ret_e (*slist_data_visit_func)(void *ctx, void *data);

/**
 *单链表节点定义
 * */
typedef struct slist_node_t{
	struct slist_node_t *next;
	void *data;
}slist_node_s;

/**
 *单链表定义
 * */
typedef  struct slist_t{
	slist_data_destroy_func data_destroy;
	slist_node_s *first;
	void *data_destroy_ctx;
}slist_s;

/*
 * 排序顺序定义
 * */
typedef enum slist_order_t{
	SLIST_SORT_ASC_ORDER,	/*　进行升序排序*/
	SLIST_SORT_DESC_ORDER,	/*　进行降序排序*/
	SLIST_SORT_MAX
}slist_order_e;

/*
 * 链表功能函数
 * */

/*
 * @brief 创建单链表函数
 *
 * ＠param[in] data_destroy 链表回收节点内容函数
 * ＠param[in] ctx                链表描述上下文
 *
 * @return  链表指针
 * */
slist_s *slist_create(slist_data_destroy_func data_destroy, void *ctx);

/*
 * @brief 单链表插入函数
 *
 *＠param[in]  thiz 链表指针
 *＠param[in]  index 插入位置，从０开始，－１表示在尾部插入
 *＠param[in]  data 插入的数据
 * */
ret_e slist_insert(slist_s *thiz, size_t index, void *data);

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
ret_e slist_insert_in_order(slist_s *thiz, slist_data_compare_func cmp,void *data,  slist_order_e order);

/*
 * @brief 在链表头部插入节点
 * */
ret_e slist_prepend(slist_s *thiz, void *data);

/*
 * @brief 在链表尾部插入节点
 * */
ret_e slist_append(slist_s *thiz, void *data);
/*
 * @brief 删除链表指定index元素
 *
 * ＠param[in] thiz　链表指针
 * @param[in] index 删除链表所在索引
 * */
ret_e slist_delete(slist_s *thiz, size_t index);
/*
 * @brief 单链表查找函数
 *
 * ＠param[in] thiz 链表指针
 * @param[in] cmp 比较函数
 * ＠param[in] ctx   比较上下文
 *
 * @return 查找到的节点所在的索引位置，若未查找到则返回－１
 * */
int slist_find(slist_s*thiz, slist_data_compare_func cmp, void *ctx);

/*
 *@brief　通过index获取链表数据
 *
 *＠param[in] thiz    链表指针
 *＠param[in] index 获取的索引位置
 *＠param[in] data  获取到数据时的data域内容
 *
 *＠return 是否获取成功
 * */
ret_e slist_get_by_index(slist_s *thiz, size_t index, void **data);

/*
 * ＠brief　通过index设置链表数据
 *
 *＠param[in] thiz 链表指针
 *＠param[in] index 设置的索引位置
 *＠param[in] data 设置的数据内容
 * */
ret_e slist_set_by_index(slist_s *thiz, size_t index, void *data);

/*
 *@brief foreach实现函数
 *
 *@param[in] thiz 单链表指针
 *@param[in] visit 轮询执行函数
 *@param[in] ctx 执行上下文
 * */
ret_e slist_foreach(slist_s *thiz, slist_data_visit_func visit, void *ctx);
/**
 * @brief 获取链表长度
 *
 * @param[in] thiz 链表指针
 *
 *@return 链表长度
 * */
size_t slist_length(slist_s *thiz);

/*
 * @brief 单链表排序函数
 * */
ret_e slist_sort(slist_s *thiz, slist_data_compare_func cmp,  slist_order_e order);

/*
 * @brief　释放链表
 * */
void slist_destroy(slist_s *thiz);
#ifdef __cplusplus
}
#endif
#endif /* S_LIST_H_ */
