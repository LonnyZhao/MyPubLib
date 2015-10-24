/*************************************************************************
	> File Name: stack.h
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月07日 星期三 11时27分11秒
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H
#ifdef __cplusplus
extern "C" {
#endif
typedef struct stack_t
{
    dlist_s *dlist;
}stack_s;

stack_s *stack_create(data_destroy_func data_destroy, void *ctx);
ret_e stack_top(stack_s *thiz, void **data);
ret_e stack_push(stack_s *thiz, void *data);
ret_e stack_pop(stack_s *thiz);
ret_e stack_length(stack_s *thiz);
ret_e stack_foreach(stack_s *thiz, data_visit_func visit, void *ctx);
void stack_destroy(stack_s *thiz);
#ifdef __cplusplus
}
#endif
#endif
