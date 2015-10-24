/*************************************************************************
	> File Name: stack.c
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月07日 星期三 11时33分26秒
 ************************************************************************/

#include<stdio.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "dlist.h"
#include "stack.h"

stack_s *stack_create(data_destroy_func data_destroy, void *ctx)
{
    stack_s *thiz = (stack_s *)malloc(sizeof(stack_s));

    if(thiz != NULL)
    {
        if((thiz->dlist = dlist_create(data_destroy, ctx)) == NULL)
        {
            free(thiz);
            thiz = NULL;
        }
    }
    return thiz;
}

ret_e stack_top(stack_s *thiz, void **data)
{
    return_val_if_fail(thiz != NULL && data != NULL, RET_INVALID_PARAMS);
    
    return dlist_get_by_index(thiz->dlist, 0, data);
}

ret_e stack_push(stack_s *thiz, void *data)
{
    return_val_if_fail(thiz != NULL && data != NULL, RET_INVALID_PARAMS);
    
    return dlist_prepend(thiz->dlist, data);
}

ret_e stack_pop(stack_s *thiz, void **data)
{
    return_val_if_fail(thiz != NULL && data != NULL, RET_INVALID_PARAMS);

    return dlist_delete(thiz->dlist, 0);
}

ret_e stack_foreach(stack_s *thiz, data_visit_func visit, void *ctx)
{
    return_val_if_fail(thiz != NULL && visit != NULL, RET_INVALID_PARAMS);

    return dlist_foreach(thiz->dlist, visit, ctx);
}

void stack_destory(stack_s *thiz)
{
    if(thiz != NULL)
    {
        dlist_destory(thiz->dlist);
        thiz->dlist = NULL;

        free(thiz);
        thiz = NULL;
    }
}


