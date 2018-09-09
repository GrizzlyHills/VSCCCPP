/*
描述
有两个字符串str和substr，str的字符个数不超过10，substr的字符个数为3。
（字符个数不包括字符串结尾处的'\0'。）将substr插入到str中ASCII码最大的那个字符后面，若有多个最大则只考虑第一个。

输入
输入包括若干行，每一行为一组测试数据，格式为
str substr

输出
对于每一组测试数据，输出插入之后的字符串。

样例输入
abcab eee
12343 555

样例输出
abceeeab
12345553

提示
这题有多组输入，请参照第二题的提示依次读入和处理每一组数据。
如果使用了字符串函数，比如strlen，请包含cstring头文件 #include <cstring>。
*/

#include <iostream>
using namespace std;
#define len1 100
#define len2 50

int main() {
    char str[len1] = {'\0'},substr[len2] = {'\0'};
    while(cin >> str >> substr){
        int flag = 0,count = 0;
        char temp = ' ';
        while(str[count] != '\0'){//求substr的实际字符串长度
            if(str[count]>temp){
                temp = str[count];
                flag = count;
            }
            count++;
        }
        int len = 0;
        while(substr[len] != '\0'){
            len++;
        }    
        for(int i = 0;i < count - flag - 1;i++){
            str[count-i+len-1] = str[count-i-1];
        }
        for(int i = flag + 1,j = 0;i < flag + len + 1,substr[j]!='\0';i++,j++){
            str[i] = substr[j];
        }
        cout << str << endl;
    }
    system("pause");
    return 0;
}

/*
#include <iostream>
using namespace std;

int main()
{
    char str[14] = {0}, substr[4] = {0};
    while (cin >> str >> substr)
    {
        int i = 0, posBiggest = 0;
        char strBiggest = 0;
        while (str[i])
        {
            if (str[i] > strBiggest)
            {
                posBiggest = i;
                strBiggest = str[i];
            }
            i++;
        }
        for (int j = 9; j > posBiggest; j--)
        {
            str[j+3] = str[j];
        }
        str[posBiggest+1] = substr[0];
        str[posBiggest+2] = substr[1];
        str[posBiggest+3] = substr[2];
        cout << str << endl;
    }
    return 0;
}
*/
//机器评判通过