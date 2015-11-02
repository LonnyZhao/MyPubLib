/*
 * darray.h
 *
 *      Created on: 2015年10月25日
 *      Author: Lonny
 */

#ifndef DARRAY_H_
#define DARRAY_H_
#ifdef __cplusplus
extern "C" {
#endif
typedef struct darray_t
{
	void **data;
	size_t size;
	size_t alloc_size;
	void *data_destroy_ctx;
	data_destroy_func data_destroy;
}darray_s;

#define MIN_PRE_ALLOCATE_NR 10
darray_s *darray_create(data_destroy_func data_destroy, void *ctx);

ret_e darray_insert(darray_s *thiz, size_t index, void *data);

ret_e darray_prepend(darray_s *thiz, void *data);

ret_e darray_append(darray_s  *thiz, void *data);

ret_e darray_delete(darray_s *thiz, size_t index);

ret_e darray_set_by_index(darray_s *thiz, size_t index, void *data);

ret_e darray_get_by_index(darray_s *thiz, size_t index, void **data);

size_t darray_length(darray_s *thiz);

int darray_find(darray_s *thiz, data_compare_func cmp, void *ctx);

ret_e darray_foreach(darray_s *thiz, data_visit_func visit, void *ctx);

void darray_destroy(darray_s *thiz);
#ifdef __cplusplus
}
#endif
#endif /* DARRAY_H_ */