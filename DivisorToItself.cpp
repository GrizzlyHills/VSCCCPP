/*
注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
对一个整数n,如果其各个位数的数字相加得到的数m能整除n,则称n为自整除数.
例如21,21%(2+1)==0,所以21是自整除数.现求出从10到n(n < 100)之间的所有自整除数.

输入
有一行,整数n,(10 <= n < 100)

输出
有多行.按从小到大的顺序输出所有大于等于10,小于等于n的自整除数,每行一个自整除数.

样例输入
47

样例输出
10
11
12
10
12
18
20
21
24
27
30
36
40
42
45
*/

#include <iostream>
using namespace std;

int main()
{
    int n, unitPlace, tenPlace, currentNum;
    bool flag = false;
    while (cin >> n && flag == true)
    {
        if (n >= 10 && n < 100)
        {
            flag = true;
            break;
        }
        else
            return 0;
    }
    for (int i = 10; i <= n; i++)
    {
        currentNum = i;
        unitPlace = currentNum % 10;
        tenPlace = currentNum / 10 % 10;
        if (currentNum % (unitPlace + tenPlace) == 0)
            cout << currentNum << endl;
    }
    system("pause");
    return 0;
}
//机器评判通过