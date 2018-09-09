#include <iostream>

void fun(int num, int sys)
{
    if (num == 0)
    {
        return;
    }
    else
    {
        fun(num / sys, sys);
    }

    printf("%d", num % sys);
}
int main()
{
    int input, system;
    while (1)
    {
        printf("请输入一个数字,以及想要转换的对应进制数：");
        scanf("%d%d", &input, &system);
        //std::cin>>input>>system;
        printf("转化为二进制为：");
        if (system == 8)
            printf("0");
        else if (system == 16)
            printf("0x");
        fun(input, system);

        printf("\n");
    }

    std::system("pause");
    return 0;
}
