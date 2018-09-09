/*
编程题＃6：流感传染

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，
房间里可能住人，也可能空着。在第一天，有些房间里的人得了流感，以后每天，
得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。请输出第m天得流感的人数。

输入
第一行一个数字n，n不超过100，表示有n*n的宿舍房间。
接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。
接下来的一行是一个整数m，m不超过100.

输出
输出第m天，得流感的人数

样例输入
5
....#
.#.@.
.#@..
#....
.....
4

样例输出
16
*/
#include<iostream>
using namespace std;
int main()
{
    char room[100][100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> room[i][j];
        }
    }
    int m;
    cin >> m;
    for (int k = 0; k < m - 1; k++) {     //注意 k < m -1 ,而不是 k < m
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (room[i][j] == '@') {
                    if (i != 0 && room[i - 1][j] != '#' && room[i - 1][j] != '@')//边界不进行运算，严格控制在输入区间内       //上
                        room[i - 1][j] = '$'; //这里用$标记待传染，因为遍历一遍之后才能够进行传染，否则会影响遍历结果，导致错误   
                    if (j != 0 && room[i][j - 1] != '#' && room[i][j - 1] != '@')                                          //左
                        room[i][j - 1] = '$'; 
                    if (j != (n - 1) && room[i][j + 1] != '#' && room[i][j + 1] != '@')                                    //右
                        room[i][j + 1] = '$';
                    if (i != (n - 1) && room[i + 1][j] != '#' && room[i + 1][j] != '@')                                    //下
                        room[i + 1][j] = '$';
                }
            }
        }
        for (int i = 0; i < n; i++) {//整个遍历之后，进行传染
            for (int j = 0; j < n; j++) {
                if (room[i][j] == '$')
                    room[i][j] = '@';
            }
        }//然后一天结束，跟天黑请闭眼一样。
    }
    int count = 0;//然后开始数数
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (room[i][j] == '@')
                count++;
        }
    }
    cout << count << endl;
    system("pause");
    return 0;
    
}
//机器评判通过