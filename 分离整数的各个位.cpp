#include <iostream>
using namespace ::std;

int main()
{
    int n = 123456;
    int unitPlace = n / 1 % 10;
    int tenPlace = n / 10 % 10;
    int hundredPlace = n / 100 % 10;
    int thousandPlace = n / 1000 % 10;
    cout << "个位：" << unitPlace     << endl
         << "十位：" << tenPlace      << endl
         << "百位：" << hundredPlace  << endl
         << "千位：" << thousandPlace << endl;
    system("pause");
    return 0;
}