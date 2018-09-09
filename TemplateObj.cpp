/*
类模板的嵌套

描述
实现一个三维数组模版CArray3D，可以用来生成元素为任意类型变量的三维数组，使得下面程序输出结果是：

0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,

注意，只能写一个类模版，不能写多个。

#include <iostream>
using namespace std;
// 在此处补充你的代码
int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}
输入
无
输出
0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,
样例输入
无
样例输出
0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,
提示
提示：类里面可以定义类，类模版里面也可以定义类模版。例如：
class A
{
    class B {

    };
};

template 
class S
{
    T x;
    class K {
        T a;
    };
};
注：
利用三个类模板嵌套来分别对应一维，用Set()来设置内存；这也是从网上找的答案出来的！！
*/
#include <iostream>
using namespace std;
// 在此处补充你的代码
template <class T3>
class CArray3D
{
  public:
    template <class T2>
    class CArray2D
    {
      public:
        template <class T1>
        class CArray1D
        {
          private:
            T1 *ptr1;

          public:
            CArray1D() : ptr1(NULL) {}
            void set(int l)
            {
                ptr1 = new T1[l];
            }
            T1 &operator[](int index)
            {
                return ptr1[index];
            }
            ~CArray1D()
            {
                if (ptr1)
                    delete[] ptr1;
            }
        };
        CArray2D() : ptr2(NULL) {}
        void set(int x, int y)
        {
            ptr2 = new CArray1D<T2>[x];
            for (int i = 0; i < x; i++)
                ptr2[i].set(y);
        }
        CArray1D<T2> &operator[](int index)
        {
            return ptr2[index];
        }
        ~CArray2D()
        {
            if (ptr2)
                delete[] ptr2;
        }

      private:
        CArray1D<T2> *ptr2;
    };
    CArray3D() : ptr3(NULL) {}
    CArray3D(int n, int x, int y)
    {
        ptr3 = new CArray2D<T3>[n];
        for (int i = 0; i < n; i++)
            ptr3[i].set(x, y);
    }
    CArray2D<T3> &operator[](int index)
    {
        return ptr3[index];
    }
    ~CArray3D()
    {
        if (ptr3)
            delete[] ptr3;
    }

  private:
    CArray2D<T3> *ptr3;
};
int main()
{
    CArray3D<int> a(3, 4, 5);
    int No = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 5; ++k)
                a[i][j][k] = No++;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 5; ++k)
                cout << a[i][j][k] << ",";
    system("pause");
    return 0;
}