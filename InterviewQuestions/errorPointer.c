#include <stdio.h>

void swap(int *p1, int *p2)
{
    int tmp;
    int *p = &tmp;
    *p = *p1;
    *p1 = *p2;
    *p2 = *p1;
}

int main()
{
    int m = 1;
    int n = 2;
    swap(&m, &n);
    printf("m = %d\n", m);
    getchar();
    return 0;
}