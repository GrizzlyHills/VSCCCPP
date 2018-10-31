// 使用结构体定义函数指针 Quicksort，并通过此函数实现快速排序
// 请定义结构体 sort 和 函数指针 Quicksort
#include <stdio.h>
#include <stdlib.h>

struct Qsort {
    void (*Quicksort)(int* ,int ,int);
};

void PrintArr(int arr[], int count)
{
    int i;
    for(i = 0; i < count; i++) {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}

int PartSort(int* array,int left,int right)
{
    int key = array[right];
    printf("!key = %-10d", key);
    PrintArr(array, 9);
    while(left < right)
    {
        while(left < right && array[left] <= key)
        {
            ++left;
        }
        array[right] = array[left];
        //PrintArr(array, 9);
        while(left < right && array[right] >= key)
        {
            --right;
        }
        array[left] = array[right];  
        //PrintArr(array, 9);
    }
    array[right] = key;
    printf("@key = %-10d", key);
    PrintArr(array, 9);
    return right;
}

void Quicksort(int* array,int left,int right)
{

    if(left >= right)//表示已经完成一个组
    {
        return;
    }
    int index = PartSort(array,left,right);//枢轴的位置
    Quicksort(array,left,index - 1);
    Quicksort(array,index + 1,right);
}


int main()
{
    int a[] = {55, 60, 49, 32, 12, 58, 56, 1, 90};
    PrintArr(a, 9);
    Qsort s;
    s.Quicksort = Quicksort;
    s.Quicksort(a, 0, sizeof(a)/sizeof(a[0]) - 1);
    PrintArr(a, sizeof(a)/sizeof(a[0]));
    getchar();
    return 0;
}