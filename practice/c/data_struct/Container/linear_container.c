#include <stdlib.h>
#include <stdio.h>
#include "typedef.h"
#include "common.h"
#include "debug.h"
#include "linear_container.h"

ret_e linear_container_insert(linear_container_s *thiz, size_t index, void *data)
{
	return_val_if_fail(thiz != NULL && thiz->insert != NULL, RET_INVALID_PARAMS);

	return thiz->insert(thiz, index, data);
}

ret_e linear_container_prepend(linear_container_s *thiz, size_t index, void *data)
{
	return_val_if_fail(thiz != NULL && thiz->prepend != NULL, RET_INVALID_PARAMS);

	return thiz->prepend(thiz, data);
}

ret_e linear_container_append(linear_container_s *thiz, size_t index, void *data)
{
	return_val_if_fail(thiz != NULL &&  thiz->append != NULL, RET_INVALID_PARAMS);

	return thiz->append(thiz, data);
}

ret_e lienar_container_delete(linear_container_s *thiz, size_t index)
{
	return_val_if_fail(thiz != NULL && thiz->del != NULL, RET_INVALID_PARAMS);

	return thiz->del(thiz, index);
}

ret_e linear_container_get_by_index(linear_container_s *thiz, size_t index, void** data)
{
	return_val_if_fail(thiz != NULL && thiz->get_by_index != NULL, RET_INVALID_PARAMS);

	return thiz->get_by_index(thiz, index, data);
}

ret_e linear_container_set_by_index(linear_container_s *thiz, size_t index, void *data)
{
	return_val_if_fail(thiz != NULL && thiz->set_by_index != NULL, RET_INVALID_PARAMS);

	return thiz->set_by_index(thiz, index, data);
}

ret_e linear_container_length(linear_container_s *thiz)
{
	return_val_if_fail(thiz != NULL && thiz->length != NULL, RET_INVALID_PARAMS);

	return thiz->length(thiz);
}

ret_e linear_container_find(linear_container_s *thiz, data_compare_func cmp, void *ctx)
{
	return_val_if_fail(thiz != NULL && thiz->find != NULL, -1);

	return thiz->find(thiz, cmp, ctx);
}

ret_e linear_container_foreach(linear_container_s thiz, data_visit_func visit, void *ctx)
{
	return_val_if_fail(thiz != NULL && thiz->foreach != NULL, RET_INVALID_PARAMS);

	return thiz->foreach(thiz, visit, ctx);
}

void linear_container_destory(linear_container_s *thiz)
{
	return_if_fail(thiz != NULL && thiz->destroy != NULL);

	return thiz->destroy(thiz);
}
