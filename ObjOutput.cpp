/*
下面程序输出的结果是：
0
5
请填空：

提示所缺代码具有如下形式：
A(_________________ ){ val = n; }
________________ GetObj() {
    return _________________;
}


分析代码a.GetObj() = 5;
首先，a.GetObj()返回A类型的对象，这个对象指向对象a自己。
this是指向自身对象的指针，*this是指针this的值即对象本身，返回值A&是一个引用，
即a.GetObj()的返回值就是对象a自己本身，这样分析其实a.GetObj() = 5;和a = 5是等价的。

分析代码a = 5
a是A类型，A类型的一个构造函数A(int v);只有一个参数，是一个类型转换构造函数，
C++会首先通过这个类型转换构造函数A(int v);构造一个临时对象，类型转换构造函数的参数v的值为5，
然后把这个临时对象赋值给a，然后临时对象消亡，最后a.val的值变成了5.
*/
#include <iostream>
using namespace std;
class A {
    public:
        int val;
        A()                 // 在此处补充你的代码
        {
            val = 0;
        }
        A(int val_)
        {
            val = val_;
        }
        A &GetObj()         //如果把引用符号&去掉，那么结果变为  0 0   ，为毛？
        {
            return *this;
        }
};
main()  
{
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
    system("pause");
    return 0;
}