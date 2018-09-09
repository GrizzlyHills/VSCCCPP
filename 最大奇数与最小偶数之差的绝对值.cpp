/*
描述
输入6个正整数，且这6个正整数中至少存在一个奇数和一个偶数。
设这6个正整数中最大的奇数为a，最小的偶数为b，求出|a-b|的值

输入
输入为一行，6个正整数,且6个正整数都小于100
输入保证这6个数中至少存在一个奇数和一个偶数

输出
输出为一行，输出最大的奇数与最小的偶数之差的绝对值

样例输入
第一组
1 2 3 4 5 6
第二组
1 6 3 8 5 10

样例输出
第一组
3
第二组
1
*/
#include <iostream>
using namespace::std;

int main(void)
{
    int all[6], odd[6], even[6]; //odd记录奇数，even记录偶数
    int i = 0, j = 0; //i,j为循环计数变量
    for(; i < 6; i++)
        cin >> all[i];
    int numOdd = 0;
    int numEven = 0; //numOdd,numEve分别记录奇数和偶数的个数
    for(i = 0; i < 6; i++)
        if(all[i] % 2 != 0) { //当前数为奇数情况
            odd[numOdd] = all[i];
            numOdd++;
        } else { //当前数为偶数情况
            even[numEven] = all[i];
            numEven++;
        }
    //对odd选择排序
    for(i = 0; i < numOdd; i++) {
        for(j = i; j < numOdd; j++) {
            if(odd[j] > odd[i]){//设定排序方式
                //tmp为临时变量
                int tmp = odd[i];
                odd[i] = odd[j];
                odd[j] = tmp;
            }
        }
    }
    //对even选择排序
    for(i = 0; i < numEven; i++) {
        for(j = i; j < numEven; j++) {
            if(even[j] < even[i]){//设定排序方式
                //tmp为临时变量
                int tmp = even[i];
                even[i] = even[j];
                even[j] = tmp;
            }
        }
    }
    if(odd[0]>even[0])
        cout << odd[0]-even[0];
    else if(odd[0]<even[0])
        cout << even[0]-odd[0];
    else 
        cout << "0";
    system("pause");
    return 0;
}
//机器评判通过