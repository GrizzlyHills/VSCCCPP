/*
 * @Author: GrizzlyHills 
 * @Date: 2017-08-22 14:44:55 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-08-22 17:10:40

    编程题＃4：计算整数平方和

    描述
    下列程序每次读入一个整数N，若N为0则退出，否则输出N和N的平方。

    #include <iostream>
    using namespace std;
    // 在此处补充你的代码
    int main(int argc, char* argv[]) {
            CType obj;
            int n;
            cin>>n;
            while ( n ) {
                    obj.setvalue(n);
                    cout<<obj++<<" "<<obj<<endl;
                    cin>>n;
            }
            return 0;
    }

    输入
    K个整数。除最后一个数据外，其他数据均不为0。

    输出
    K-1行。第I行输出第I个输入数和它的平方。

    样例输入
    1 5 8 9 0

    样例输出
    1 1
    5 25
    8 64
    9 81
 */

#include <iostream>
using namespace std;

// 在此处补充你的代码
class CType {
    public:
        int m;
        void setvalue(int n)
        {
            m = n;
        }

        //正确的写法
        CType &operator++ (int)           //后置++， 需要传入一个 int 作为标记
        {
            static CType tmpObj;          //必须使用static变量,否则返回时内存就被释放了
            tmpObj.m = m;
            m *= m; 
            return tmpObj;
        }

        // //这样写出现了结果异常的情况，m的值保持为初始时的输入值 1 , 但是求平方的值都更新了。逻辑上貌似没有什么问题, 为什么 this->m 的值没有赋给 tmpObj.m 呢？
        // CType &operator++ (int)             //后置 ++ 的重载， 需要传入一个 int 作为标记
        // {
        //     static CType tmpObj = *this;    //这种写法是对象的初始化，调用了自动生成的复制构造函数，但这并不一定会使目标对象的每个成员变量都和源对象相等，
        //                                     //问题就出现在这里, 下面的两种写法都是是正解
        //     //static CType tmpObj;            //必须使用static变量, 否则返回时内存就被释放了
        //     //tmpObj = *this;                 //问题已经发现了， 这样写也没有问题
        //     //tmpObj.m = this->m;           //加上这一句后就没有问题了。。。。。。。。。。。。。
        //     m *= m; 
        //     return tmpObj;
        // }

        friend ostream &operator<< (ostream &os, CType &ob);
};

ostream &operator<< (ostream &os, CType &ob)
{
    os << ob.m;
    return os;
}

int main(int argc, char* argv[]) 
{
    CType obj;
    int n;
    cin >> n;
    while( n ) {
        obj.setvalue(n);
        cout << obj++ << " " << obj << endl;
        cin >> n;
    }
    system("pause");
    return 0;
}