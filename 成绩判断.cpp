/*
描述
输入一个0--100的分数，判断分数代表什么等级。
95<=分数<=100, 输出1
90<=分数<95,输出2
85<=分数<90,输出3
80<=分数<85,输出4
70<=分数<80,输出5
60<=分数<70输出6
分数 < 60;输出7.

输入
n

输出
m

样例输入
87

样例输出
3
*/
#include<iostream>
using namespace std;

int main() {
    int n;
    if(cin>>n && n>=95 && n<=100)
        cout<<"1";
    else if(n>=90 && n<95)
        cout<<"2";
    else if(n>=85 && n<90)
        cout<<"3";
    else if(n>=80 && n<85)
        cout<<"4";
    else if(n>=70 && n<80)
        cout<<"5";
    else if(n>=60 && n<70)
        cout<<"6";
    else 
        cout<<"7";    
    system("pause");
    return 0;
}
//机器评判通过