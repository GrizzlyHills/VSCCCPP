#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>


typedef enum
{ 
  GPIO_Speed_10MHz = 1,
  GPIO_Speed_2MHz, 
  GPIO_Speed_50MHz
}GPIOSpeed_TypeDef;

typedef enum
{ GPIO_Mode_AIN = 0x0,
  GPIO_Mode_IN_FLOATING = 0x04,
  GPIO_Mode_IPD = 0x28,
  GPIO_Mode_IPU = 0x48,
  GPIO_Mode_Out_OD = 0x14,
  GPIO_Mode_Out_PP = 0x10,
  GPIO_Mode_AF_OD = 0x1C,
  GPIO_Mode_AF_PP = 0x18
}GPIOMode_TypeDef;

typedef struct
{
  uint16_t GPIO_Pin;             /*!< Specifies the GPIO pins to be configured.
                                      This parameter can be any value of @ref GPIO_pins_define */

  GPIOSpeed_TypeDef GPIO_Speed;  /*!< Specifies the speed for the selected pins.
                                      This parameter can be a value of @ref GPIOSpeed_TypeDef */

  GPIOMode_TypeDef GPIO_Mode;    /*!< Specifies the operating mode for the selected pins.
                                      This parameter can be a value of @ref GPIOMode_TypeDef */
}GPIO_InitTypeDef;

// 计算将产生 6  作为骰子值的随机数生成函数所返回的最大数。
#define MAX_OK_RAND (int)((((long)RAND_MAX + 1) / 6) * 6 - 1)


// 宏的用法
#define DEBUG_PRINT(fmt, expr) \
        printf("File %s, line %d: %s = " fmt "\n", __FILE__, __LINE__, #expr, expr)


typedef enum {RESET = 0X11, SET = !RESET} FlagStatus, ITStatus;        


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

void CheckBit()
{
    int16_t flags = 0xffff;
    int16_t flags1 = 0xffff;
    uint16_t MASK = 0xffff;
    printf("flags = %d      MASK = %d\n", flags, MASK);
    if(flags == MASK)
        puts("WOW~ It's not a correct CheckBit skill.");   // 不能正常工作，其他位的值会导致毕竟站效果为假
    if((flags & MASK) == MASK)
        printf("(flags & MASK) = %d     (flags & flags1) = %d     WOW~ It's  a correct CheckBit skill.\n",
                 flags&MASK, flags&flags1);   // 消除了符号位的影响，因为 flags&MASK 的值按照 uint16 解析。同理可见int16与int16的与运算结果按照有符号位解析。
}

int main()
{
    struct tmmp {
        char a;
        int b;
        short c;
    } wmmp;
    printf("%d \n", sizeof(wmmp));

    char buf[33] = {0};
    int kind = 16;
    sprintf(buf, "%dK", kind);
    printf("%s\n", buf);

    CheckBit();     // 位运算中检查位的值的方法验证

    printf("RESET = %X      SET = %X\n\n", RESET, SET);

    GPIOSpeed_TypeDef s;
    GPIOMode_TypeDef m;
    GPIO_InitTypeDef io;
    printf("enum_GPIOSpeed 的长度：%d   enum_GPIOMode 的长度：%d   InitType 的长度：%d\n\n", sizeof(s), sizeof(m), sizeof(io));


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