/*************************************************************************
	> File Name: hashtable.h
	> Brief:
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月22日 星期四 07时39分45秒
 ************************************************************************/

#ifndef _HASHTABLE_H
#include "typedef.h"
typedef struct hash_table_t
{
	data_hash_func hash;
	dlist_s **slots;
	size_t slot_nr;
	data_destroy_func data_destroy;
	void* data_destroy_ctx;
}hash_table_s;

hash_table_s * hash_table_create(data_destroy_func data_destroy, void *ctx, data_hash_func hash, int slot_nr);
size_t hash_table_length(hash_table_s *thiz);
ret_e hash_table_insert(hash_table_s *thiz, void*data);
ret_e hash_table_delete(hash_table_s *thiz, data_compare_func cmp, void *data);
ret_e hash_table_find(hash_table_s *thiz, data_compare_func cmp, void *data, void **ret_data);
ret_e hash_table_forech(hash_table_s *thiz, data_visit_func visit, void *ctx);
void hash_table_destroy(hash_table_s *thiz);
#endif
