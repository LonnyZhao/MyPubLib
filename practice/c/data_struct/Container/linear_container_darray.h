/*
 * linear_container_darray.h
 *
 *  Created on: 2015年11月1日
 *      Author: Lonny
 */

#ifndef LINEAR_CONTAINER_DARRAY_H_
#define LINEAR_CONTAINER_DARRAY_H_
#ifdef __cplusplus
extern "C" {
#endif
linear_container_s *linear_container_darray_create(data_destroy_func data_destroy, void *ctx);

#ifdef __cplusplus
}
#endif
#endif /* LINEAR_CONTAINER_DARRAY_H_ */
