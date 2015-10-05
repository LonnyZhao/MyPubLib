/*************************************************************************
	> File Name: sort.h
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月05日 星期一 19时22分30秒
 ************************************************************************/

#ifndef _SORT_H
#define _SORT_H
#ifdef __cplusplus
extern "C" {
#endif
/**
 *
 * @brief 选择排序算法实现，每次选择最大的值排列到最后
 * @param[in] array        输入数据,使用二维数组是为了能对指向性内容，如字符串进行排序
 * @param[in] nr           输入数据个数
 * @param[in] cmp          比较函数，通过该函数实现升序和降序选择
 *
 * @return  RET_OK         成功
 * @return  其他           失败
* */
ret_e select_sort(void **array, size_t nr, DataCompareFunc cmp);

/**
 * @brief 冒泡排序算法实现，采用将大的沉到最下面的方法进行排序
 *
 * @param[in] array        输入数据,使用二维数组是为了能对指向性内容，如字符串进行排序
 * @param[in] nr           输入数据个数
 * @param[in] cmp          比较函数，通过该函数实现升序和降序选择
 **/
ret_e bubble_sort(void **array, size_t nr, DataCompareFunc cmp);
typedef ret_e (*SortFunc)(void** array, size_t nr, DataCompareFunc cmp);
#ifdef __cplusplus
}
#endif /* end of __cplusplus*/
#endif /* end of _SORT_H*/
