
/*
C有一个鲜为人知的运算符叫”趋向于”， 写作“-->”。
比如说如果要实现一个倒数的程序，我们可以定义一个变量x，然后让它趋向与0：



被骗了  被骗了  被骗了   不过是自减和大于运算符而已哟~
*/


#include <stdio.h>
int main(int argc, char** argv) {
  int x = 10;
  while (x --> 0) {
    printf("%d\n", x);
  }
  getchar();
  return 0;
}