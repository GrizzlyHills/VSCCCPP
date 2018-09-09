#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    //打印参数，直到遇到NULL指针（未使用argc）。程序名被跳过。
    char temp[50] = {0};
    int i = 0;
    // while(*++argv != NULL) {
    // while(strcpy(temp, *argv++) && temp != NULL) {    // 会报 segment default
    // while(*argv != NULL) {           // 会报 segment default
    //     puts(argv[i]);
    //     i++;
    // }
    for(i = 0; i < argc; i++)           //正常
        puts(argv[i]);
    return 0;
} 