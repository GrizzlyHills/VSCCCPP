/*
描述
某校大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是1米。
我们可以把马路看成一个数轴，马路的一端在数轴0的位置，另一端在L的位置；
数轴上的每个整数点，即0，1，2，……，L，都种有一棵树。
马路上有一些区域要用来建地铁，这些区域用它们在数轴上的起始点和终止点表示。
已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。
现在要把这些区域中的树（包括区域端点处的两棵树）移走。
你的任务是计算将这些树都移走后，马路上还有多少棵树。

输入
输入的第一行有两个整数L（1 <= L <= 10000）和 M（1 <= M <= 100），
L代表马路的长度，M代表区域的数目，L和M之间用一个空格隔开。
接下来的M行每行包含两个不同的整数，用一个空格隔开，表示一个区域的起始点和终止点的坐标。

输出
输出包括一行，这一行只包含一个整数，表示马路上剩余的树的数目。

样例输入
第一组
500 3
150 300
100 200
470 471
第二组
500 3
100 200
150 160
180 190

样例输出
第一组
298
第二组
400

提示
由于数据范围不大（L<=10000），我们可以使用一个10001长度的数组来记录每一个坐标上有没有树。
但想象一下如果数据范围很大，比如下面这个情况，你怎么办呢？

输入
5000000 3
1500000 3000000
1000000 2000000
4700000 4700001

输出
2999998
*/
#include <iostream>
#include <iomanip>
using namespace ::std;

int main(void)
{
    int L,M;
    cin >> L >> M;
    int arr[M][2]={0},flag[L+1]={0};
    for(int i=0;i<M;i++){
        for(int j=0;j<2;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<M;i++){
        for(int j = arr[i][0];j<=arr[i][1];j++)
            flag[j] = 1;
    }
    int count=0;
    for(int i=0;i<=L;i++){
        if(flag[i]==0)
            count++;
    }
    cout << count;
    system("pause");
    return 0;
}
//机器评判通过