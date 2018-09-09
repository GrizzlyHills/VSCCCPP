/*
描述
中位数定义：一组数据按从小到大的顺序依次排列，
处在中间位置的一个数或最中间两个数据的平均值
（如果这组数的个数为奇数，则中位数为位于中间位置的那个数；如果这组数的个数为偶数，则中位数是位于中间位置的两个数的平均值）.
给出一组无序整数，求出中位数，如果求最中间两个数的平均数，向下取整即可（不需要使用浮点数）

输入
该程序包含多组测试数据，每一组测试数据的第一行为N，代表该组测试数据包含的数据个数，1 <= N <= 15000.
接着N行为N个数据的输入，N=0时结束输入

输出
输出中位数，每一组测试数据输出一行

样例输入
4
10
30
20
40
3
40
30
50
4
1
2
3
4
0

样例输出
25
40
2

提示
这是也一道经典的算法问题，在企业面试里出现概率很高，是“找到第K大的数”的变种。
先排序再找中位数自然是很直接的做法，但排序本身很慢。
我们只想找到第n/2大的数，对于其他数的顺序我们并不关心。
那么怎么在不排序的前提下找到第n/2大的数呢？
*/

//方法一
#include <iostream>
#include <iomanip>
using namespace ::std;

int main(void)
{
    int N, arr[15000];
    while (cin >> N && N > 0)
    {
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        //排序
        for (int i = 0; i < N; i++)
            for (int j = i; j < N; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp;
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        if (N % 2 == 0)
        {
            cout << (arr[N / 2 - 1] + arr[N / 2]) / 2 << endl;
        }
        else
        {
            cout << arr[N / 2] << endl;
        }
        //cin.clear();  
        //cin.ignore(); 
    }
    system("pause");
    return 0;
}
//机器评判通过

/*
//方法二：
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        int *arr = new int[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr + n);
        int mid = n >> 1;
        if (n & 1 == 1)
            cout << arr[mid] << endl;
        else
            cout << ((arr[mid - 1] + arr[mid]) >> 1) << endl;
        cin >> n;
    }
    system("pause");
    return 0;
}
*/