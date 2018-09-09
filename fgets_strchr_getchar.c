/*
 * @Author: GrizzlyHills 
 * @Date: 2018-07-12 20:16:31 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2018-07-12 21:20:34
 */
//探讨一下几个输入流函数的用法

#include <stdio.h>
#include <string.h>

#define LEN 30

char *s_gets(char *str, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(str, n, stdin);
    if(ret_val)
    {
        find = strchr(str, '\n');        //查找 换行符, 回车键对应了'\n'
        if(find)                        //如果地址不是 NULL
        {
            *find = '\0';               //在此处放置一个空字符
        } else {
            while(getchar() != '\0')
                continue;               //清理输入行
        }
    }
    return ret_val;
}


int main()
{
    char string[LEN];
    puts(s_gets(string, LEN));          //打印输入行
    getchar();
    return 0;
}