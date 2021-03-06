/*
描述
某医院想统计一下某项疾病的获得与否与年龄是否有关，需要对以前的诊断记录进行整理。

输入
共2行，第一行为过往病人的数目n（0 < n <= 100)，第二行为每个病人患病时的年龄。

输出
每个年龄段（分四段：18以下，19-35，36-60，大于60注意看样例输出的格式）的患病人数占总患病人数的比例，
以百分比的形式输出，精确到小数点后两位（double）。
关于c++的格式化的输入输出，请参考：http://www.cplusplus.com/reference/iomanip。
也可以在网上搜索一下，资料很多的。

样例输入
10
1 11 21 31 41 51 61 71 81 91

样例输出
1-18: 20.00%
19-35: 20.00%
36-60: 20.00%
60-: 40.00%

提示
注意最后一行的输出是“60-: ”，而不是“61-: ”。
每个冒号之后有一个空格。
输出可以用 cout<<fixed<<setprecision(2) << f; 来保留f后面的两位小数。
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n],i;
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    int ratio_1_18 = 0,
        ratio_19_35 = 0,
        ratio_36_60 = 0,
        ratio_60plus = 0;
    for(i=0;i<n;i++){
        if(arr[i] < 19)
            ratio_1_18++;
        else if(arr[i] >= 19 && arr[i] < 36)
            ratio_19_35++;
        else if(arr[i] >= 36 && arr[i] <= 60)
            ratio_36_60++;
        else if(arr[i] >= 60)
            ratio_60plus++;
    }
    cout << fixed << setprecision(2) 
         << "1-18: " << ratio_1_18*100.0/n << "%"
         << "\n19-35: " << ratio_19_35*100.0/n << "%"
         << "\n36-60: " << ratio_36_60*100.0/n << "%"
         << "\n60-: " << ratio_60plus*100.0/n << "%"
         << endl;
    system("pause");
    return 0;
}
//机器评判通过gcc