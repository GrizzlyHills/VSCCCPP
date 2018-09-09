/*
 * @Author: GrizzlyHills 
 * @Date: 2017-08-21 11:15:37 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-08-22 12:45:38

    编程题＃1：输出200

    描述
    使以下代码输出结果为200.

    #include<iostream>
    using namespace std;
    class Number {
    public:
        int num;
        Number(int n=0): num(n) {}
    // 在此处补充你的代码
    };
    int main() {
        Number n1(10), n2(20);
        Number n3;n3 = n1*n2;
        cout << int(n3) << endl;
        return 0;
    }

    输入
    不需要输入。

    输出
    输出结果为200。

    样例输入
    不需要输入。

    样例输出
    200
 */

#include<iostream>
using namespace std;
class Number {
    public:
        int num;
        Number(int n=0): num(n) {}
        
        // 在此处补充你的代码
        Number operator* (const Number &n);

        //重载类型转换方程，不能能有返回值
        operator int();
        // {
        //     return this->num;                     //真心看不懂
        // }

};

Number Number::operator* (const Number &n)
{
    return Number(num * n.num);
}

//重载类型转换方程，不能能有返回值；重载强制类型转换运算符；
Number::operator int()
{
    return this->num;                     //真心看不懂, 也不返回一个明确的类型; 问题的关键是明明返回的是一个 int 类型的变量， 函数名前面加上 int 反而报错！！
}

int main() {
    Number n1(10), n2(20);
    Number n3;
    n3 = n1*n2;                           //对象的赋值只对其中的数据成员赋值，而不对成员函数赋值。
                                          //数据成员是占存储空间的，不同对象的数据成员占有不同的存储空间，
                                          //赋值的过程是将一个对象的数据成员在存储空间的状态复制给另一对象的数据成员的存储空间。
    cout << int(n3) << endl;
    system("pause");
    return 0;
} 