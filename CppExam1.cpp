/*
 * @Author: GrizzlyHills 
 * @Date: 2017-08-22 09:38:02 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-08-22 12:44:30

    编程题＃2：输出指定结果一

    描述
    填写代码，使输出结果为

    2
    2
    8
    10

    #include <iostream>
    using namespace std;
    class Number {
    public:
        int num;
        Number(int n): num(n) {
        }
    // 在此处补充你的代码
    };
    int main() {
        Number a(2);
        Number b = a;
        cout << a.value() << endl;
        cout << b.value() << endl;
        a.value() = 8;
        cout << a.value() << endl;
        a+b;
        cout << a.value() << endl;
        return 0;
    }

    输入
    不需要输入。

    输出
    使输出结果为
    2
    2
    8
    10
 */

#include <iostream>
using namespace std;

class Number {
public:
    int num;
    Number(int n): num(n) {         //只有一个参数的构造函数一般都可以称为类型转换构造函数，因为这样的构造函数能起到类型自动转换的作用。
    }
// 在此处补充你的代码
    int &value() 
    {
        return num;
    }
    void operator+ (const Number &n) 
    {
        num += n.num;
    }
};

int main() {
    Number a(2);
    Number b = a;                   //调用默认的复制构造函数，同 Number b(a)
    cout << a.value() << endl;
    cout << b.value() << endl;
    a.value() = 8;
    cout << a.value() << endl;
    a+b;
    cout << a.value() << endl;
    system("pause");
    return 0;
}