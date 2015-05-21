/*#include<iostream>
#include<malloc.h>
using namespace std;

int getdigit(int x,int d)  
{   
    int a[] = {1, 1, 10};     //因为待排数据最大数据也只是两位数，所以在此只需要到十位就满足
    return ((x / a[d]) % 10);    //确定桶号
}  

void  PrintArr(int ar[],int n)
{
    for(int i = 0; i < n; ++i)
        cout<<ar[i]<<" ";
    cout<<endl;
}

void msdradix_sort(int arr[],int begin,int end,int d)  
{     
    const int radix = 10;   
    int count[radix], i, j; 
    //置空
    for(i = 0; i < radix; ++i)   
    {
        count[i] = 0;   
    }
    //分配桶存储空间
    int *bucket = (int *) malloc((end-begin+1) * sizeof(int));    
    //统计各桶需要装的元素的个数  
    for(i = begin;i <= end; ++i)   
    {
        count[getdigit(arr[i], d)]++;   
    }
    //求出桶的边界索引，count[i]值为第i个桶的右边界索引+1
    for(i = 1; i < radix; ++i)   
    {
        count[i] = count[i] + count[i-1];    
    }
    //这里要从右向左扫描，保证排序稳定性 
    for(i = end;i >= begin; --i)          
    {    
        j = getdigit(arr[i], d);      //求出关键码的第d位的数字， 例如：576的第3位是5   
        bucket[count[j]-1] = arr[i];   //放入对应的桶中，count[j]-1是第j个桶的右边界索引   
        --count[j];                    //第j个桶放下一个元素的位置(右边界索引+1)   
    }   
    //注意：此时count[i]为第i个桶左边界    
    //从各个桶中收集数据  
    for(i = begin, j = 0;i <= end; ++i, ++j)  
    {
        arr[i] = bucket[j]; 
    }       
    //释放存储空间
    free(bucket);   
    //对各桶中数据进行再排序
    //count[0]=0
    for(i = 0;i < radix; i++)  
    {   
        int p1 = begin + count[i];         //第i个桶的左边界   
        int p2 = begin + count[i+1]-1;     //第i个桶的右边界   
        if(p1 < p2 && d > 1)  
        {
            msdradix_sort(arr, p1, p2, d-1);  //对第i个桶递归调用，进行基数排序，数位降 1    
        }
    }  
} 

void  main()
{
    int  ar[] = {12, 14, 54, 5, 6, 3, 9, 8, 47, 89};
    int len = sizeof(ar)/sizeof(int);
    cout<<"排序前数据如下："<<endl;
    PrintArr(ar, len);
    msdradix_sort(ar, 0, len-1, 2);
    cout<<"排序后结果如下："<<endl;
    PrintArr(ar, len);
	system("pause");
} */
/*
排序前数据如下：
12 14 54 5 6 3 9 8 47 89
排序后结果如下：
3 5 6 8 9 12 14 47 54 89
 */
#include<iostream>
#include<malloc.h>
using namespace std;

#define   MAXSIZE   10000

int getdigit(int x,int d)  
{   
    int a[] = {1, 1, 10, 100};   //最大三位数，所以这里只要百位就满足了。
    return (x/a[d]) % 10;  
}  
void  PrintArr(int ar[],int n)
{
    for(int i = 0;i < n; ++i)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}  
void lsdradix_sort(int arr[],int begin,int end,int d)  
{    
    const int radix = 10;   
    int count[radix], i, j; 

    int *bucket = (int*)malloc((end-begin+1)*sizeof(int));  //所有桶的空间开辟   
   
    //按照分配标准依次进行排序过程
    for(int k = 1; k <= d; ++k)  
    {  
        //置空
        for(i = 0; i < radix; i++)  
        {
            count[i] = 0;        
        }               
        //统计各个桶中所盛数据个数
        for(i = begin; i <= end; i++) 
        {
           count[getdigit(arr[i], k)]++;
        }
        //count[i]表示第i个桶的右边界索引
        for(i = 1; i < radix; i++) 
        {
            count[i] = count[i] + count[i-1];
        }
        //把数据依次装入桶(注意装入时候的分配技巧)
        for(i = end;i >= begin; --i)        //这里要从右向左扫描，保证排序稳定性   
        {    
            j = getdigit(arr[i], k);        //求出关键码的第k位的数字， 例如：576的第3位是5   
            bucket[count[j]-1] = arr[i]; //放入对应的桶中，count[j]-1是第j个桶的右边界索引 
            --count[j];               //对应桶的装入数据索引减一  
        } 

        //注意：此时count[i]为第i个桶左边界  
        
        //从各个桶中收集数据
        for(i = begin,j = 0; i <= end; ++i, ++j)  
        {
            arr[i] = bucket[j];    
        }        
    }     
    free(bucket);   
}  

void  main()
{
    int  br[10] = {20, 80, 90, 589, 998, 965, 852, 123, 456, 789};
    cout<<"原数据如下："<<endl;
    PrintArr(br,10);
    lsdradix_sort(br, 0, 9, 3);
    cout<<"排序后数据如下："<<endl;
	system("pause");
    PrintArr(br, 10);
}
/*
原数据如下：
20 80 90 589 998 965 852 123 456 789
排序后数据如下：
20 80 90 123 456 589 789 852 965 998
*/