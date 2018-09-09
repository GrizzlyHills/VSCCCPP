#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

// 计算将产生 6  作为骰子值的随机数生成函数所返回的最大数。
#define MAX_OK_RAND (int)((((long)RAND_MAX + 1) / 6) * 6 - 1)


// 宏的用法
#define DEBUG_PRINT(fmt, expr) \
        printf("File %s, line %d: %s = " fmt "\n", __FILE__, __LINE__, #expr, expr)


#define SUM(value) ((value) + (value))

#define SIZE 1

struct NODE
{
    int a;
    struct NODE *b;
    struct NODE *c;
};

void PrintStr(char const *s)
{
    printf("%s", s);
}
int main()
{

    printf("long long 的长度：%d\n\n", sizeof(long long));
    int *ip;
    // *ip = 666;              // segmentation fault, 应该是没有为 int 指针分配空间的缘故。
    
    ip = (int *)malloc(sizeof(int));
    *ip = 666; 
    printf("%X %d\n", ip, *ip);
    free(ip);
    printf("%X %d\n", ip, *ip);     // 地址还是那个地址，但内容已经不是那个内容了

    printf("MAX_OK_RAND = %d\n", MAX_OK_RAND);      // 32765

    int j;
    for(j = 0; j < 200; j++) {
        printf("%d", rand() % 2);
    }
    printf("\n");

    // the C locale will be UTF-8 enabled English;
    // decimal dot will be German
    // date and time formatting will be Japanese
    setlocale(LC_ALL, "en_US.UTF-8");
    setlocale(LC_NUMERIC, "de_DE");
    setlocale(LC_TIME, "ja_JP");
    wchar_t str[100];
    time_t t = time(NULL);
    wcsftime(str, 100, L"%A %c", localtime(&t));
    wprintf(L"Number: %.2f\nDate: %Ls\n", 3.14, str);

    char const *str1 = "hello";
    char const str2[] = "hello";
    printf("你好世界！  %d %d %d %d\n", sizeof(str1), sizeof(str2), strlen(str1), strlen(str2));   
    // 8 6 5 5, str1是指针长度，不是字符串常量的长度。 strlen 计算的长度没有加上 NULL 这个字符。


    char *env_p = getenv("PATH");       // #include <stdlib.h>
    if (env_p)
        printf("PATH = %s\n", env_p);

    time_t result = time(NULL);
    if(result != -1)
        printf("The current time is %s(%u seconds since the Epoch)\n",
               asctime(gmtime(&result)), (uintmax_t)result);        // #include <stdint.h>
    printf("UTC:   %s", asctime(gmtime(&result)));
    printf("local: %s", asctime(localtime(&result)));

    int array[SIZE] = {0};
    int sum = 0, i = 0;
    while(i < SIZE) {
        sum += SUM(array[i++]);
    }
    printf("%d \n", sum);
    



    int x = 1, y = 2;
    DEBUG_PRINT("%d", x * y + 3);       //可以


    int tmp = 0Xffffffaa;
    printf("%X %X \n", tmp, !tmp);
    enum TYPE {INT, FLOAT, STRING};
    enum TYPE type;
    for(int type = INT; type <= STRING; type++)             // 注意  type 前面要加上 int 来声明才有效
        printf("%d\n", type);

    if (type == STRING)
        printf("It's OK!\n");

    printf("%d\n\n", sizeof(struct NODE));
    PrintStr("abc");        //事实证明可以直接传递字符串到子函数的形参

    char input[] = "A bird came down the walk";
    printf("Parsing the input string '%s'\n", input);
    char *token = strtok(input, " ");       //为什么第一个搜索到的字符串标记是 A 呢？貌似规定就是如此？
    while(token) {
        puts(token);
        token = strtok(NULL, " ");
    }

    char input1[] = "A bird came down the walk";
    for(token = strtok( input1, " " );      //此方法获得的结果同上面的一致
        token != NULL; 
        token = strtok( NULL, " " )) 
        printf( "Next token is %s\n", token );

    getchar();
    return 0;
}