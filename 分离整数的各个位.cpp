#include <iostream>
using namespace ::std;

int main()
{
    int n = 123456;
    int unitPlace = n / 1 % 10;
    int tenPlace = n / 10 % 10;
    int hundredPlace = n / 100 % 10;
    int thousandPlace = n / 1000 % 10;
    cout << "��λ��" << unitPlace     << endl
         << "ʮλ��" << tenPlace      << endl
         << "��λ��" << hundredPlace  << endl
         << "ǧλ��" << thousandPlace << endl;
    system("pause");
    return 0;
}