/*
 * module.h
 *
 *  Created on: 2015年11月1日
 *      Author: Lonny
 */

#ifndef MODULE_H_
#define MODULE_H_
#ifdef __cplusplus
extern "C" {
#endif
typedef struct module_t
{
	void *handle;
}module_s;

typedef enum module_flags_t
{
	MODULE_FLAGS_NONE,
	MODULE_FLAGS_DELAY = 1
}module_flags_e;
/**
 * 以指定模式打开指定的动态链接库文件，并返回一个句柄给dlsym的调用进程
 * RTLD_LAZY:在dlopen返回前，对于动态库中的未定义符号不执行解析（只对函数引用有效，对于变量引用总是立即解析）
 * RTLD_NOW:需要在dlopen返回前，解析出所有未定义符号，如果解析不出来，在dlopen会返回NULL,错误为：
 * undefined symbol:xxx...
 * */
module_s module_create(const char *file_name, module_flags_e flags);
/**
 *根据动态链接库操作句柄与符号，返回符号对应的地址
 * */
void* module_sym(module_s *thiz, const char * func_name);
/**
 *关闭动态链接库
 * */
void* module_destroy(module_s *thiz);

#ifdef __cplusplus
}
#endif
#endif /* MODULE_H_ */
