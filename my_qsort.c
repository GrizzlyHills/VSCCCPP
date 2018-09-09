/*
** Sort an array of arbitrary fixed–length elements.  The caller passes a
** pointer to a function which compares two elements.
*/

#include <stdio.h>


char arr[50] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
/*
**      Exchange two elements with each other.
*/
void swap(char *i, char *j, int recsize)
{
    char x;
    while (recsize-- > 0)
    {
        x = *i;
        *i++ = *j;
        *j++ = x;
    }
}

/*
**      比较函数：只比较关键字的值
*/
int comp(void const *a, void const *b)
{
    //printf("\t%d", (char *)a - (char *)b);
    return (*(char *)a - *(char *)b);
}

/*
**      Sort the array.
*/
void sort(char *base, int nel, int recsize, int (*comp)(void const *, void const *))
{
    register char *i;
    register char *j;
    register char *last;
    last = base + (nel - 1) * recsize;
    for (i = base; i < last; i += recsize)
        for (j = i + recsize; j <= last; j += recsize)
            if (comp(i, j) < 0)
                swap(i, j, recsize);
}

void PrintArr(char arr[])
{
    int i;
    for(i = 0; i < 50; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    //char arr[50] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printf("Before Sorting: ");
    PrintArr(arr);
    sort(&arr[0], 50, sizeof(arr[0]), comp);
    printf("After Sorting: ");
    PrintArr(arr);
    getchar();
    return 0;
}