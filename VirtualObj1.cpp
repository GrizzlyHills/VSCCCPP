/*
编程题 #1

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

下面程序的输出结果是：
A::Fun
C::Do

请填空：
#include <iostream>
using namespace std;
class A {
    private:
        int nVal;
    public:
        void Fun()
        { cout << "A::Fun" << endl; }
        void Do()
        { cout << "A::Do" << endl; }
};
class B:public A {
    public:
        virtual void Do()
        { cout << "B::Do" << endl; }
};
class C:public B {
    public:
    void Do( )
    { cout << "C::Do" <<endl; }
    void Fun()
    { cout << "C::Fun" << endl; }
};
void Call(
// 在此处补充你的代码
        ) {
    p.Fun(); p.Do();
}
int main() {
    C c; Call(c);
    return 0;
}

输入
无

输出
A::Fun
C::Do

样例输入
无

样例输出
A::Fun
C::Do
*/
#include <iostream>
using namespace std;
class A
{
  private:
    int nVal;

  public:
    void Fun()
    {
        cout << "A::Fun" << endl;
    }
    void Do()
    {
        cout << "A::Do" << endl;
    }
};
class B : public A
{
  public:
    //virtual void Do()             //此时显示  C::Do   why？
    void Do()
    {
        cout << "B::Do" << endl;
    }
};
class C : public B
{
  public:
    void Do()
    {
        cout << "C::Do" << endl;
    }
    void Fun()
    {
        cout << "C::Fun" << endl;
    }
};
void Call(B &p)                      // 在此处补充你的代码
{
    p.Fun();                         //A::Fun
    p.Do();                          //C::Do
}
int main()
{
    C c;
    Call(c);
    system("pause");
    return 0;
}
// 注：类A的Fun()和Do()都不是虚函数，类B没有重新定义同名函数Fun(),  
// 只将Do()定义为虚函数，输出结果为类A的 Fun()和类C 的Do(),
// 在 main()中定义的是类C的对象，因此要按以上结果输入，那Call()的形参只能是类B的引用；