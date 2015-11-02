/*
 * linear_container.h
 *
 *  Created on: 2015年10月28日
 *      Author: Lonny
 */

#ifndef LINEAR_CONTAINER_H_
#define LINEAR_CONTAINER_H_
#ifdef __cplusplus
extern "C" {
#endif
struct _linear_container;
typedef struct _linear_container linear_container_s;
typedef ret_e (*linear_container_insert_func)(linear_container_s* thiz, size_t index, void* data);

typedef ret_e (*linear_container_prepend_func)(linear_container_s* thiz, void* data);
typedef ret_e (*linear_container_append_func)(linear_container_s* thiz, void* data);
typedef ret_e (*linear_container_delete_func)(linear_container_s* thiz, size_t index);
typedef ret_e (*linear_container_get_by_index_func)(linear_container_s* thiz, size_t index, void** data);
typedef ret_e (*linear_container_set_by_index_func)(linear_container_s* thiz, size_t index, void* data);
typedef size_t (*linear_container_length_func)(linear_container_s* thiz);
typedef int  (*linear_container_find_func)(linear_container_s* thiz, data_compare_func cmp, void* ctx);
typedef ret_e  (*linear_container_foreach_func)(linear_container_s* thiz, data_visit_func visit, void* ctx);
typedef void  (*linear_container_destroy_func)(linear_container_s* thiz);

struct _linear_container
{
	linear_container_insert_func insert;
	linear_container_prepend_func prepend;
	linear_container_append_func append;
	linear_container_delete_func del;
	linear_container_get_by_index_func get_by_index;
	linear_container_set_by_index_func set_by_index;
	linear_container_length_func length;
	linear_container_find_func find;
	linear_container_foreach_func foreach;
	linear_container_destroy_func destroy;

	char priv[0];
};

ret_e linear_container_insert(linear_container_s *thiz, size_t index, void *data);
ret_e linear_container_prepend(linear_container_s *thiz, size_t index, void *data);
ret_e linear_container_append(linear_container_s *thiz, size_t index, void *data);
ret_e lienar_container_delete(linear_container_s *thiz, size_t index);
ret_e linear_container_get_by_index(linear_container_s *thiz, size_t index, void** data);
ret_e linear_container_set_by_index(linear_container_s *thiz, size_t index, void *data);
ret_e linear_container_length(linear_container_s *thiz);
ret_e linear_container_find(linear_container_s *thiz, data_compare_func cmp, void *ctx);
ret_e linear_container_foreach(linear_container_s thiz, data_visit_func visit, void *ctx);
void linear_container_destory(linear_container_s *thiz);
#ifdef __cplusplus
}
#endif
#endif /* LINEAR_CONTAINER_H_ */