/*
描述
在main函数中， 生成一个5*5的矩阵，输入矩阵数据，并输入n，m的值。
判断n，m是否在数组范围内，如果不在，则输出error；
如果在范围内，则将n行和m行交换，输出交换n，m后的新矩阵。

输入
5*5矩阵的数据，以及n和m的值。

输出
如果不可交换，则输出error
如果可交换，则输出新矩阵

样例输入
第一组
1 2 2 1 2
5 6 7 8 3
9 3 0 5 3
7 2 1 4 6
3 0 8 2 4
0 4
第二组
1 2 2 1 2
5 6 7 8 3
9 3 0 5 3
7 2 1 4 6
3 0 8 2 4
5 1

样例输出
第一组
   3   0   8   2   4
   5   6   7   8   3
   9   3   0   5   3
   7   2   1   4   6
   1   2   2   1   2
第二组
error

提示
输出error格式如下：
cout<< "error" << endl;
输出矩阵格式如下：
cout<< setw(4)<< num;
输出矩阵一行后要输出cout<< endl;
setw是iomanip库里定义的格式控制操作符，需要#include <iomanip> 包含这个头文件。
*/
#include <iostream>
#include <iomanip>
using namespace ::std;
#define row 5
#define column 5

int main(void)
{
    int arr[row][column] = {0};
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
        {
            cin >> arr[i][j];
        }
    int m, n, temp;
    if (cin >> m >> n && (n >= 0 && n < row) && (m >= 0 && m < row))
    {
        for (int i = 0; i < column; i++)
        {
            temp = arr[m][i];
            arr[m][i] = arr[n][i];
            arr[n][i] = temp;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                cout << setw(4) << arr[i][j];
            }
            cout << endl;
        }
    }
    else
        cout << "error" << endl;
    system("pause");
    return 0;
}
//机器评判通过