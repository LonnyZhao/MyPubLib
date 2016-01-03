/*
 * slist_test.c
 *
 *  Created on: 2016年1月3日
 *      Author: Lonny
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"

#include "s_list.h"

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

static void test_int_slist()
{
	int i = 0;
	int n = 32*1024;
	int data = 0;

	slist_s *slist = slist_create(NULL, NULL);
	for(i = 0; i < n; i++)
	{
		assert((slist_append(slist, (void *)i)) == RET_OK);
		assert((slist_length(slist)) == (i+1));
		assert(slist_get_by_index(slist, i, (void**)&data) == RET_OK);
		assert(data == i);
		assert(slist_set_by_index(slist, i, (void*)(2*i)) == RET_OK);
		assert(slist_get_by_index(slist, i, (void**)&data) == RET_OK);
		assert(data == 2*i);
		assert(slist_set_by_index(slist, i, (void*)i) == RET_OK);
		assert(slist_find(slist, cmp_int, (void*)i) == i);
	}

	for(i = 0; i < n; i++)
	{
		assert(slist_get_by_index(slist, 0, (void**)&data) == RET_OK);
		assert(data == (i));
		assert(slist_length(slist) == (n-i));
		assert(slist_delete(slist, 0) == RET_OK);
		assert(slist_length(slist) == (n-i-1));
		if((i + 1) < n)
		{
			assert(slist_get_by_index(slist, 0, (void**)&data) == RET_OK);
			assert((int)data == (i+1));
		}
	}

	assert(slist_length(slist) == 0);

	for(i = 0; i < n; i++)
	{
		assert(slist_prepend(slist, (void*)i) == RET_OK);
		assert(slist_length(slist) == (i + 1));
		assert(slist_get_by_index(slist, 0, (void**)&data) == RET_OK);
		assert(data == i);
		assert(slist_set_by_index(slist, 0, (void*)(2*i)) == RET_OK);
		assert(slist_get_by_index(slist, 0, (void**)&data) == RET_OK);
		assert(data == 2*i);
		assert(slist_set_by_index(slist, 0, (void*)i) == RET_OK);
	}

	i = n - 1;
	assert(slist_foreach(slist, check_and_dec_int, &i) == RET_OK);

	slist_destroy(slist);

	return;
}
static void test_invalid_params(void)
{
	printf("===========Warning is normal begin==============\n");
	assert(slist_length(NULL) == 0);
	assert(slist_prepend(NULL, 0) == RET_INVALID_PARAMS);
	assert(slist_append(NULL, 0) == RET_INVALID_PARAMS);
	assert(slist_delete(NULL, 0) == RET_INVALID_PARAMS);
	assert(slist_insert(NULL, 0, 0) == RET_INVALID_PARAMS);
	assert(slist_set_by_index(NULL, 0, 0) == RET_INVALID_PARAMS);
	assert(slist_get_by_index(NULL, 0, NULL) == RET_INVALID_PARAMS);
	assert(slist_find(NULL, NULL, NULL) == RET_INVALID_PARAMS);
	assert(slist_foreach(NULL, NULL, NULL) == RET_INVALID_PARAMS);
	printf("===========Warning is normal end==============\n");

	return;
}

static void test_insert_asc(void)
{
	slist_s *slist = slist_create(NULL, NULL);
	printf("===========insert asc test begin==============\n");
	slist_insert_in_order(slist, cmp_int, (void *)1, SLIST_SORT_ASC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)0, SLIST_SORT_ASC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)9, SLIST_SORT_ASC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)3, SLIST_SORT_ASC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)5, SLIST_SORT_ASC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)19, SLIST_SORT_ASC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)99, SLIST_SORT_ASC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)22, SLIST_SORT_ASC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)88, SLIST_SORT_ASC_ORDER);
	slist_foreach(slist, print_int, NULL);
	printf("\n===========insert asc test end==============\n");
	slist_destroy(slist);
}

static void test_insert_desc(void)
{
	slist_s *slist = slist_create(NULL, NULL);
	printf("===========insert desc test begin==============\n");
	slist_insert_in_order(slist, cmp_int, (void *)1, SLIST_SORT_DESC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)0, SLIST_SORT_DESC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)9, SLIST_SORT_DESC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)3, SLIST_SORT_DESC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)5, SLIST_SORT_DESC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)19, SLIST_SORT_DESC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)99, SLIST_SORT_DESC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)22, SLIST_SORT_DESC_ORDER);
	slist_insert_in_order(slist, cmp_int, (void *)88, SLIST_SORT_DESC_ORDER);
	slist_foreach(slist, print_int, NULL);
	printf("\n===========insert desc test end==============\n");
}

static void test_slist_sort_asc(void)
{
	slist_s *slist = slist_create(NULL, NULL);

	printf("\n===========slist sort asc begin==============\n");
	slist_prepend(slist,(void *)1);
	slist_prepend(slist, (void *)0);
	slist_prepend(slist, (void *)9);
	slist_prepend(slist, (void *)3);
	slist_prepend(slist, (void *)5);
	slist_prepend(slist, (void *)19);
	slist_prepend(slist, (void *)99);
	slist_prepend(slist, (void *)22);
	slist_prepend(slist, (void *)88);

	slist_sort(slist, cmp_int, SLIST_SORT_ASC_ORDER);
	slist_foreach(slist, print_int, NULL);

	printf("\n===========slist sort asc end==============\n");
}
static void test_slist_sort_desc(void)
{
	slist_s *slist = slist_create(NULL, NULL);

	printf("===========slist sort desc begin==============\n");
	slist_prepend(slist,(void *)1);
	slist_prepend(slist, (void *)0);
	slist_prepend(slist, (void *)9);
	slist_prepend(slist, (void *)3);
	slist_prepend(slist, (void *)5);
	slist_prepend(slist, (void *)19);
	slist_prepend(slist, (void *)99);
	slist_prepend(slist, (void *)22);
	slist_prepend(slist, (void *)88);

	slist_sort(slist, cmp_int, SLIST_SORT_DESC_ORDER);
	slist_foreach(slist, print_int, NULL);

	printf("\n===========slist sort desc end==============\n");
}
static void test_slist_performance(void)
{
	int i = 0;
	int n = 32*1024;
	int data = 0;

	slist_s *slist = slist_create(NULL, NULL);

	for(i = 0; i< n; i++)
	{
		slist_insert_in_order(slist, cmp_int, (void *)i, SLIST_SORT_DESC_ORDER);
	}

	slist_destroy(slist);

	return;

}
int main()
{
	//test_int_slist();
	//test_invalid_params();
	//test_insert_asc();
	//test_insert_desc();
	//test_slist_sort_asc();
	//test_slist_sort_desc();
	test_slist_performance();
	return 0;
}


