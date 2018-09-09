/* 
** Line-oriented input processing with sscanf 
** 使用 sscanf 处理定向的输入
*/
#include <stdio.h>
#define BUFFER_SIZE 100
/* Longest line we'll handle */
void function(FILE *input)
{
    int a, b, c, d, e;
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, input) != NULL)
    {
        if (sscanf(buffer, "%d %d %d %d %d", &a, &b, &c, &d, &e) != 5)
        {
            fprintf(stderr, "Bad input skipped: %s", buffer);
            continue;
        }
        /*      
            ** Process this set of input. 
            */
        printf("%d", a + b + c + d + e); //还是很好用的
    }
}

int main(void)
{
    function(stdin); //从标准输入读取并处理
    getchar();
    return 0;
}