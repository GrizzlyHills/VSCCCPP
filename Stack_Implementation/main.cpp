#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<string> test1;
    Stack<string> test2;
    string s[] = { " Hello ", " World ", " ! " };
    for (int i = 0; i < 3; i++) {
        test1.Push(s[i]);
    } 
    //test1.Peek(6);
    for (int i = 0; i < 3; i++) {
        string tmp = test1.Pop();
        cout <<  tmp;
        test2.Push(tmp);
    } 
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout <<  test2.Pop();
    }     
    system("pause");
    return 0;
}