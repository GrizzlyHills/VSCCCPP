/*
 * @Author: GrizzlyHills 
 * @Date: 2017-08-23 16:47:16 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-08-23 17:38:58

    编程题＃10：输出指定结果二

    描述
    通过填空使得程序输出的结果符合下面的要求。

    #include <iostream>
    #include <map>
    using namespace std;
    // 在此处补充你的代码
    int A::count = 0;
    void func(B b) { }
    int main()
    {
            A a1(5),a2;
            cout << A::count << endl;
            B b1(4);
            cout << A::count << endl;
            func(b1);
            cout << A::count << endl;
            A * pa = new B(4);
            cout << A::count << endl;
            delete pa;
            cout << A::count << endl;
            return 0;
    }

    样例输入
    不需要输入。

    样例输出
    2
    3
    B::destructor
    A::destructor
    3
    4
    B::destructor
    A::destructor
    3
    B::destructor
    A::destructor
    A::destructor
    A::destructor

    提示
    int A::count = 0; 这个变量是用来记录一共有多少个类A及类A的派生类的对象的。
 */

#include <iostream>
#include <map>
using namespace std;

// 在此处补充你的代码
class A
{
  public:
    static int count;
    A() { count++; }
    A(int a) { count++; }
    virtual ~A()
    {
        cout << "A::destructor" << endl;
    }
    /*
    使用了delete释放某个重载了delete的类的对象空间时，先调用类的析构函数，
    然后再调用重载的delete函数。
    */
    void operator delete(void *a) //重载delete
    {
        count--;
    }
};
class B : public A
{
  public:
    B() : A() {}
    B(int b) : A() {}
    B &operator=(B &b)
    {
        return b;
    }
    virtual ~B()
    {
        cout << "B::destructor" << endl;
    }
};

int A::count = 0;
void func(B b) {}
int main()
{
    A a1(5), a2;
    cout << A::count << endl;
    B b1(4);
    cout << A::count << endl;
    func(b1);                   //func() 的参数需要传入对象，故调用了构造和析构
    cout << A::count << endl;
    A *pa = new B(4);
    cout << A::count << endl;
    delete pa;
    cout << A::count << endl;
    system("pause");
    return 0;
}