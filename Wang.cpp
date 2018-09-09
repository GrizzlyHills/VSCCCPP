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
            cout << "x取值范围[-7, 10]，迭代频率freq = 0.001，第 " << i++ << " 个取得的函数零点为 x = " << init << endl;
        }
        PreviousVal = CurrentVal;        
    }

}

int main()
{
    compute(-7.0, 0.001);
    system("pause");
}