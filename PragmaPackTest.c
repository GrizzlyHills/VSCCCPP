#include <stdio.h>

// #pragma pack(push, 1) //保存对齐状态
#pragma pack(3)
struct
{
    char m1;
    double m4;
    int m3;
} test1;
// #pragma pack(pop)//恢复对齐状态
#pragma pack()   //取消指定对齐，恢复缺省对齐

// // #pragma pack(push, 2) 
#pragma pack(4)
struct
{
    char m1;
    double m4;
    int m3;
} test2;
// // #pragma pack(pop)
#pragma pack()   //取消指定对齐，恢复缺省对齐

int main()
{
    // printf("%d, %d, %d, %d\n", sizeof(Test1.m1), sizeof(Test1.m4), sizeof(Test1.m3), sizeof(Test1));
    // printf("%p, %p, %p, %p\n", &Test1, &Test1.m1, &Test1.m4, &Test1.m3);

    // printf("%d, %d, %d, %d\n", sizeof(Test2.m1), sizeof(Test2.m4), sizeof(Test2.m3), sizeof(Test2));

    printf("%d         %d", sizeof(test1), sizeof(test2));
    getchar();
    return 0;
}