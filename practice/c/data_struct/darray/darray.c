#include <stdlib.h>
#include <stdio.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "darray.h"

static ret_e darray_expand(darray_s *thiz, size_t need)
{
	return_val_if_fail(thiz != NULL,  RET_INVALID_PARAMS);

	if((thiz->size + need) > thiz->alloc_size)
	{
		size_t alloc_size = thiz->alloc_size + (thiz->alloc_size>>1) +MIN_PRE_ALLOCATE_NR;

		void **data = (void **)realloc(thiz->data, sizeof(void *) * alloc_size);

		if(data != NULL)
		{
			thiz->data = data;
			thiz->alloc_size = alloc_size;
		}
	}

	return((thiz->size + need) <= thiz->alloc_size) ?RET_OK:RET_FAIL;
}
static ret_e darray_shrink(darray_s *thiz)
{
	return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

	if((thiz->size < (thiz->alloc_size>>1))
		&& (thiz->alloc_size > MIN_PRE_ALLOCATE_NR))
	{
		size_t alloc_size = thiz->size + (thiz->size >> 1);

		void **data =(void **)realloc(thiz->data, sizeof(void *)*alloc_size);
		if(data != NULL)
		{
			thiz->data = data;
			thiz->alloc_size = alloc_size;
		}
	}

	return RET_OK;
}
static void darray_destroy_data(darray_s *thiz, void *data)
{
	if(thiz->data_destroy != NULL)
	{
		thiz->data_destroy(thiz->data_destroy_ctx, data);
	}

	return;
}
darray_s *darray_create(data_destroy_func data_destroy, void *ctx)
{
	darray_s *thiz= (darray_s *)malloc(sizeof(darray_s));

	if(thiz != NULL)
	{
		thiz->data = NULL;
		thiz->size = 0;
		thiz->alloc_size = 0;
		thiz->data_destroy = data_destroy;
		thiz->data_destroy_ctx = ctx;
	}

	return thiz;
}

ret_e darray_insert(darray_s *thiz, size_t index, void *data)
{
	ret_e ret = RET_OK;
	size_t cursor = index;
	return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

	cursor = cursor < thiz->size ? cursor :thiz->size;

	if(darray_expand(thiz, 1) == RET_OK)
	{
		size_t i = 0;
		for(i = thiz->size; i > cursor; i--)
		{
			thiz->data[i] = thiz->data[i-1];
		}

		thiz->data[cursor] = data;
		thiz->size++;

		ret = RET_OK;
	}

	return ret;
}
ret_e darray_prepend(darray_s *thiz, void *data)
{
	return darray_insert(thiz, 0, data);
}
ret_e darray_append(darray_s *thiz, void *data)
{
	return darray_insert(thiz, -1, data);
}
ret_e darray_delete(darray_s *thiz, size_t index)
{
	size_t i = 0;

	return_val_if_fail(thiz != NULL && thiz->size > index, RET_INVALID_PARAMS);

	darray_destroy_data(thiz, thiz->data[index]);
	for(i = index; (i+1) < thiz->size; i++)
	{
		thiz->data[i] = thiz->data[i+1];
	}
	thiz->size--;

	darray_shrink(thiz);

	return RET_OK;
}
ret_e darray_set_by_index(darray_s *thiz, size_t index, void *data)
{
	return_val_if_fail(thiz != NULL && index < thiz->size, RET_INVALID_PARAMS);

	thiz->data[index] = data;

	return RET_OK;
}
ret_e darray_get_by_index(darray_s *thiz, size_t index, void **data)
{
	return_val_if_fail(thiz != NULL && data != NULL && index < thiz->size, RET_INVALID_PARAMS);

	*data = thiz->data[index];

	return RET_OK;
}
size_t darray_length(darray_s *thiz)
{
	return_val_if_fail(thiz != NULL, 0);

	return thiz->size;
}
int darray_find(darray_s *thiz, data_compare_func cmp, void *ctx)
{
	size_t i = 0;

	return_val_if_fail(thiz != NULL && cmp != NULL, -1);

	for(i = 0; i < thiz->size; i++)
	{
		if(cmp(ctx, thiz->data[i]) == 0)
		{
			break;
		}
	}

	return i;
}
ret_e darray_foreach(darray_s *thiz, data_visit_func visit, void *ctx)
{
	size_t i = 0;

	ret_e ret = RET_OK;
	return_val_if_fail(thiz != NULL && visit != NULL, RET_INVALID_PARAMS);

	for(i = 0; i < thiz->size; i++)
	{
		ret = visit(ctx, thiz->data[i]);
	}

	return ret;
}
void darray_destroy(darray_s *thiz)
{
	size_t i = 0;

	if(thiz != NULL)
	{
		for(i = 0; i < thiz->size; i++)
		{
			darray_destroy_data(thiz, thiz->data[i]);
		}
		SAFE_FREE(thiz->data);
		SAFE_FREE(thiz);
	}
}
