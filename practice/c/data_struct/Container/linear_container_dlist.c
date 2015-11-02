/*
 * linear_container_dlist.c
 *
 *  Created on: 2015年11月1日
 *      Author: Lonny
 */
#include <stdlib.h>
#include <stdio.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"

#include "dlist.h"
#include "linear_container.h"

typedef struct priv_info_t
{
	dlist_s *dlist;
}priv_info_s;

static ret_e linear_container_dlist_insert(linear_container_s *thiz, size_t index, void *data)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return dlist_insert(priv->dlist, index, data);
}

static ret_e linear_container_dlist_prepend(linear_container_s *thiz, void *data)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return dlist_prepend(priv->dlist, data);
}

static ret_e linear_container_dlist_append(linear_container_s *thiz, void *data)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return dlist_append(priv->dlist, data);
}

static ret_e linear_container_dlist_delete(linear_container_s *thiz, size_t index)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return dlist_delete(priv->dlist, index);
}

static ret_e linear_container_dlist_get_by_index(linear_container_s *thiz, size_t index, void **data)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return dlist_get_by_index(priv->dlist, index, data);
}

static ret_e linear_container_dlist_set_by_index(linear_container_s *thiz, size_t index, void *data)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return dlist_get_by_index(priv->dlist, index, data);
}

static ret_e linear_container_dlist_set_by_index(linear_container_s *thiz, size_t index, void *data)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return dlist_set_by_index(priv->dlist, index, data);
}

static size_t linear_container_dlist_length(linear_container_s *thiz)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return dlist_length(priv->dlist);
}

static int linear_container_dlist_find(linear_container_s *thiz, data_compare_func cmp, void *ctx)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return dlist_find(priv->dlist, cmp, ctx);
}

static ret_e linear_container_dlist_foreach(linear_container_s *thiz, data_visit_func visit, void *ctx)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	return dlist_foreach(priv->dlist, visit, ctx);
}

static void linear_container_dlist_destroy(linear_container_s *thiz)
{
	priv_info_s *priv = (priv_info_s *)thiz->priv;

	dlist_destroy(priv->dlist);

	free(thiz);

	return;
}


linear_container_s* linear_container_dlist_create(data_destroy_func data_destroy, void* ctx)
{
	linear_container_s* thiz = (linear_container_s*)malloc(sizeof(linear_container_s) + sizeof(priv_info_s));

	if(thiz != NULL)
	{
		priv_info_s* priv = (priv_info_s*)thiz->priv;
		priv->dlist = dlist_create(data_destroy, ctx);

		thiz->insert              =  linear_container_dlist_insert;
		thiz->prepend         =  linear_container_dlist_prepend;
		thiz->append          =  linear_container_dlist_append;
		thiz->del                  =  linear_container_dlist_delete;
		thiz->get_by_index  =  linear_container_dlist_get_by_index;
		thiz->set_by_index  =  linear_container_dlist_set_by_index;
		thiz->length            =  linear_container_dlist_length;
		thiz->find                =  linear_container_dlist_find;
		thiz->foreach          =  linear_container_dlist_foreach;
		thiz->destroy           =  linear_container_dlist_destroy;

		if(priv->dlist == NULL)
		{
			free(thiz);
			thiz = NULL;
		}
	}

	return thiz;
}
