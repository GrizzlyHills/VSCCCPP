#include <iostream>
using namespace::std;

int main(void)
{
    
    int x, y, z;
    cout << "\t����\t\tĸ��\t\tС��" << endl;
    for(x = 0; x <= 33; x++)
        for(y = 0; y <= 50; y++)
            for(z = 0; z <= 100; z++) {
                if((x + y + z) == 100)
                    if((3 * x + 2 * y + 0.5 * z) == 100)
                        cout << "\t" << x << "\t\t"
                             << y << "\t\t" << z << endl; 
            }
    system("pause");
    return 0;
}