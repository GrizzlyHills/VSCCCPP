#include <iostream>
#include <cstdio>
using namespace ::std;

void toSixteen(unsigned int n)
{
    if (n >= 16)
    {
        toSixteen(n / 16);
    }
    if (n % 16 < 10)
        cout << n % 16;
    else
        printf("%c", n % 16 - 10 + 'A');
}

void overflow() //溢出试验
{
    int flag = 0;
    char c[4];
    scanf("%s", c);
    if (flag)
    {
        printf("flag is not 0\n");
    }
    else
    {
        printf("flag is 0\n");
    }
}

int main()
{
    unsigned int n;
    scanf("%ud", &n);
    //cin >> n;
    toSixteen(n);
    overflow();
    system("pause");
}