// 编写一个函数，将一个整形x转换为二进制，并将结果存放在 char 型数组中，
// 最低位存放在数组第 0 个元素

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintArr(char arr[], int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// 这个方法与题意不符合
int anotherIdea()
{
    int num = 256;
    char buf[10];
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "%d", num); //num以整形的形式放在数组buf中去
    for (num = 0; num < strlen(buf); num++)
        printf("%d", buf[num]);
    return 0;
}

void Idea(int num)
{
    int i;
    char c[33] = {0};
    char *tmp = &c[0];
    for (i = 0; i < 32; i++) {
        printf("%d", 1 & (num >> i));       // 由低位到高位
        sprintf(tmp++, "%d", (1 & (num >> i)));
    }
    printf("\n");
    puts(c);                                // 由于字符串第一位就是'\0'，故没有显示。
    PrintArr(c, 32);
}

int main()
{
    int i = 256;
    char arr[4];
    memcpy(arr, &i, sizeof(int));   // 直接内存拷贝就可以了，因为在内存中这些数的表示是一致的。
    PrintArr(arr, 4);
    anotherIdea();
    printf("\n");
    Idea(-256);
    getchar();
    return 0;
}