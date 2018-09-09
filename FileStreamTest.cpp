
// Mode(方式) 意义 
// "r" 打开一个用于读取的文本文件 
// "w" 创建一个用于写入的文本文件 
// "a" 附加到一个文本文件 
// "rb" 打开一个用于读取的二进制文件 
// "wb" 创建一个用于写入的二进制文件 
// "ab" 附加到一个二进制文件 
// "r+" 打开一个用于读/写的文本文件 
// "w+" 创建一个用于读/写的文本文件 
// "a+" 打开一个用于读/写的文本文件 
// "rb+" 打开一个用于读/写的二进制文件 
// "wb+" 创建一个用于读/写的二进制文件 
// "ab+" 打开一个用于读/写的二进制文件 

// FILE *fopen( const char *fname, const char *mode );
// fopen()函数打开由fname(文件名)指定的文件, 并返回一个关联该文件的流.如果发生错误, fopen()返回NULL. mode(方式)是用于决定文件的用途(例如 用于输入,输出,等等) 

//  FILE *freopen( const char *fname, const char *mode, FILE *stream );
//  freopen()函数常用于再分配一个以存在的流给一个不同的文件和方式(mode).
//  在调用本函数后,给出的文件流将会用mode(方式)指定的访问模式引用fname(文件名). freopen()的返回值是新的文件流,发生错误时返回NULL. 

/*
C语言中freopen()函数是用来重新定向的，所谓重新定向是给输入和输出的位置重新定向。
原本输入位置是键盘缓存区，输出在屏幕上，用了重新定向后可以将输入位置改变成一个
文件，而输出位置也可以输出到一个文件中，具体代码可以这么写：

freopen ("text.txt","r",stdin);  freopen ("text1.txt","w",stdout);
这里输入和输出便都在文件中操作了。可是这样做有一个弊端，就是所有输入输出都将在文
件中操作，如何灵活控制呢？这就要用到fopen()函数了，可以自由在文件输入输出中转换，
具体语法是：
FILE *fin,*fout;  
fin = fopen("text.txt","rb");  
fout = fopen("text1.txt","wb");  
fscanf (fin,"%d",&amp;x);  
fprintf (fout,"%d",x);  
fclose(fin);  
fclose(fout);
这里函数稍微复杂了些，不过仔细看看也蛮简单的，最重要的是多了文件关闭操作，这样是
为了不持续占用系统资源。在读取、写入操作时用“rb”的原因是为了兼容Linux系统，只在
windows下运行只要“r”即可，同样，scanf和printf函数都要改成fscanf和fprintf，在
前面加上你要输入的文件和输出的文件名,这样就可以有选择性的操作文件了。
*/

//更改输入输出流的入口和出口
#include <iostream>
using namespace::std;
int main(void)
{
    int i,tmp;
    //if (freopen ("output.txt", "w", stdout) == NULL)
    if (freopen ("input.txt", "r", stdin) == NULL)
        fprintf(stderr, "error redirecting stdin\n");
    if (freopen ("output.txt", "w", stdout) == NULL)
        fprintf(stderr, "error redirecting stdout\n");        
    for (i = 0; i < 10; i++){
        cin >> tmp;
        printf("\n%3d", 3*tmp);
    }
        
    printf("\n");
    fclose(stdout);
    fclose(stdin);
    system("pause");
    return 0;
}

// freopen
// 函数原型：FILE * freopen ( const char * filename, const char * mode, FILE * stream );
// 参数：
// filename: 要打开的文件名
// mode: 文件打开的模式，和fopen中的模式(r/w)相同
// stream: 文件指针，通常使用标准流文件(stdin/stdout/stderr)
// 返回值：如果成功则返回该指向该stream的指针,否则为NULL。
// 作用：用于重定向输入输出流的函数，将stream中的标准输入、输出、错误或者文件流重定向为filename文件中的内容。
//     linux下需要重定向输出很容易使用 ./程序名 >test （>>test 追加）,windows下的输入输出重定向可以使用freopen。
// 使用方法: 因为文件指针使用的是标准流文件，因此我们可以不定义文件指针。
// 我们使用freopen()函数以只读方式r(read)打开输入文件test.in ，freopen("test.in", "r", stdin);
// 这样程序的输入就会从标准输入流stdin转换到从文件"test.in"中输入
// 然后使用freopen()函数以写入方式w(write)打开输出文件test.out，freopen("test.out", "w", stdout);
// 程序的输出就会从原来的标准输出变成写入文件"test.out"中