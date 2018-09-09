/*
描述
在一个字符串中找出元音字母a,e,i,o,u出现的次数。

输入
输入一行字符串（字符串中可能有空格，请用cin.getline(s,counts)方法把一行字符串输入到字符数组s中，
其中counts是s的最大长度，这道题里面可以直接写80。），字符串长度小于80个字符。

输出
输出一行，依次输出a,e,i,o,u在输入字符串中出现的次数，整数之间用空格分隔。

样例输入
If so, you already have a Google Account. You can sign in on the right.

样例输出
5 4 3 7 3

提示
注意，只统计小写元音字母a,e,i,o,u出现的次数。
*/
#include <iostream>
using namespace::std;

int main(void)
{
    char s[80]; 
    cin.getline(s,80);
    int arr[5] = {0},i = 0;
    while(s[i] != '\0'){
        switch(s[i]){
            case 'a':
                arr[0]++;
                break;
            case 'e':
                arr[1]++;
                break;
            case 'i':
                arr[2]++;
                break;
            case 'o':
                arr[3]++;
                break;
            case 'u':
                arr[4]++;
                break;
            default:
                NULL;
        }
        i++;
    }
    for(i=0;i<5;i++)
        cout << arr[i] << " ";
    system("pause");
    return 0;
}
//机器评判通过