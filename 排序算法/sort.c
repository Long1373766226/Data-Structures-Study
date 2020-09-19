/*************************************************************************
    > File Name: sort.c
    > Author: 郭耀龙
    > Mail: 1373766226@qq.com 
    > Created Time: Sat 19 Sep 2020 04:40:51 PM CST
    > Function: 排序算法学习
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

/*  交换两个数  */
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*  冒泡排序   */
void Bubble_Sort(int *arr, int len)
{
    int i,j,temp;

    for(i=0; i<len-1; i++)
    {
        int flag = 1;
        for(j=0; j<len-1-i; j++)
        {
            if(arr[j] > arr[j+1])   //相邻两个元素比较
            {
                flag = 0;
                Swap(&arr[j],&arr[j+1]);
            }
        }
        if(flag)
            break;
    }
}

/*  选择排序   */
void Selection_Sort(int *arr, int len)
{
    int i,j;

    for(i=0; i<len-1; i++)
    {
        int min = i;
        for(j=i+1; j<len; j++)   //走访未排序的元素
        {
            if(arr[j] < arr[min])   //找到目前的最小值
            {
                min = j;            //保存最小数的索引
            }
            Swap(&arr[min], &arr[i]);
        }
    }
}

/*  插入排序   */
void Insertion_Sort(int *arr, int len)
{
    int i,j,temp;
    for(i=1;i<len;i++)
    {
        temp = arr[i];
        for(j=i; j>0 && arr[j-1]>temp; j--)
            arr[j] = arr[j-1];
        arr[j] = temp;
    }
}

/*  希尔排序  */
void Shell_Sort(int *arr, int len)
{
    int gap, i, j,temp;
    
    for(gap = len>>1; gap > 0 ; gap >>= 1)  //初始gap增量为len/2
    {
        for(i = gap; i<len; i++)
        {
            temp = arr[i];
            for(j=i-gap; j>=0 && arr[j]>temp; j-= gap)
            {
                arr[j+gap] = arr[j];
            }
            arr[j+gap] = temp;
        }
    }
}

int main(int argc, const char* argv[])
{
    int arr[] = {7,6,2,1,9,3,4,8,5};
    
    int len = sizeof(arr)/sizeof(int);
    
    //Bubble_Sort(arr,len);
    //Selection_Sort(arr,len);
    //Insertion_Sort(arr,len);
    Shell_Sort(arr, len);
    
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
	return 0;
}
