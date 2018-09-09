#include <iostream>
using namespace::std;    
    
class Skill {
    private:
        int ints;
    public:
        Skill(int n):ints(n) {}
        int Get()
        {
            return ints;
        }
};
class Bug {
    private:
        int nLegs;
        int nColor;
    public:
        int nType;
        Bug(int legs,int color):nLegs(legs),nColor(color) {}
        void PrintBug() 
        {
            cout << "nLegs=" << nLegs << endl
                 << "nColor=" << nColor << endl;
        }
};
class FlyBug:public Bug {                   //FlyBug是Bug的派生类
    private:
        int nWings;
        Skill sk1,sk2;
    public:
        FlyBug(int legs,int color,int wings);
        void Print();
};    

// Bug::Bug(int legs,int color)
// {
//     nLegs = legs;
//     nColor = color;
// }

//正确的FlyBug构造函数：
FlyBug::FlyBug(int legs,int color,int wings):Bug(legs,color),sk1(5),sk2(color),nWings(wings)      //先调用基类的构造函数，再调用成员对象类的构造函数
{
    //nWings = wings;
    cout << "派生兼包含成员对象类构造函数启动" << endl;
}

void FlyBug::Print()
{
    cout << "nWings=" << nWings << endl
         << "sk1.ints=" << this->sk1.Get() << endl
         << "sk2.ints=" << this->sk2.Get() << endl;
    Bug::PrintBug();
}

int main()
{
    FlyBug fb(6,7,8);
    fb.Print();
    system("pause");
    return 0;
}