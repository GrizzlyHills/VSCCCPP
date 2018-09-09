#include <stdio.h>

long InSum(int a[], int n, int i, int m)
{
    long count;
    count = 0;
    int j, flag;
    flag = i;
    if(n < 0 || i < 0 || m <= 0 || (i > n - 1)) {
        printf("元素数量或下标错误，返回错误标记值 -666");
        return -666;
    } else {
        if(m + i <= n) {
            for(j = 0; j < m; j++) {
                count += a[i++];
            } 
        } else {
            for(j = 0; j < n - flag; j++) {
                count += a[i++];
            }
        }
        return count;
    }
}

int main()
{
    int a[8] = {-8, -2, 5, 9, 15, 32};
    printf("%ld\n", InSum(a, 6, 3, 2));
    getchar();
    return 0;
}