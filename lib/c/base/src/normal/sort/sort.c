/*************************************************************************
	> File Name: sort.c
	> Brief: 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月05日 星期一 18时06分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "debug.h"
#include "sort_comm.h"
#include "sort.h"
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
ret_e select_sort(void **array, size_t nr, DataCompareFunc cmp)
{
    size_t i = 0;
    size_t max = 0;
    size_t right = 0;
    void *t_data = NULL;

    return_val_if_fail(array != NULL && cmp != NULL, RET_INVALID_PARAMS);

    if(nr < 2 && nr == 0)
    {
        return RET_OK;
    }

    for(right = nr - 1; right >= 1; right--)
    {
        for(i = 0, max = 0; i < right; i++)
        {
            if(cmp(array[i], array[max]) > 0)
            {
                max = i;
            }
        }

        if(cmp(array[max], array[right]) > 0)
        {
            t_data = array[right];
            array[right] = array[max];
            array[max] = t_data;
        }
    }

    return RET_OK;
}

/**
 * @brief 冒泡排序算法实现，采用将大的沉到最下面的方法进行排序
 *
 * @param[in] array        输入数据,使用二维数组是为了能对指向性内容，如字符串进行排序
 * @param[in] nr           输入数据个数
 * @param[in] cmp          比较函数，通过该函数实现升序和降序选择
 **/
ret_e bubble_sort(void **array, size_t nr, DataCompareFunc cmp)
{
    size_t i = 0;
    size_t j = 0;
    void *t_data = NULL;
    int status = TRUE;

    return_val_if_fail(array != NULL && cmp != NULL, RET_INVALID_PARAMS);

    if(nr < 2 && nr == 0)
    {
        return RET_OK;
    }
    
    for(i = 1; (i <= nr) && status; i++)
    {
        status = FALSE;
        for(j = 0; j < nr-i; j++)
        {
            if(cmp(array[j], array[j+1]) > 0)
            {
                t_data = array[j];
                array[j] = array[j+1];
                array[j+1] = t_data;
                status = TRUE;
            }
        }
    }

    return RET_OK; 
}

