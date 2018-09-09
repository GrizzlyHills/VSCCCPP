/*
编程题＃1：计算矩阵边缘元素之和

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
输入一个整数矩阵，计算位于矩阵边缘的元素之和。所谓矩阵边缘的元素，就是第一行和最后一行的元素以及第一列和最后一列的元素。

输入
第一行为整数k，表示有k组数据。
每组数据有多行组成，表示一个矩阵：
第一行分别为矩阵的行数m和列数n（m < 100，n < 100），两者之间以空格分隔。
接下来输入的m行数据中，每行包含n个整数，整数之间以空格作为间隔。

输出
输出对应矩阵的边缘元素和，一个一行。

样例输入
2
4 4
1 1 1 1
0 0 0 0
1 0 1 0
0 0 0 0
3 3
3 4 1
3 7 1
2 0 1

样例输出
5
15
*/
/*
#include <iostream>
using namespace::std;

int main()
{ 
    int k,m,n,sum;
    int arr[99][99];
    cin >> k;
    for(int i = 0;i < k;i++){
        sum = 0;
        cin >> m >> n;
        if(m >= 100 || n >= 100)
            return 0;
        for(int j = 0;j < m;j++)
            for(int k = 0;k < n;k++){
                cin >> arr[j][k]; 
            }
        for(int i = 0;i < m;i++){    //计算列
            sum += arr[i][0];
            sum += arr[i][m - 1];
        }
        for(int i = 1;i < n - 1;i++){ //计算行
            sum += arr[0][i];
            sum += arr[n - 1][i];
        }
        cout << sum << endl;
    }
    system("pause");
    return 0;
} //机器不通过，本地通过
*/

#include<iostream>  
using namespace std;  
int main() {  
    int t;  
    cin >> t;  
    for (int i = 0; i < t; i++) {  
        int m = 0, n = 0;  
        cin >> m >> n;  
        int shuzu[100][100];//矩阵最大100*100  
        int sum = 0;  
        for (int j = 0; j < m; j++) {  
            for (int o = 0; o < n; o++) {  
                cin >> shuzu[j][o];//输入数组数值  
                //下面是精髓,在存储的同时判断并计算，自己并没有充分理解    else if
                if (j == 0 || j == m - 1)//先算首行，末行  
                    sum += shuzu[j][o];  
                else if(o==0||o==n-1)//else 之后再用if 找除了四个角落之外的首列，末列  
                    sum += shuzu[j][o];  
            }  
        }  
        cout << sum << endl;  
    }  
    system("pause");
    return 0;  
}  //机器通过
