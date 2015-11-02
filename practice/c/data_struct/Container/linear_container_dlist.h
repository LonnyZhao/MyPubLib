/*
 * linear_container_dlist.h
 *
 *  Created on: 2015年11月1日
 *      Author: Lonny
 */

#ifndef LINEAR_CONTAINER_DLIST_H_
#define LINEAR_CONTAINER_DLIST_H_
#ifdef __cplusplus
extern "C" {
#endif
linear_container_s*lieanr_container_dlist_create(data_destroy_func data_destroy, void *ctx);
#ifdef __cplusplus
}
#endif
#endif /* LINEAR_CONTAINER_DLIST_H_ */
