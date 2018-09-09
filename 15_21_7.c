/* 问题：
** Compute the average age of family members.  Each line of input is for one
** family; it contains the ages of all family members.
** 某个数据文件包含了家庭成员的年龄。一个家庭各个成员的年龄都位于同一行，由空格分隔。数据类型如下所示：
**        45 42 22
**        36 35 7 3 1
**        22 20
** 描述了三个家庭的所有成员的年龄，他们分别有 3、5、2 个成员。
** 编写一个程序，计算用这种文件表述的家庭成员的平均年龄。程序使用格式代码 %5.2f 打印出平均年龄，后面
** 一个冒号和输入数据。假定每个家庭的成员数量都不超过 10 个。    
*/

/* 解答思路：
** The limitation to at most 10 members makes it possible (if tedious) to do this with fgets
** and sscanf. Assuming a maximum of three digits (plus one separating space) per age, a buffer of 
** 40 characters would be adequate. However, the problem specification does not say that the ages 
** will be separated by exactly one whitespace character, so this solution uses a buffer of 512 
** characters instead. If you know something about the nature of the input (e.g., it was created 
** with an editor whose maximum line size is 512 bytes), then this approach is fine. Otherwise, 
** it is risky and you should dynamically allocate a buffer that can be extended whenever a line 
** is found that is too long.
** 对最多10个成员的限制使得用fgets和sscanf做到这一点成为可能（如果单调乏味）。假设每个年龄最多
** 三个数字（加一个分隔空间），40个字符的缓冲区就足够了。但是，问题规范并未说明年龄将仅由一个空格字符分隔，
** 因此此解决方案使用512的缓冲区而不是字符。如果您对输入的性质有所了解（例如，它是使用最大行大小为512字节
** 的编辑器创建的），那么这种方法很好。否则，它是有风险的，你应该动态分配一个缓冲区，只要找到一条太长的行，
** 就可以扩展它。
*/

/*
** Compute the average age of family members.  Each line of input is for one
** family; it contains the ages of all family members.
*/
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512 /* size of input buffer */
int main()
{
    char buffer[BUFFER_SIZE];
/*
** Get the input one line at a time.
*/
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL)
    {
        int age[10];
        int members;
        int sum;
        int i;
/*
** Decode the ages, remembering how many there were.
*/
        members = sscanf(buffer, "%d %d %d %d %d %d %d %d %d %d",
                         age, age + 1, age + 2, age + 3, age + 4, age + 5, age + 6,
                         age + 7, age + 8, age + 9);
        if (members == 0)
            continue;
/*
** Compute the average and print the results.
*/
        sum = 0;
        for (i = 0; i < members; i += 1)
            sum += age[i];
        printf("%5.2f: %s", (double)sum / members, buffer);
    }
    getchar();
    return 0;
}