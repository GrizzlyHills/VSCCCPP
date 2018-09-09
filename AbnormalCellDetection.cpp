/*
描述
我们拍摄的一张CT照片用一个二维数组来存储，假设数组中的每个点代表一个细胞。
每个细胞的颜色用0到255之间（包括0和255）的一个整数表示。
我们定义一个细胞是异常细胞，如果这个细胞的颜色值比它上下左右4个细胞的颜色值都小50以上（包括50）。
数组边缘上的细胞我们不检测。现在我们的任务是，给定一个存储CT照片的二维数组，写程序统计照片中异常细胞的数目。

输入
第一行包含一个整数N（100>=N>2）.
下面有 N 行，每行有 N 个0~255之间的整数，整数之间用空格隔开。

输出
输出只有一行，包含一个整数，为异常细胞的数目。

样例输入
4
70 70 70 70
70 10 70 70
70 70 20 70
70 70 70 70

样例输出
2
*/
#include <iostream>
#include <iomanip>
using namespace ::std;

int main(void)
{
    int N, count = 0;
    cin >> N;
    int arr[N][N] = {0};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < N - 1; j++)
        {
            if (arr[i - 1][j] - arr[i][j] >= 50 
                && arr[i + 1][j] - arr[i][j] >= 50 
                && arr[i][j - 1] - arr[i][j] >= 50 
                && arr[i][j + 1] - arr[i][j] >= 50)
            {
                count++;
            }
        }
    }
    cout << count;
    system("pause");
    return 0;
}
//机器评判通过