#include <iostream>
using namespace ::std;
int main()
{
    char a[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    for (int i = 0; i < 10; i++)
        cout << a[i];
    char c1[] = {'L', 'o', 'v', 'e'};
    char c2[] = "Love";
    char weekday[7][11] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"};
    system("pause");
    return 0;
}