#include <iostream>
#include <iomanip>
using namespace::std;

int main(void)
{
    int all[10], odd[10], even[10]; //odd记录奇数，even记录偶数
    int i = 0, j = 0; //i,j为循环计数变量
    for(; i < 10; i++)
        cin >> all[i];
    int numOdd = 0;
    int numEven = 0; //numOdd,numEve分别记录奇数和偶数的个数
    for(i = 0; i < 10; i++)
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
    //输出奇数
    for(i = 0; i < numOdd; i++) {
        cout << setw(10) << odd[i];
    }
    cout << endl;
    //输出偶数
    for(i = 0; i < numEven; i++) {
        cout << setw(10) << even[i];
    }
    system("pause");
    return 0;
}