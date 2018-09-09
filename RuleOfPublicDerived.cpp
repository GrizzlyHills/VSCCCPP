//public继承的赋值兼容规则
#include <iostream>
using namespace::std;

class Base {
    public:
        int n;
        Base(int i):n(i) 
        {
            cout << "Base" << n << "constructed" << endl;           //一
        }
        ~Base() 
        {
            cout << "Base" << n << "destructed" << endl;            //六
        }
};
class Derived:public Base {
    public:
        Derived(int i):Base(i)
        {
            cout << "Derived constructed" << endl;                  //二
        }
        ~Derived()
        {
            cout << "Derived destructed" << endl;                   //五
        }
};
class MoreDerived:public Derived {
    public:
        MoreDerived():Derived(4) 
        {
            cout << "MoreDerived constructed" << endl;              //三
        }
        ~MoreDerived()
        {
            cout << "MoreDerived destructed" << endl;               //四
        }
};

int main()
{
    MoreDerived Obj;
    system("pause");
    return 0;
}
