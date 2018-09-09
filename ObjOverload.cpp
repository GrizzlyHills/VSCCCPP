/*
编程题 ＃1

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

下面程序的输出是：
3+4i
5+6i

请补足Complex类的成员函数。不能加成员变量。
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:    
    double r,i;
public:    
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
输入
无

输出
3+4i
5+6i

样例输入
无

样例输出
3+4i
5+6i
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:    
    double r,i;
public:    
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    // 在此处补充你的代码
    Complex() : r(0), i(0) {}
    Complex &operator=(const char *ch)                  //不加const  会有警告
    {
        int ii = 0;
        char cr[100];
        while (*ch != '+')
        {
            cr[ii] = *ch;
            ch++;
            ii++;
        }
        cr[ii] = '\n';
        ch++;

        r = atoi(cr);
        i = atoi(ch); // atoi(6i)  得到结果为6；
        return *this;
    }
};
int main() {
    Complex a;
    a = "3+4i"; 
    a.Print();
    a = "5+6i"; 
    a.Print();
    system("pause");
    return 0;
}