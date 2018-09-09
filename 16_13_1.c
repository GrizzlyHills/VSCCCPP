/*  问题：
**  计算机人群中颇为流行的一个笑话是“我29岁，但我不告诉你这个数字的基数！”如果基数是16，这个人实际上是41岁。
**  编写一个程序，接受一个年龄作为命令行参数，并在2~36的范围计算那个字面值小于等于29的最小基数。例如，如果
**  用户输入41，程序应该计算出这个最小基数为16.因为在16进制中，十进制41的值是29。
*/
/*  思路：
**  This program makes use of the div function to obtain both the quotient and remainder from an
**  integer division.   On machines without hardware instructions to do integer division, this will 
**  be considerably faster than doing a / and a % operation.
**  For a given input age, compute the smallest radix in the range 2–36 for which the age appears 
**  as a number less than or equal to 29.
*/

#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
    int age;
    int radix;
    div_t result;
    if (ac != 2)
    {
        fputs("Usage: age_radix your–age\n", stderr);
        exit(EXIT_FAILURE);
    }
/*
** Get the age argument.
*/
    age = atoi(av[1]);
/*
** Find the smallest radix that does the job.
*/
    for (radix = 2; radix <= 36; radix += 1)
    {
        result = div(age, radix);
        if (result.quot <= 2 && result.rem <= 9)
            break;
    }
/*
** Print the results.
*/
    if (radix <= 36)
    {
        printf("你好世界！ Use radix %d when telling your age; "
               "%d in base %d is %d%d\n",
               radix, age, radix, result.quot, result.rem);
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Sorry, even in base 36 your age "
               "is greater than 29!\n");
        return EXIT_FAILURE;
    }
    getchar();
    return 0;
}