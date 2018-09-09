/*
描述
一个以'.'结尾的简单英文句子，单词之间用空格分隔，没有缩写形式和其它特殊形式

输入
一个以'.'结尾的简单英文句子（长度不超过500），单词之间用空格分隔，没有缩写形式和其它特殊形式

输出
该句子中最长的单词。如果多于一个，则输出第一个

样例输入
第一组
I am a student of Peking University.
第二组
Hello world.

样例输出
第一组
University
第二组
Hello
*/
#include <iostream>
using namespace ::std;

int main(void)
{
    char sentence[500] = {'\0'};
    char tempLongestWord[30] = {'\0'};
    cin.getline(sentence, 500);
    int i = 0, Flag = 0, spacePos = 0, wordLength = 0;
    while (sentence[i] != '\0')
    {
        if (sentence[i] == ' ' || sentence[i] == '.')
        {
            spacePos = i;
            if (spacePos - Flag > wordLength)
            {
                for (int j = 0, k = Flag; j < spacePos - Flag; j++, k++)
                {
                    tempLongestWord[j] = sentence[k];
                    wordLength = spacePos - Flag;
                }
            }
            Flag = spacePos + 1;
        }
        i++;
    }
    cout << tempLongestWord;
    system("pause");
    return 0;
}
//机器评判通过