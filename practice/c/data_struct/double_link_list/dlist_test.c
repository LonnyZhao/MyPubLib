/*************************************************************************
	> File Name: dlist_test.c
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月06日 星期二 13时17分21秒
 ************************************************************************/

#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "locker.h"
#include "rw_locker.h"
#include "dlist.h"
#include "locker_pthread.h"
static int cmp_int(void* ctx, void* data)
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

static void test_int_dlist(void)
{
	int i = 0;
	int n = 100;
	int data = 0;
	dlist_s* dlist = dlist_create(NULL, NULL, NULL);

	for(i = 0; i < n; i++)
	{
		assert(dlist_append(dlist, (void*)i) == RET_OK);
		assert(dlist_length(dlist) == (i + 1));
		assert(dlist_get_by_index(dlist, i, (void**)&data) == RET_OK);
		assert(data == i);
		assert(dlist_set_by_index(dlist, i, (void*)(2*i)) == RET_OK);
		assert(dlist_get_by_index(dlist, i, (void**)&data) == RET_OK);
		assert(data == 2*i);
		assert(dlist_set_by_index(dlist, i, (void*)i) == RET_OK);
		assert(dlist_find(dlist, cmp_int, (void*)i) == i);
	}

	for(i = 0; i < n; i++)
	{
		assert(dlist_get_by_index(dlist, 0, (void**)&data) == RET_OK);
		assert(data == (i));
		assert(dlist_length(dlist) == (n-i));
		assert(dlist_delete(dlist, 0) == RET_OK);
		assert(dlist_length(dlist) == (n-i-1));
		if((i + 1) < n)
		{
			assert(dlist_get_by_index(dlist, 0, (void**)&data) == RET_OK);
			assert((int)data == (i+1));
		}
	}
	
	assert(dlist_length(dlist) == 0);

	for(i = 0; i < n; i++)
	{
		assert(dlist_prepend(dlist, (void*)i) == RET_OK);
		assert(dlist_length(dlist) == (i + 1));
		assert(dlist_get_by_index(dlist, 0, (void**)&data) == RET_OK);
		assert(data == i);
		assert(dlist_set_by_index(dlist, 0, (void*)(2*i)) == RET_OK);
		assert(dlist_get_by_index(dlist, 0, (void**)&data) == RET_OK);
		assert(data == 2*i);
		assert(dlist_set_by_index(dlist, 0, (void*)i) == RET_OK);
	}

	i = n - 1;
	assert(dlist_foreach(dlist, check_and_dec_int, &i) == RET_OK);

	dlist_destroy(dlist);

	return;
}

static void test_invalid_params(void)
{
	printf("===========Warning is normal begin==============\n");
	assert(dlist_length(NULL) == 0);
	assert(dlist_prepend(NULL, 0) == RET_INVALID_PARAMS);
	assert(dlist_append(NULL, 0) == RET_INVALID_PARAMS);
	assert(dlist_delete(NULL, 0) == RET_INVALID_PARAMS);
	assert(dlist_insert(NULL, 0, 0) == RET_INVALID_PARAMS);
	assert(dlist_set_by_index(NULL, 0, 0) == RET_INVALID_PARAMS);
	assert(dlist_get_by_index(NULL, 0, NULL) == RET_INVALID_PARAMS);
	assert(dlist_find(NULL, NULL, NULL) == RET_INVALID_PARAMS);
	assert(dlist_foreach(NULL, NULL, NULL) == RET_INVALID_PARAMS);
	printf("===========Warning is normal end==============\n");

	return;
}
static void single_thread_test(void)
{
    test_int_dlist();
    test_invalid_params();

    return;

}

int main(int argc, char * argv[])
{
    single_thread_test();
    //multi_thread_test();

    return 0;
}
