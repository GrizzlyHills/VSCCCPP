// 作者：origin
// 链接：https://www.zhihu.com/question/28324597/answer/41386836
// 来源：知乎
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string cipher = "VRPHWLPHV L ZDQW WR FKDW ZLWK BRX, EXW L KDYH QR UHDVRQ WR FKDW ZLWK BRX";
    std::string confession(cipher.size(), ' ');
    for (int i = 0; i <= 25; ++i)
    {
        for (size_t j = 0; j < cipher.size(); ++j)
        {
            if (cipher[j] != ' ' && cipher[j] != ',')
            {
                if (cipher[j] + i >= 'A' && cipher[j] + i <= 'Z')
                {
                    confession[j] = static_cast<char>(cipher[j] + i);
                }
                else
                {
                    confession[j] = static_cast<char>(cipher[j] + i - 26);
                }
            }
            else
            {
                confession[j] = cipher[j];
            }
        }
        std::cout << confession << std::endl;
    }
    system("pause");
}