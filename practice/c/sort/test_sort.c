/*************************************************************************
	> File Name: test_sort.c
	> Brief: 用于测试排序函数库是否正确 
	> Author: Lonny
	> Mail: zhaochenglong08@126.com
	> Created Time: 2015年10月05日 星期一 19时54分28秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "typedef.h"
#include "common.h"
#include "sort_comm.h"
#include "sort.h"
void **create_int_array(int n)
{
    int i = 0;
    int *array = (int *)malloc(sizeof(int) * n);

    for(i = 0; i < n; i++)
    {
        array[i] = rand()%20;
    }

    return (void **)array;
}
void print_arr(void **array, size_t n)
{
    size_t i = 0;
    
    for(i = 0; i < n; i++)
    {
        printf("%d\t", (int)array[i]);
    }
    printf("\n");
}
void sort_test_asc(SortFunc sort, int n)
{
    int i = 0;
    void **array = create_int_array(n);

    sort(array, n, int_cmp);
    
    for(i = 1; i < n; i++)
    {
        assert(array[i] >= array[i-1]);
    }

    free(array);

    return;
}
void sort_test_dsc(SortFunc sort, int n)
{
    int i = 0;
    void **array = create_int_array(n);

    sort(array, n, int_cmp_invert);

    for(i = 1; i < n; i++)
    {
        assert(array[i] <= array[i-1]);
    }

    free(array);

    return;
}
void sort_test(SortFunc sort)
{
    int i = 0;
    for(i = 0; i < 1000; i++)
    {
        sort_test_asc(sort, i);
        sort_test_dsc(sort, i);
    }

    return;
}
int main(int argc, char **argv)
{
    srand(100);

    printf("bubble sort test begin.\n");
    sort_test(bubble_sort);
    printf("bubble sort test success.\n");

    printf("select sort test begin.\n");
    sort_test(select_sort);
    printf("select sort test success.\n");
    return 0;
}
