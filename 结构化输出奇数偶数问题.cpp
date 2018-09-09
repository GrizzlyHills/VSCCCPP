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
    for(i = 0; i < numOdd; i++) //输出奇数
        cout << setw(10) << odd[i];
    cout << endl;
    for(i = 0; i < numEven; i++) //输出偶数
        cout << setw(10) << even[i];
    system("pause");
    return 0;
}