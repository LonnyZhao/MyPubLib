/*
 * linear_container_darray.c
 *
 *  Created on: 2015年11月1日
 *      Author: Lonny
 */
#include <stdlib.h>
#include <stdio.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "darray.h"
#include "linear_container.h"

/**
 * 私有数据，不对外体现
 * */
typedef struct priv_info_t
{
	darray_s *darray;
}priv_info_s;

static ret_e linear_container_darray_insert(linear_container_s *thiz, size_t index, void *data)
{
	priv_info_s *priv =(priv_info_s *)thiz->priv;

	return darray_insert(priv->darray, index, data);
}

static ret_e linear_container_darray_prepend(linear_container_s *thiz, void *data)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return darray_insert(priv->darray, data);
}

static ret_e linear_container_darray_append(linear_container_s *thiz, void *data)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return darray_append(priv->darray, data);
}
static ret_e linear_container_darray_delete(linear_container_s *thiz, size_t index)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return darray_delete(priv->darray, index);
}
static ret_e linear_container_darray_get_by_index(linear_container_s *thiz, size_t index, void **data)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return darray_get_by_index(priv->darray, index, data);
}

static ret_e linear_container_darray_set_by_index(linear_container_s *thiz, size_t index,void *data)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return darray_set_by_index(priv->darray, index, data);
}

static size_t linear_container_darray_length(linear_container_s *thiz)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return darray_length(priv->darray);
}
static int linear_container_darray_find(linear_container_s *thiz, data_compare_func cmp, void *ctx)
{
	priv_info_s *priv = (priv_info_s*)thiz->priv;

	return darray_find(priv->darray, cmp, ctx);
}
static ret_e linear_container_darray_foreach(linear_container_s *thiz, data_visit_func visit, void *ctx)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return darray_foreach(priv->darray, visit, ctx);
}

static void linear_container_darray_destroy(linear_container_s *thiz)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	darray_destroy(priv->darray);
	free(thiz);

	return;
}

linear_container_s *linear_container_darray_create(data_destroy_func data_destroy, void *ctx)
{
	linear_container_s *thiz = (linear_container_s *)malloc(sizeof(linear_container_s) + sizeof(priv_info_s));

	if(thiz != NULL)
	{
		priv_info_s *priv = (priv_info_s)thiz->priv;
		priv->darray = darray_create(data_destroy, ctx);

		thiz->insert        =  linear_container_darray_insert;
		thiz->prepend       =  linear_container_darray_prepend;
		thiz->append        =  linear_container_darray_append;
		thiz->del           =  linear_container_darray_delete;
		thiz->get_by_index  =  linear_container_darray_get_by_index;
		thiz->set_by_index  =  linear_container_darray_set_by_index;
		thiz->length        =  linear_container_darray_length;
		thiz->find          =  linear_container_darray_find;
		thiz->foreach       =  linear_container_darray_foreach;
		thiz->destroy       =  linear_container_darray_destroy;
	}

	return thiz;
}



