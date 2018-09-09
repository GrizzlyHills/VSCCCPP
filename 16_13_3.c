/*  问题：
**  以小孩的方式来说明当前的时间（例如，时针在 6 上面，分针在 12 上面）
**  The biggest problem with this is the rounding required to 
**  show which number the hour hand is actually closer to.
*/

/*
** Give the current time as a young child would.
*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    time_t now;
    struct tm *tm;
    int hour;
    int minute;
/*
** Get current hour and minute.
*/
    now = time(NULL);
    tm = localtime(&now);
    hour = tm->tm_hour;
    minute = tm->tm_min;
    printf("HOUR: %d    MINUTES: %d\n", hour, minute);
/*
** Round and normalize the hour, convert the minute, and then print them.
*/
    if (minute >= 30)   // 分针 30 进， 时针跳一格 1 小时
        hour += 1;
    hour %= 12;
    if (hour == 0)
        hour = 12;
    minute += 2;        // 分针 3 进 2 退，分针跳一格 5 分钟
    minute /= 5;
    if (minute == 0)
        minute = 12;
    printf("The little hand is on the %d, and the big hand is on the %d.\n", hour, minute);
    getchar();
    return EXIT_SUCCESS;
}