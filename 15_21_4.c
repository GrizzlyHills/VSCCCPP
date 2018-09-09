/*
** This program reads two file names and then copies data from the input file
** to the output file one line at a time.
** 提示用户输入两个文件名，并从标准输入读取它们。第 1 个作为输入文件，第 2 个作为输出文件。
** 这个程序应该打开这两个文件并把输入文件的内容按照前面的方式复制到输出文件。
*/
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 256 /* I/O buffer size */
/*
**      This function prompts for a filename, reads the name, and then tries to
**      open the file.  Any errors encountered are reported before the program
**      terminates.  Note that the gets function strips the trailing newline off
**      of the file name so we don’t have to do it ourselves.
*/
FILE *openfile(char const *prompt, char const *mode)
{
    char buf[BUFSIZE];
    FILE *file;
    printf("%s filename? ", prompt);
    if (gets(buf) == NULL)
    {
        fprintf(stderr, "Missing %s file name.\n", prompt);
        exit(EXIT_FAILURE);
    }
    if ((file = fopen(buf, mode)) == NULL)
    {
        perror(buf);
        exit(EXIT_FAILURE);
    }
    return file;
}
/*
**      Main function.
*/
int main()
{
    char buf[BUFSIZE];
    int value, total = 0;
    FILE *input;
    FILE *output;
    // FILE *openfile(char const *, char const *);     // p264 中说了要确保函数原型出现在函数指针调用前，
    //                                                 // 不过好像屏蔽了也没有关系
    input = openfile("Input", "r");
    // output = openfile("Output", "w");                //更改输出流添加模式会在结尾更新
    output = openfile("Output", "a");
    while (fgets(buf, BUFSIZE, input) != NULL) {
        if(sscanf(buf, "%d", &value) == 1)
            total += value;
        fputs(buf, output);     // 值得注意的是，output 文件中的内容每次会被刷新，从头复制了 input 文件的内容
    }
    fprintf(output, "\ntoalt = %d\n", total);
        
    fclose(input);
    fclose(output);
    getchar();
    return EXIT_SUCCESS;
}