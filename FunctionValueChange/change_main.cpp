
/*
问题：change.h可以用
      改成chang.c编译报错    "undefined reference to `change(int, int)'"
*/
#include <iostream>
//#include "change.h"
using namespace::std;
void change(int,int);
int main()
{
    int a = 3,b = 5;
    change(a,b);
    cout << a << " " << b << endl;
    system("pause");
    return 0;
}