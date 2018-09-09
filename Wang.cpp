#include <iostream>
#include <cmath>

#define e 2.718281828
using namespace::std;

double function(double val)
{
    return (pow(e, val) - 1/tan(val));
}

void compute(double init, double freq)
{
    double PreviousVal = function(init);
    double CurrentVal = 0.0;
    int i = 1;
    while(init < 10.0) {
        init += freq;
        CurrentVal = function(init);
        if(PreviousVal*CurrentVal <= 0) {
            cout << "xȡֵ��Χ[-7, 10]������Ƶ��freq = 0.001���� " << i++ << " ��ȡ�õĺ������Ϊ x = " << init << endl;
        }
        PreviousVal = CurrentVal;        
    }

}

int main()
{
    compute(-7.0, 0.001);
    system("pause");
}