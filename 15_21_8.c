/* 问题：
** 编写一个程序，产生一个文件的十六进制转储机器码。它应该从命令行接受单个参数，也就是需要进行转储的文件名。
** 如果命令行中未给出参数，程序就打印标准输入的转储码。
** 每行转储码都应该具有如下格式：
** P324
** 所有的十六进制数都应该使用大写的 A-F。下面是一些样例格式：
** 000200 D4O5C000 82102004 91D02000 9010207F *...... ... ... .*
** 000210 82102001 91D02000 0001C000 2F757372 *.. ... ...../usr*
** 000220 2F6C6962 2F6C642E 736F002F 6465762F * /lib/ld.so./dev/*
*/

/* 解答思路：
** While not explicitly specified in the problem statement, an important consideration is what to do
** when the file being dumped does not contain an even multiple of 16 bytes. A simplistic approach
** is to simply report the missing bytes as zero. The solution below constructs each output line in 
** a buffer in memory; this makes it easier to print only the data that appears in a partial last line
** while still maintaining the proper format. The program would be easier to modify when someone
** comes along and wants the format changed (as is inevitable) had defined names been used for the 
** numbers related to the format rather than literal constants.
** 虽然未在问题陈述中明确指定，但重要的考虑因素是当转储的文件不包含16个字节的偶数倍时该怎么办。
** 一种简单的方法是简单地将丢失的字节报告为零。下面的解决方案在内存中的缓冲区中构造每个输出行;
** 这样可以更轻松地仅打印部分最后一行中显示的数据，同时仍保持正确的格式。当有人出现并希望格式改变（不可避免）时，
** 程序将更容易修改已定义的名称已被用于与格式相关的数字而不是文字常量。
*/
/*
** Print an hexadecimal dump of the specified file.  If no filename argument is
** given, print a dump of the standard input instead.
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#define BUFFER_SIZE 64
/*
**      Function to dump the contents of a stream.
*/
void dump(FILE *stream)
{
    long offset;
    unsigned char data[16];
    int len;
    char buffer[BUFFER_SIZE];
/*
** Initialize the buffer that will be used for output.
*/
    memset(buffer, ' ', BUFFER_SIZE - 1);   // #include <memory.h>
    buffer[45] = '*';
    buffer[62] = '*';
    buffer[BUFFER_SIZE-1] ='\0';
    offset = 0;
    while ((len = fread(data, 1, 16, stream)) > 0)
    {
        char *hex_ptr;
        char *char_ptr;
        int i;
/*
** Start building the output buffer with the offset.
*/
        sprintf(buffer, "%06X  ", offset);
/*
** Prepare pointers to the hex and character portions of the
** buffer and initialize them to spaces.
*/
        hex_ptr = buffer + 8;
        char_ptr = buffer + 46;
        memset(hex_ptr, ' ', 35);
        memset(char_ptr, ' ', 16);
/*
** Now translate the data to both of the output forms and store
** it in the buffer.
*/
        for (i = 0; i < len; i += 1)    // 每次处理一个字符，很关键
        {
/*
** Convert the next character to hex.  Must overwrite
** the NUL that sprintf inserts with a space.
*/
            sprintf(hex_ptr, "%02X", data[i]);
            hex_ptr += 2;
            *hex_ptr = ' ';     // 很关键，NULL 用空格取代
/*
** Leave a space between each group of 4 values in the
** hex portion of the line.
*/
            if (i % 4 == 3)
                hex_ptr++;
/*
** If the character is printable, put it in the char
** portion of the line, else put a dot in.
*/
            if (isprint(data[i]) || data[i] == ' ')     // #include <ctype.h>
                *char_ptr++ = data[i];
            else
                *char_ptr++ = '.';
        }
/*
** Print the line and then update the offset for the next time
** through the loop.
*/
        puts(buffer);
        offset += len;
    }
}
/*
**      Main program.  Dump the file (if there is an argument) or stdin.
*/
int main(int ac, char **av)
{
    printf("字符集测试是否在 UTF-8 编码格式下正确显示中文。");
    if (ac <= 1)
        dump(stdin);
    else
    {
        FILE *stream;
        stream = fopen(av[1], "rb");
        if (stream == NULL)
        {
            perror(av[1]);
            exit(EXIT_FAILURE);
        }
        dump(stream);
        fclose(stream);
    }
    getchar();
    return EXIT_SUCCESS;
}