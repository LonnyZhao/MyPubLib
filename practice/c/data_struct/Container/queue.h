/*
 * queue.h
 *
 *  Created on: 2015年11月1日
 *      Author: Lonny
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#ifdef __cplusplus
extern "C" {
#endif

typedef struct queue_t
{
	linear_container_s *linear_container;
}queue_s;

queue_s *queue_creaet(linear_container_s * container);
ret_e queue_head(queue_s *thiz, void **data);
ret_e queue_push(queue_s *thiz, void *data);
ret_e queue_pop(queue_s *thiz);
size_t queue_length(queue_s *thiz);
ret_e queue_foreach(queue_s *thiz, data_visit_func visit, void *ctx);
void queue_destroy(queue_s *thiz);

#ifdef __cplusplus
}
#endif
#endif /* QUEUE_H_ */
