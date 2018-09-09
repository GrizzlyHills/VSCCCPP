/*
描述
从键盘输入一个任意的三位整数，要求正确地分离出它的百位、十位和个位数，
并分别在屏幕上输出，输出采用每行输出一个数的方式，不带其它符号。

输入
一个任意的三位整数

输出
一个任意的三位整数

样例输入
123

样例输出
1
2
3
*/
#include <iostream>
using namespace::std;

int main(void)
{
    int n,Digits,DigitsTen,DigitsHundred;
    cin >> n;
    if(n > 0){
        if(n/100 > 0){
            DigitsHundred = n/100;
            DigitsTen = n/10%10;
            Digits = n%100%10;
        }else if(n/10 > 0){
            DigitsHundred = 0;
            DigitsTen = n/10;
            Digits = n%10;            
        }else{
            DigitsHundred = 0;
            DigitsTen = 0;
            Digits = n;            
        }
    }else if(n == 0){
        DigitsHundred = 0;
        DigitsTen = 0;
        Digits = 0;
    }else{
        n = -1 * n;
        if(n/100 > 0){
            DigitsHundred = n/100;
            DigitsTen = n/10%10;
            Digits = n%100%10;
        }else if(n/10 > 0){
            DigitsHundred = 0;
            DigitsTen = n/10;
            Digits = n%10;            
        }else{
            DigitsHundred = 0;
            DigitsTen = 0;
            Digits = n;            
        }
    }
    cout << DigitsHundred << endl;
    cout << DigitsTen << endl;
    cout << Digits << endl;
    system("pause");
    return 0;
}
//机器评判通过