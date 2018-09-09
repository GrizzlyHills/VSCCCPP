#include <iostream>
#include <iomanip>
using namespace ::std;
int main()
{
    unsigned char a = 64;
    unsigned int b = 'Z';
    unsigned int c = b - a;
    unsigned char d = 6 + 256;
    unsigned char e = 6;
    cout << a << " " << b << " " << c << " " << d << " " << e << endl;
    //转义字符考察
    cout << "This is the first line!\n";
    cout << '\a' << '\\' << '\n'
         << endl;

    unsigned int i;
    for (i = 1; i <= 256; i++)
    {
        cout << char(i);
        cout << ' ';
        if (i % 20 == 0)
            cout << endl;
    }
    system("pause");
    return 0;
}