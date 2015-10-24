/*************************************************************************
	> File Name: queue.c
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月07日 星期三 11时12分32秒
 ************************************************************************/

#include<stdio.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "dlist.h"
#include "queue.h"

queue_s *queue_create(data_destroy_func data_destroy, void *ctx)
{
    queue_s *thiz = (queue_s *)malloc(sizeof(sizeof(queue_s)));

    if(thiz != NULL)
    {
        if((thiz->dlist = dlist_create(data_destory, ctx)) == NULL)
        {
            free(thiz);
            thiz = NULL;
        }
    }

    return thiz;
}

ret_e queue_head(queue_s *thiz, void **data)
{
    return_val_if_fail(thiz != NULL && data != NULL, RET_INVALID_PARAMS);

    return dlist_get_by_index(thiz->dlist, 0, data);
}

ret_e queue_push(queue_s *thiz, void *data)
{
    return_val_if_fail(thiz != NULL && data != NULL, RET_INVALID_PARAMS);

    return dlist_get_by_index(thiz->dlist, 0, data);
}

ret_e queue_push(queue_s *thiz, void *data)
{
    return_val_if_fail(thiz != NULL && data != NULL, RET_INVALID_PARAMS);

    return dlist_get_by_index(thiz->dlist, 0, data);
}

ret_e queue_pop(queue_s *thiz)
{
    return_val_if_fail(thiz != NULL, RET_INVALID_PARAMS);

    return dlist_delete(thiz->dlist, 0);
}

size_t queue_length(queue_s *thiz)
{
    return_val_if_fail(thiz != NULL, 0);

    return dlist_length(thiz->dlist);
}

ret_e queue_foreach(queue_s *thiz, data_vist_func visit, void *ctx)
{
    return_val_if_fail(thiz != NULL && visit != NULL, RET_INVALID_PARAMS);

    return dlist_foreach(thiz->dlist, visit, ctx);
}

void queue_destory(queue_s *thiz)
{
    if(thiz != NULL)
    {
        dlist_destroy(thiz->dlist);
        thiz->dlist = NULL;

        free(thiz);
        thiz = NULL;
    }

    return ;
}
