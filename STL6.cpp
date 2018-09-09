/*
编程题＃3：Set

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 5000ms 内存限制: 100000kB

描述
现有一整数集（允许有重复元素），初始为空。我们定义如下操作：
add x 把x加入集合
del x 把集合中所有与x相等的元素删除
ask x 对集合中元素x的情况询问
对每种操作，我们要求进行如下输出。
add 输出操作后集合中x的个数
del 输出操作前集合中x的个数
ask 先输出0或1表示x是否曾被加入集合（0表示不曾加入），再输出当前集合中x的个数，中间用空格格开。

输入
第一行是一个整数n，表示命令数。0<=n<=100000。
后面n行命令，如Description中所述。

输出
共n行，每行按要求输出。

样例输入
7
add 1
add 1
ask 1
ask 2
del 2
del 1
ask 1

样例输出
1
2
1 2
0 0
0
2
1 0

提示
Please use STL’s set and multiset to finish the task
*/

#include <iostream>
#include <iterator>
#include <set>
using namespace std;

class element {
    private:
        int elem;
    public:
        void SetElement(int e) { elem = e; }
        int GetElem() const { return elem; }        
        friend bool operator < (const element &e1, const element &e2)
        {
            return e1.elem < e2.elem;
        }
};

class element1 : public element {
    private:
        static bool flag;
    public:
        void SetFlag() { flag = true; }
        bool GetFlag() const { return flag; }  
        element1(int e) { SetElement(e); }
};

class element2 : public element {
    private:
        static bool flag;
    public:
        void SetFlag() { flag = true; }
        bool GetFlag() const { return flag; } 
        element2(int e) { SetElement(e); }
};

bool element1::flag = false;
bool element2::flag = false;

int main()
{
    int n;
    string cmd;
    int e;
    element1 tmp1(1);
    element2 tmp2(2);    
    multiset<element> test;
    cin >> n;
    while (n && cin >> cmd >> e) {
        if (cmd == "add") {
            if (e == 1) {
                test.insert(tmp1);
                tmp1.SetFlag();
                cout << test.count(tmp1) << endl;
            } else if (e == 2) {
                test.insert(tmp2);    
                tmp2.SetFlag();   
                cout << test.count(tmp2) << endl;
            }         
        } else if (cmd == "ask") {
            if (e == 1) {
                cout << tmp1.GetFlag() << " " << test.count(tmp1) << endl;
            } else if (e == 2) {
                cout << tmp2.GetFlag() << " " << test.count(tmp2) << endl;
            }
        } else if (cmd == "del") {
            if (e == 1) {
                cout << test.count(tmp1) << endl;
                test.erase(tmp1);
            } else if (e == 2) {
                cout << test.count(tmp2) << endl;
                test.erase(tmp2);
            }
        }
        cout << endl;
        //当前 multiset 中的元素分布
        for (const auto &tmp : test) {
            cout << "member: " << tmp.GetElem() << " "  << tmp1.GetFlag() << " " << tmp2.GetFlag() << "    ";
        }
        cout << endl;
        n--;
    }
    system("pause");
    return 0;
}

// C++ 中 const 引用的是对象时只能访问该对象的 const 函数， 因为其他函数有可能会修改该对象的成员， 编译器为了避免该类事情发生， 会认为调用非 const 函数是错误的。
// 函数末尾加 const， 表示不会修改该对象的成员。