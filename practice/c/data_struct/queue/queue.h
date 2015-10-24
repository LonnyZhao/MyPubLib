/*************************************************************************
	> File Name: queue.h
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月07日 星期三 10时59分33秒
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H
#ifdef __cplusplus
extern "C"{
#endif
/*********************************
 * @Brief queue定义
 ********************************/
typedef struct queue_t
{
    dlist_s *list;
}queue_s;

queue_s *queue_create(data_destroy_func data_destroy, void *ctx);
ret_e queue_head(queue_s *thiz, void **data);
ret_e queue_push(queue_s *thiz, void *data);
ret_e queue_pop(queue_s *thiz, void *data);
size_t queue_length(queue_s *thiz);
ret_e queue_foreach(queue_s *thiz, data_visit_func visit, void *ctx);
ret_e queue_destory(queue_s *thiz);
#ifdef __cplusplus
}
#endif
#endif
