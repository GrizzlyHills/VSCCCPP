/*
单词翻转

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
输入一个句子（一行），将句子中的每一个单词翻转后输出。

输入
只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。所谓单词指的是所有不包含空格的连续的字符。
这道题请用cin.getline输入一行后再逐个单词递归处理。

输出
翻转每一个单词后的字符串，单词之间的空格需与原文一致。

样例输入
hello    world.

样例输出
olleh    .dlrow
*/

//方法一
#include <iostream>
using namespace::std;
void revertWord(char *pStart, char *pEnd)
{
    char temp;
    for (; pStart < pEnd; pStart++, pEnd--) {
        temp = *pEnd;
        *pEnd = *pStart;
        *pStart = temp;
    }
}

void revert(char *p) 
{
    char *p1;
    while (*p && *p == ' ')
        p++;
    if (!*p)
        return;
    p1 = p;
    while (*p && *p != ' ')
        p++;
    revertWord(p1, p - 1);
    revert(p);
}

int main() 
{
    char str[500] = {0};
    cin.getline(str,500);
    revert(str);
    cout << str << endl;
    system("pause");
    return 0;
}
//机器评判通过
