/*
编程题 ＃2

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
下面的MyInt类只有一个成员变量。MyInt类内部的部分代码被隐藏了。假设下面的程序能编译通过，且输出结果是:
4,1

请写出被隐藏的部分。（您写的内容必须是能全部放进 MyInt类内部的，MyInt的成员函数里不允许使用静态变量）。
#include <iostream>
using namespace std;
class MyInt {
    int nVal;
    public:
        MyInt(int n) { nVal = n; }
        int ReturnVal() { return nVal; }
// 在此处补充你的代码
};
int main () {
    MyInt objInt(10);
    objInt-2-1-3;
    cout << objInt.ReturnVal();
    cout <<",";
    objInt-2-1;
    cout << objInt.ReturnVal();
    return 0;
}
输入
无

输出
4,1

样例输入
无

样例输出
1
4,1
*/
#include <iostream>
using namespace std;
class MyInt {
    int nVal;
    public:
        MyInt(int n) { nVal = n; }
        int ReturnVal() { return nVal; }
    // 在此处补充你的代码
    MyInt &operator-(const int i)                   //必须返回引用类型的对象，否则重载只能计算一次
    {
        nVal -= i;
        return *this;
    }
};
int main () {
    MyInt objInt(10);
    objInt-2-1-3;
    cout << objInt.ReturnVal();
    cout <<",";
    objInt-2-1;
    cout << objInt.ReturnVal() << endl;
    system("pause");
    return 0;
}