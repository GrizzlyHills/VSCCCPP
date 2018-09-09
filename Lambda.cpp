#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace::std;

int main()
{
    int x = 1, y = 2, z = 3;
    cout << [](double a, double b) { return a + b; } (1.2, 2.5) << endl;
    auto ff = [=, &y, &z](int n) {
        cout << x << endl;
        y++;
        z++;
        return n * n;
    };
    cout << ff(15) << endl;
    cout << y << "," << z << endl;

    //优势用法
    int a[4] = { 4, 2, 11, 33 };
    sort(a, a + 4, [](int x, int y)->bool { return x % 10 < y % 10; });
    for_each(a, a + 4, [](int x) { cout << x << " "; });
    cout << endl;
    for ( auto &tmp : a) {
        [](int x) { cout << x << " "; } (tmp);          //for-range 循环也可以用
    }

    //一道题目
    cout << endl;
    int n = 0;
    int b[] = { 1, 2, 3, 4 };
    for_each(b, b + 4, [&](int e) { ++e; n += e; });
    cout << n << "," << b[2] << endl;                   //14, 3

    //另一个例子
    vector<int> c{ 1, 2, 3, 4 };
    int total = 0;
    for_each( c.begin(), c.end(), [&](int &x) { total += x; x *= 2; });
    cout << total << endl;                              //输出： 10
    for_each( c.begin(), c.end(), [](int x) { cout << x << " "; });     //输出： 2 4 6 8
    cout << endl;

    //实现递归求斐波那契数列第 n 项：
    function<int(int)> fib = [&fib](int n) {        // function<int(int)> 表示返回值为 int, 有一个 int 参数的函数
        return n <= 2 ? 1 : fib(n - 1) + fib(n - 2);
    };
    cout << fib(5) << endl;     //输出： 5

    system("pause");
    return 0;
}