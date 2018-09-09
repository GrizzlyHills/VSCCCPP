#include <iostream>
using namespace::std;

/*
class Ctest {
    private:
        //int a;
        //int b;
        //int c;
        //int d;
    public:
        Ctest() {
            cout << "constructor called" << endl;
        }
        ~Ctest() {
            cout << "destructor called" << endl;
        }
};

int main() {
    Ctest array[2];
    cout << sizeof(array[1]) << endl;   //如果类中没有成员变量，则实测的一个新的对象大小为一个字节
    cout << "End Main" << endl;         //输出：End Main   destructor called   destructor called 
    delete []array;
    system("pause");                    //单步调试才能看见析构函数被调用
    return 0;
}
*/

//构造函数和析构函数以及变量的生存期
class Demo {
        int id;
    public:
        Demo(int i) {
            id = i;
            cout << "id = " << id << "  Constructed" << endl;
        }
        ~Demo() {
            cout << "id = " << id << "  Destructed" << endl;
        }
};
Demo d1(1);
void Func() {
    static Demo d2(2);
    Demo d3(3);
    cout << "Func" << endl;
}
int main() {
    Demo d4(4);
    d4 = 6;                         //生成了一个临时对象后又析构了，类型转换构造函数的功能
    cout << "main" << endl;
    {
        Demo d5(5);                 //那么对于d5这样的一个全局变量的话呢，它呢会有点特殊，区别于d4，
                                    //那么它有一个自己的作用域，看到没有，这有一对花括号，
                                    //那么我们语法规定说呢， 这个离对象最近的一对花括号中间的范围呢， 就是它相应的作用域。 
                                    //那么这个作用域呢就标志着这个对象的生命，生命周期，啊，也就是说这个对象在离开作用域之后呢，就需要消亡掉
    }
    Func();
    cout << "main ends" << endl;
    system("pause");
    return 0;
}
/*
id = 1  Constructed
id = 4  Constructed
id = 6  Constructed
id = 6  Destructed
main
id = 5  Constructed
id = 5  Destructed
id = 2  Constructed
id = 3  Constructed
Func
id = 3  Destructed
main ends
id = 6  Destructed
id = 2  Destructed
id = 1  Destructed
*/