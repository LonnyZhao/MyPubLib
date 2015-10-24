/*
 * main.c
 *
 *  Created on: 2015年10月23日
 *      Author: Lonny
 */

#include  <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "dlist.h"
#include "hashtable.h"


static int hash_int(void* data)
{
	return (int)data;
}

static int cmp_int(void* ctx, void* data)
{
	return (int)ctx - (int)data;
}

static ret_e print_int(void* ctx, void* data)
{
	printf("%d ", (int)data);

	return RET_OK;
}

int main(int argc, char* argv[])
{
	int i = 0;
	int n = 10000;
	int ret_data = 0;
	hash_table_s* hash_table = hash_table_create(NULL, NULL, hash_int, 31);

	printf("Hash table test begin....\n");
	for(i = 0; i < n; i++)
	{
		assert(hash_table_length(hash_table) == i);
		assert(hash_table_insert(hash_table, (void*)i) == RET_OK);
		assert(hash_table_length(hash_table) == (i + 1));
		assert(hash_table_find(hash_table, cmp_int, (void*)i, (void**)&ret_data) == RET_OK);
		assert(ret_data == i);
	}

	for(i = 0; i < n; i++)
	{
		assert(hash_table_delete(hash_table, cmp_int, (void*)i) == RET_OK);
		assert(hash_table_length(hash_table) == (n - i -1));
		assert(hash_table_find(hash_table, cmp_int, (void*)i, (void**)&ret_data) != RET_OK);
	}

	hash_table_destroy(hash_table);

	printf("Hash Table test end.\n");
	return 0;
}


