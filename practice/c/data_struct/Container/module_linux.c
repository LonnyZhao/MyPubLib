/*
 * module_linux.c
 *
 *  Created on: 2015年11月1日
 *      Author: Lonny
 */
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include "typedef.h"
#include "debug.h"
#include "common.h"

#include "module.h"

module_s * module_create(const char *file_name, module_flags_e flags)
{
	module_s *thiz = NULL;
	return_val_if_fail(file_name != NULL, NULL);

	if((thiz = malloc(sizeof(module_s))) != NULL )
	{
		thiz->handle = dlopen(file_name, flags & MODULE_FLAGS_NONE ?  RTLD_LAZY : RTLD_NOW);
		if(thiz->handle == NULL)
		{
			free(thiz);
			thiz = NULL;
			printf("%s\n", dlerror());
		}
	}

	return thiz;
}

/**
 *根据动态链接库操作句柄与符号，返回符号对应的地址
 * */
void * module_sym(module_s *thiz, const char * func_name)
{
	return_val_if_fail(thiz != NULL && thiz->handle != NULL && func_name != NULL, NULL);

	dlerror();

	return dlsym(thiz->handle, func_name);
}

void module_destroy(module_s *thiz)
{
	if(thiz != NULL && thiz->handle != NULL)
	{
		dlclose(thiz->handle);
		free(thiz);
	}
	return;
}
