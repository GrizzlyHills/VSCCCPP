// 编写一个函数输入一个字符串，将字符翻转作为返回值返回，
// 比如：“abcdef”翻转后变为“fedcba”。

#include <stdio.h>
#include <string.h>

void PrintArr(char arr[], int count)
{
    int i;
    for(i = 0; i < count; i++) {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}

char *revstr(char *str, size_t len)
{

    char    *start = str;
    char    *end = str + len - 1;
    char    ch;

    if (str != NULL)
    {
        while (start < end)
        {
            ch = *start;
            *start++ = *end;
            *end-- = ch;
        }
    }
    return str;
}

int main()
{
    char s[] = "abcdef";
    puts(revstr(s, strlen(s)));
    getchar();
    return 0;
}