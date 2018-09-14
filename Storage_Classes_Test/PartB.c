// partb.c -- rest of the program
// compile with parta.c
#include <stdio.h>
extern int count;       // reference declaration, external linkage
static int total = 0;   // static definition, internal linkage
void accumulate(int k); // prototype
void accumulate(int k)  // k has block scope, no linkage
{
    static int subtotal = 0; // static, no linkag
    if (k <= 0)
    {
        printf("loop cycle: %d\n", count);
        printf("subtotal: %d; total: %d\n", subtotal, total);
        subtotal = 0;   // 如果注释掉这一行，那么 subtotal 的作用和 total 的作用一样。这里只是体现了 块作用域的静态无链接变量 的作用
    }
    else
    {
        subtotal += k;
        total += k;
    }
}