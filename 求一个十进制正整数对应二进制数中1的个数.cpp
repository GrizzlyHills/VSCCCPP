/* 给定一个十进制整数N，求其对应2进制数中1的个数*/
//这道题的解法就是反复地除以2，看最低位是1还是0。
//有些知道位运算的同学喜欢用位运算，但其实没必要，
//因为编译器优化之后的程序其实效率是一样的。
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int x, ans = 0;
        cin >> x;
        while (x > 0) {
            ans += x % 2;
            x /= 2;
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}