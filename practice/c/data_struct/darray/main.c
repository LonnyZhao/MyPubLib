/*
 * main.c
 *
 *  Created on: 2015年10月25日
 *      Author: Lonny
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "darray.h"
static int int_cmp(void* ctx, void* data)
{
	return (int)data - (int)ctx;
}

static ret_e print_int(void* ctx, void* data)
{
	printf("%d ", (int)data);

	return RET_OK;
}

static ret_e check_and_dec_int(void* ctx, void* data)
{
	int* expected =(int*)ctx;
	assert(*expected == (int)data);

	(*expected)--;

	return RET_OK;
}

static void test_int_darray(void)
{
	int i = 0;
	int n = 100;
	int data = 0;
	darray_s *darray = darray_create(NULL, NULL);

	for(i = 0; i < n; i++)
	{
		assert(darray_append(darray, (void*)i) == RET_OK);
		assert(darray_length(darray) == (i + 1));
		assert(darray_get_by_index(darray, i, (void**)&data) == RET_OK);
		assert(data == i);
		assert(darray_set_by_index(darray, i, (void*)(2*i)) == RET_OK);
		assert(darray_get_by_index(darray, i, (void**)&data) == RET_OK);
		assert(data == 2*i);
		assert(darray_set_by_index(darray, i, (void*)i) == RET_OK);
		assert(darray_find(darray, int_cmp, (void*)i) == i);
	}

	for(i = 0; i < n; i++)
	{
		assert(darray_get_by_index(darray, 0, (void**)&data) == RET_OK);
		assert(data == (i));
		assert(darray_length(darray) == (n-i));
		assert(darray_delete(darray, 0) == RET_OK);
		assert(darray_length(darray) == (n-i-1));
		if((i + 1) < n)
		{
			assert(darray_get_by_index(darray, 0, (void**)&data) == RET_OK);
			assert((int)data == (i+1));
		}
	}

	assert(darray_length(darray) == 0);

	for(i = 0; i < n; i++)
	{
		assert(darray_prepend(darray, (void*)i) == RET_OK);
		assert(darray_length(darray) == (i + 1));
		assert(darray_get_by_index(darray, 0, (void**)&data) == RET_OK);
		assert(data == i);
		assert(darray_set_by_index(darray, 0, (void*)(2*i)) == RET_OK);
		assert(darray_get_by_index(darray, 0, (void**)&data) == RET_OK);
		assert(data == 2*i);
		assert(darray_set_by_index(darray, 0, (void*)i) == RET_OK);
	}

	i = n - 1;
	assert(darray_foreach(darray, check_and_dec_int, &i) == RET_OK);

	darray_destroy(darray);

	return;
}

static void test_invalid_params(void)
{
	printf("===========Warning is normal begin==============\n");
	assert(darray_length(NULL) == 0);
	assert(darray_prepend(NULL, 0) == RET_INVALID_PARAMS);
	assert(darray_append(NULL, 0) == RET_INVALID_PARAMS);
	assert(darray_delete(NULL, 0) == RET_INVALID_PARAMS);
	assert(darray_insert(NULL, 0, 0) == RET_INVALID_PARAMS);
	assert(darray_set_by_index(NULL, 0, 0) == RET_INVALID_PARAMS);
	assert(darray_get_by_index(NULL, 0, NULL) == RET_INVALID_PARAMS);
	assert(darray_find(NULL, NULL, NULL) < 0);
	assert(darray_foreach(NULL, NULL, NULL) == RET_INVALID_PARAMS);
	printf("===========Warning is normal end==============\n");

	return;
}

static void single_thread_test(void)
{
	test_int_darray();
	test_invalid_params();

	return;
}

int main(int argc, char *argv[])
{
	single_thread_test();

	return 0;
}
