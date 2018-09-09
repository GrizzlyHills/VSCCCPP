/*
编程题 ＃3

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

写一个二维数组类 Array2,使得下面程序的输出结果是：
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,

程序：
#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
int main() {
    Array2 a(3,4);
    int i,j;
    for( i = 0;i < 3; ++i )
        for( j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b; b = a;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

输入
无

输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,

样例输入
无

样例输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
*/
#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2
{
    // 在此处补充你的代码
    int **ptr;
    int _x, _y;

  public:
    Array2() : ptr(NULL), _x(0), _y(0) {}
    Array2(int x, int y)                    //分配空间
    {
        _x = x;
        _y = y;
        ptr = new int *[x];
        for (int i = 0; i < x; i++)
        {
            ptr[i] = new int[y];            //一次分配了 y * 4 个字节的空间
        }
    }
    int *operator[](int n)
    {
        return ptr[n];
    }
    int operator()(int x, int y)
    {
        return ptr[x][y];
    }
    Array2 &operator=(const Array2 &a)
    {
        if (ptr != NULL)
        {
            for (int i = 0; i < _x; i++)
            {
                delete[] ptr[i];
            }
            delete[] ptr;
        }
        ptr = new int *[a._x];
        for (int i = 0; i < a._x; i++)
        {
            ptr[i] = new int[a._y];
            memcpy(ptr[i], a.ptr[i], sizeof(int) * a._y);
        }
        _x = a._x;
        _y = a._y;
        return *this;
    }
    ~Array2()
    {
        for (int i = 0; i < _x; i++)
            delete[] ptr[i];                    //先释放各行空间
        delete[] ptr;                           //再释放存放各行头指针的指针的指针
    }
};
int main()
{
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}