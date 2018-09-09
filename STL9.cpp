/*
编程题＃6： priority queue练习题

描述
我们定义一个正整数a比正整数b优先的含义是：
*a的质因数数目（不包括自身）比b的质因数数目多；
*当两者质因数数目相等时，数值较大者优先级高。
现在给定一个容器，初始元素数目为0，之后每次往里面添加10个元素，
每次添加之后，要求输出优先级最高与最低的元素，并把该两元素从容器中删除。

输入
第一行: num (添加元素次数，num <= 30)
下面10*num行，每行一个正整数n（n < 10000000).

输出
每次输入10个整数后，输出容器中优先级最高与最低的元素，两者用空格间隔。

样例输入
1
10 7 66 4 5 30 91 100 8 9
*/

#include <iostream>
#include <cmath>
#include <set>
using namespace std;

//判断一个数是否为质数
bool isPrime(int iVal)
{
    for (int i = 2; i <= sqrt((float)iVal); i++)
    {
        if (iVal % i == 0)
            return false;
    }
    return true;
}

//得到一个数的质因数数目
int getFactor(int a)                                            //这段判断质数数量的代码可以 copy 下来
{
    int sum = 0;
    int k = 0;
    for (int i = 2; i <= sqrt((float)a); i++)
    {
        if (a % i == 0)                         //即a/i = k，无余数
        {
            k = a / i;
            if (i != k && isPrime(k))
                sum += 1;
            if (isPrime(i))
            {
                sum += 1;
            }
        }
    }
    return sum;
}

//函数对象，判断大小
class Compare_Class_Up
{
    public:
        bool operator()(const int& a, const int& b)
        {
            int sumA = 0, sumB = 0;
            sumA = getFactor(a);
            sumB = getFactor(b);
            if (sumA == sumB)
            {
                if (a < b)
                {
                    return true;
                }
                else
                    return false;
            }
            else if (sumA < sumB)
            {
                return true;
            }
            else
                return false;
        }
};


int main()
{
    set<int, Compare_Class_Up> queue;
    int n = 0;
    cin >> n;
    while (n--)
    {
        int num;
        for (int i = 0; i < 10; i++)
        {
            cin >> num;
            queue.insert(num);
        }

        int min = *(queue.begin());
        int max = *(queue.rbegin());
        queue.erase(max);
        queue.erase(min);
        cout << max << ' ' << min << endl;
    }
    system("pause");
    return 0;
}
