/*
** Return the largest value from the argument list.  The list is terminated by a
** negative value.
*/
#include <stdio.h>
#include <stdarg.h>

int max_list(int first_arg, ...)
{
    va_list var_arg;
    int max = 0;
    /*
** Get the first arg if there is one and save it as the max.
*/
    if (first_arg >= 0)
    {
        int this_arg;
        max = first_arg;
        /*
** Get the remaining arguments and save each one if it is
** greater than the current max.
*/
        va_start(var_arg, first_arg);
        while ((this_arg = va_arg(var_arg, int)) >= 0)
        //while ((this_arg = va_arg(var_arg, int)) > -2)    //卡的条件不对 停不下来
            if (this_arg > max)
                max = this_arg;
        va_end(var_arg);
    }
    return max;
}

int main()
{
    printf("The max value is %d", max_list(1, 2, 3, 4, 5, -1, 6));
    getchar();
    return 0;
}