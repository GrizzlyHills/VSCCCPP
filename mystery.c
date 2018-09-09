/*
    神秘函数
    参数是一个 0~100 的值
*/

#include <stdio.h>

void mystery(int n)
{
    n += 5;
    n /= 10;
    puts("**********" + 10 - n);        //这种用法 值得记忆运用。
}

int main()
{
    int i;
    for(i = 1; i <= 100; i++) {
        mystery(i);
    }
    getchar();
    return 0;
}