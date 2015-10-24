/*************************************************************************
	> File Name: hashtabale.c
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月22日 星期四 07时37分33秒
 ************************************************************************/

#include  <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "dlist.h"
#include "hashtable.h"
/**
 * @brief 创建散列表
 **/
hash_table_s * hash_table_create(data_destroy_func data_destroy, void *ctx, data_hash_func hash, int slot_nr)
{
	hash_table_s  *thiz = NULL;

	return_val_if_fail(hash != NULL && slot_nr > 1, NULL);

	thiz = (hash_table_s*)malloc(sizeof(hash_table_s));

	if(thiz == NULL)
	{
		return NULL;
	}

	thiz->hash = hash;
	thiz->slot_nr = slot_nr;
	thiz->data_destroy_ctx = ctx;
	thiz->data_destroy = data_destroy;

	thiz->slots = (dlist_s **)calloc(sizeof(dlist_s *)*slot_nr, 1);
	if(thiz->slots == NULL)
	{
		free(thiz);
		thiz = NULL;
	}

	return thiz;
}
/**
 * @brief　计算hash表长度
 * */
size_t hash_table_length(hash_table_s *thiz)
{
	size_t i = 0;
	size_t nr = 0;

	return_val_if_fail(thiz != NULL, 0);

	for(i = 0; i < thiz->slot_nr; i++)
	{
		if(thiz->slots[i] != NULL)
		{
			nr += dlist_length(thiz->slots[i]);
		}
	}

	return nr;
}

/**
 *@brief HashTable插入
 * */
ret_e hash_table_insert(hash_table_s *thiz, void*data)
{
	size_t index = 0;

	return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

	index = thiz->hash(data)%thiz->slot_nr;

	if(thiz->slots[index] == NULL)
	{
		thiz->slots[index] = dlist_create(thiz->data_destroy, thiz->data_destroy_ctx);
	}

	return dlist_prepend(thiz->slots[index], data);

}
/**
 * @brief Hash表删除成员
 * */
ret_e hash_table_delete(hash_table_s *thiz, data_compare_func cmp, void *data)
{
	int index = 0;
	dlist_s *dlist = NULL;

	return_val_if_fail(thiz != NULL && cmp != NULL, RET_INVALID_PARAMS);

	index = thiz->hash(data)%thiz->slot_nr;
	dlist = thiz->slots[index];

	if(dlist != NULL)
	{
		index = dlist_find(dlist, cmp, data);

		return dlist_delete(dlist, index);
	}

	return RET_FAIL;
}
ret_e hash_table_find(hash_table_s *thiz, data_compare_func cmp, void *data, void **ret_data)
{
	int index = 0;
	dlist_s *dlist = NULL;

	return_val_if_fail(thiz != NULL && cmp != NULL && ret_data != NULL, RET_INVALID_PARAMS);

	index =thiz->hash(data)%thiz->slot_nr;
	dlist = thiz->slots[index];
	if(dlist != NULL)
	{
		index = dlist_find(dlist, cmp, data);

		return dlist_get_by_index(dlist, index, ret_data);
	}

	return RET_FAIL;
}
ret_e hash_table_forech(hash_table_s *thiz, data_visit_func visit, void *ctx)
{
	size_t i = 0;

	return_val_if_fail(thiz != NULL && visit != NULL, RET_INVALID_PARAMS);

	for(i = 0; i < thiz->slot_nr; i++)
	{
		if(thiz->slots[i] != NULL)
		{
			dlist_foreach(thiz->slots[i], visit, ctx);
		}
	}

	return RET_OK;
}

void hash_table_destroy(hash_table_s *thiz)
{
	size_t i = 0;
	if(thiz != NULL)
	{
		for(i = 0; i < thiz->slot_nr; i++)
		{
			if(thiz->slots[i] != NULL)
			{
				dlist_destroy(thiz->slots[i]);
				thiz->slots[i] = NULL;
			}
		}

		free(thiz->slots);
		free(thiz);
	}
}
