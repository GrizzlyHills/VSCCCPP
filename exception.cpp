//bad_cast
//在用 dynamic_cast 进行从多态基类对象（或引用），到派生类的引用的强制类型转换时，如果转换是不安全的，则会抛出异常
#include <iostream>
//#include <stdexcept>              //貌似不用也可以产生异常的错误报告
//#include <typeinfo>               //貌似不用也可以产生异常的错误报告
#include <vector>
#include <string>
using namespace::std;

class Base {
    public:
        virtual void func() { cout << "Base" << endl; }
};

class Derived : public Base {
    public:
        virtual void Print() { cout << "Derived" << endl; }
};

class Derived1 : public Derived {
    public:
        void Print() { cout << "Derived1" << endl; }
};

void PrintObj(Base &b)
{
    try {
        Derived &rd = dynamic_cast<Derived&>(b);    //此转换若不安全， 会抛出 bad_cast 异常
        rd.Print();
    }
    catch (bad_cast &e) {
        cerr << e.what() << "-----Some wrong has happened" << endl;                   //有异常时输出：  std::bad_cast
    }
}    

int main()
{
    Derived d;
    Derived1 d1;
    Base b;
    PrintObj(d);                // 传递了派生类对象， 安全
    PrintObj(d1);
    PrintObj(b);                // 传递了基类对象， 不安全

    //bad_alloc
    //在用 new 运算符进行动态内存分配时， 如果没有足够的内存， 则会引发此异常
    try {
        char *p = new char[0x7ffffffffffffff];      //无法分配这么多空间， 会抛出异常
    }
    catch (bad_alloc &e) {
        cerr << e.what() << "-----Some wrong has happened" << endl;
    }

    //out_of_range
    //用 vector 或 string 的 at 成员函数根据下标访问元素时， 如果下标越界， 就会抛出此异常
    vector<int> v(10);
    try {
        v.at(100);          //抛出 out_of_range 异常
    }
    catch (out_of_range &e) {
        //cerr << e.what() << "-----Some wrong has happened" << endl;
    }

    string s = "hello";
    try {
        char c = s.at(100);          //抛出 out_of_range 异常
    }
    catch (out_of_range &e) {
        cerr << e.what() << "-----Some wrong has happened" << endl;
    }
    
    system("pause");
    return 0;
}