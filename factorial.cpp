/*
 * @Author: GrizzlyHills 
 * @Date: 2017-10-11 21:09:14 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-10-11 21:17:03
 */

#include <iostream>
using namespace::std;

// 递归计算阶乘
int factorial(int n)
{
    return n==1  ? 1 : (n * factorial( n-1 ));
}

int main()
{
    cout << factorial(10) << endl;
    system("pause");
    return 0;
}

