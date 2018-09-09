/*
作者：喻时耕宇
链接：https://zhuanlan.zhihu.com/p/27519218
来源：知乎
著作权归作者所有，转载请联系作者获得授权。
*/

#include <stdio.h>
static const unsigned char a[] = {
#include "values.txt"
};

int main(int argc, char *argv[])
{
    int i;
    for (i = 0; i < sizeof(a); ++i)
        printf("a[%d] = %d\n", i, a[i]);
    getchar();
    return 0;
}

/*
values.txt
1,2,3,4,5,
6,7,8,9,0,
*/
