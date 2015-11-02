/*
 * queue.c
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
#include "queue.h"
#include "linear_container.h"

queue_s queue_create(linear_container_s *container)
{
	queue_s *thiz = NULL;

	return_val_if_fail(container != NULL, NULL);

	thiz = (queue_s *)malloc(sizeof(queue_s));

	if(thiz != NULL)
	{
		thiz->linear_container = container;
	}

	return thiz;
}

ret_e queue_head(queue_s *thiz, void **data)
{
	return_val_if_fail(thiz != NULL && data != NULL, RET_INVALID_PARAMS);

	return linear_container_get_by_index(thiz->linear_container, 0, data);
}

ret_e queue_push(queue_s *thiz, void *data)
{
	return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

	return linear_container_append(thiz->linear_container, data);
}

ret_e queue_pop(queue_s *thiz)
{
	return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

	return linear_container_delete(thiz->linear_container, 0);
}

size_t queu_length(queue_s *thiz)
{
	return_val_if_fail(thiz != NULL, 0);

	return linear_container_length(thiz->linear_container);
}

ret_e queue_foreach(queue_s *thiz, data_visit_func visit, void *ctx)
{
	return_val_if_fail(thiz != NULL && visit != NULL, RET_INVALID_PARAMS);

	return linear_container_foreach(thiz->linear_container, visit, ctx);
}

void queue_destroy(queue_s *thiz)
{
	if(thiz != NULL)
	{
		linear_container_destroy(thiz->linear_container);
		thiz->linear_container = NULL;
		free(thiz);
	}
}