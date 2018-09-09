/*
描述
下面程序的输出是：
10

请补足Sample类的成员函数。不能增加成员变量。


#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
// 在此处补充你的代码
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}

输入
无

输出
10

样例输入
无

样例输出
10

在代码 Sample b = a;中，这里的=是初始化，而不是赋值，
在用同类型的对象对对象初始化的时候会调用复制构造函数。形如Sample(Sample& s)，
以同类型的引用作为构造函数的参数的构造函数是复制构造函数。
在 Sample b = a;中，a是复制构造函数的参数，调用构造函数的对象的v的值被赋值为10。

调用复制构造函数的三种情况
1.初始化：当用一个对象去初始化同类的另一个对象时
2.函数参数：如果某函数有一个参数是类A的对象，那么该函数被调用时，类A的复制构造函数被调用
3.函数返回值：如果函数的返回值是类A的对象时，则函数返回时，A的复制构造函数被调用
*/
#include <iostream>
using namespace std;

class Sample{
    public:
        int v;
        Sample(int n):v(n) { }              // 在此处补充你的代码
        Sample(Sample &S) {
            v = 10;
            //v = S.v * 2;
        }                          
};

int main() 
{
    Sample a(5);
    Sample b = a;
    cout << b.v;
    system("pause");
    return 0;
}