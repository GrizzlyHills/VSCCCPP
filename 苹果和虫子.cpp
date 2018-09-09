/*
描述
你买了一箱n个苹果，很不幸的是买完时箱子里混进了一条虫子。
虫子每x小时能吃掉一个苹果，假设虫子在吃完一个苹果之前不会吃另一个，
那么经过y小时你还有多少个完整的苹果？

输入
输入仅一行，包括n，x和y（均为整数）。输入数据保证y <= n * x。

输出
输出也仅一行，剩下的苹果个数

样例输入
10 4 9

样例输出
7
*/

#include <iostream>
using namespace::std;

int main(void)
{
    //依次输入苹果数n，吃一个苹果时间x，耗时y
    int n,x,y;
    do{
        cout << "请输入数据：";
        cin >> n >> x >> y;
        cout << endl;
    }while(y > n * x);
    //计算还剩几个苹果
    int nRemaining = n - (y/x + 1);
    cout << nRemaining << endl;
    system("pause");
    return 0;
}

/*机器能接受的版本，仔细看了看，我果然疏漏了很多地方
#include<iostream>
using namespace std;
int main()
{
    int n, x, y;
    float q; //  WHY NOT  int q ?    They are all right!
    cin >> n >> x >> y;
    q = y % x;
    if(y > n * x)
        cout << 0;     //情况一
    else {
        if(q == 0)
            n = n - y / x;  //情况二
        else
            n = n - y / x - 1;  //情况三。我只考虑到了这种情况，惭愧！
        cout << n;
    }
    return 0;
}
*/