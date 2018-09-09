// #include <iostream>
// #include <cstring>
// #include <iomanip>
// #include <cstdlib>
// #include <sstream>
// #include <set>
// #include <ctime>
#include "bits/stdc++.h"
using namespace::std;
#define ArrLength 10

int flag = 0;

class Ctest {
    public:
        ~Ctest() {
            cout << "destructor called     " << flag++ << endl;
        }
};

void SubFuncDestruct()
{
    Ctest test[10];
    return;
}

int* reset(int *iip)
{
    *iip = 0;
    cout << *iip << endl;
//    iip = 0;
    return iip;
}
int main()
{
    const int arr_length = 10;
    int i = 0;
    //char a[10] = {'a','b','c','d','e','f','g','h','i','j'};
    //char a[ArrLength] = {'a','b','c','d','e','f','g','h','i','j'};
    char a[arr_length] = {'a','b','c','d','e','f','g','h','i','j'};
    cout << "字母表中序号为奇数的前五个字母：" << endl;
    for(i = 0; i < 10; i++){
        if(i%2 != 0)
            cout << a[i] << endl;
    }
    int n = -123;
    cout << hex << n << endl;
    cout << oct << n << endl;
    cout << dec << n << endl;
    n = 0xffffff85;
    cout << oct << n << endl;
    cout << dec << n << endl;   

    float q = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
    double w = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679; 
    long double e = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;    
    cout << q << endl;
    cout << w << endl;
    cout << e << endl;   
    cout << setprecision(100) << q << endl;
    cout << w << endl;
    cout << e << endl;    
    int j = 0;
    cout << (j = 10) << endl;
    cout << (j = i + i) << endl;  
    unsigned int ui = 1;
    int ii = -1;
    cout << hex << "ui=" << ui << endl;
    cout << hex << "ii=" << ii << endl;
    cout << ui+ii << endl;   
    cout << hex << "ii=" << (unsigned int)(ii) << endl 
         << dec << (unsigned int)(ii) <<endl;     
    char hi[] = {'h','e','l','l','o'};
    char HI[] = "hello";
    const char *Hi = "hello";
    cout << sizeof(hi)/sizeof(char) << "     " << sizeof(HI)/sizeof(char) << "      " << sizeof(*Hi)/sizeof(char) << endl;
    cout << strlen(hi) << "     " << strlen(HI) << "      " << strlen(Hi) << endl;
    bool f = false,t = true;
    cout << f << "     " << t <<  endl;
    cout << hex << f << "     " << t <<  endl;
    char *p = hi;
    for(int i = 0;i < 6;i++){
        cout << setw(4) << hi[i] << setw(4) << *p++ << setw(10) << hi << endl;
    }
    cout << "引用的地址测试：" << endl;
    int test = 666;
    int &ref = test;
    cout << "test的地址为：" << &test << "  ref的地址为：" << &ref << endl;
    const char *c_ptr = "666hello";               //数字在前  可被  atoi  单独解析出数字
    cout << c_ptr << "  " << dec << atoi(c_ptr) << endl;
    //-----------------------------------一些字符串函数的应用----------------------------------------------------------------
    char cc[] = "Hello World";
    cout << strlen(cc) << endl;
    memset(cc,'\101',sizeof(char) * strlen(cc));
    char cat[] = "catch";
    cc[11] = '\0';
    strcat(cc,cat);   
    cout << cc << "           " << strlen(cc) <<endl;
//-----------------------------------指针传值的小探究----------------------------------------------------------------
    int uu = 666;
    cout << "--------------------------" << endl;
    cout << uu << endl << *reset(&uu) << endl << uu << endl;
    cout << "--------------------------" << endl;
    cout << reset(&uu) << endl << &uu << endl << uu << endl;
//-----------------------------------cout的小探究----------------------------------------------------------------   
    cout << "--------------------------" << endl;
    std::ostringstream s;
    std::cout << s.tellp() << '\n';
    s << 'h';
    std::cout << s.tellp() << '\n';
    s << "ello, world ";
    std::cout << s.tellp() << '\n';
    s << 3.14;
    s <<"_                            _";
    std::cout << s.tellp() << '\n' << s.str() << endl << sizeof(double) << endl;
    
    long location = s.tellp();
    location = 30L;
    s.seekp(location);
    s << "Inspire";
    cout << s.str() << endl;
//-----------------------------------指针和引用的小探究-----------------------------------------------------------      
    int jim = 666;
    int &re = jim;
    cout << "re=" << re << "  jim=" << jim << "  &re=" << &ref << "  &jim=" << &jim << endl; 
//-----------------------------------string类对象----------------------------------------------------------------       
    string hello("Hello World"); 
    string ss1("ba"),ss2("hello"),ss3("b");
    bool StrFlag;
    StrFlag = (ss1 > ss3);
    cout << "StrFlag=" << StrFlag << endl;              //1

    string s1("hello worlld");

    cout << s1.find("ll") << endl;
    cout << s1.find("abc") << endl; 

    cout << s1.rfind("ll") << endl; 
    cout << s1.rfind("abc") << endl;  

    cout << s1.find_first_of("abcde") << endl;   
    cout << s1.find_first_of("abc") << endl;    

    cout << s1.find_last_of("abcde") << endl;   
    cout << s1.find_last_of("abc") << endl;    

    cout << s1.find_first_not_of("abcde") << endl;   
    cout << s1.find_first_not_of("hello world") << endl; 

    cout << s1.find_last_not_of("abcde") << endl;   
    cout << hex << s1.find_last_not_of("hello world") << endl;
//-----------------------------------字符串----------------------------------------------------------------
    const char *cstr = "Hello World";
    char *cp = new char[strlen(cstr) + 1];
    *(cp + strlen(cstr)) = '\0';                                     //结尾的空字符必须加

    memcpy(cp,cstr,sizeof(char) * strlen(cstr));
     cout << "cp=" << cp << endl;
    while(*cp != 0) {
        cout << "cp=" << cp << endl;
        cp++;
    }
//-----------------------------------子函数中类的对象的析构----------------------------------------------------------------
    SubFuncDestruct();
    cout << "The SubFuncDestruct Function have came out." << endl;
//-----------------------------------股票涨幅----------------------------------------------------------------    
    float start = 1.0;
    float increase = 0.6;
    for(int i = 0; i < 13; i++) {
        start *= (1 + increase);
    }
    cout << "start=" << start << endl;              //13年股价翻涨约450倍，年平均涨幅约60%
//-----------------------------------multiset----------------------------------------------------------------     
    int testarr[] = {2,3,4,5,7,3};
    multiset<int> mp(testarr, testarr+6);
    cout << *mp.lower_bound(4) << endl;
//-----------------------------------rand----------------------------------------------------------------     

    std::srand(std::time(0)); //use current time as seed for random generator

    for(int i = 0; i < 10; ++i) {
        int uniform_random_variable = std::rand();
        std::cout << dec << "Uniform random value on [0 " << RAND_MAX << "]: " << uniform_random_variable % 100 << '\n';    
    }

    int iSecret, iGuess;
    /* initialize random seed: */
    srand (time(NULL));
    /* generate secret number between 1 and 10: */
    iSecret = rand() % 10 + 1;
    do {
        printf ("Guess the number (1 to 10): ");
        scanf ("%d",&iGuess);
        if (iSecret<iGuess) puts ("The secret number is lower");
        else if (iSecret>iGuess) puts ("The secret number is higher");
    } while (iSecret!=iGuess);
    puts ("Congratulations!");
    puts("hello world\ras");
//---------------------------------------------------------------------------------------------------------
    char pan = 'q';	
    cout << "previous_pan: " << pan << endl;
    int *ppan = new (&pan) int;
    *ppan &= 0;
    cout << "later_pan: " << *ppan << endl;
    pan = 'w';
    cout << "later_pan: " << *ppan << endl;
//-----------------------------------------------------------------------------------------------------------
    int dd = 1, ee = 0;
    try {
        if (ee == 0)
            throw -1;
        else 
            cout << dd/ee << endl;          //由于除数是 0， 此处会抛出一个异常。。 没有除法运算的结果
    }
    // catch(int i) {
    //     cout << dec << "catch(int): " << i << endl;
    // }
    catch(...) {
        cout << dec << "catch(...): 能够捕捉任何异常！但只能放到捕捉异常代码的最后面！\
                        对于任何类型的 catch 语句而言， 如果该 catch 语句块已经起作用了， 则后面的语句块都不再起作用，\ 
                        所以该类型的语句块不要写到所有 cacth 块的最前面。" << endl;
    }  
//-----------------------------数组长度判断------------------------------------------------------------------------------
    char testStr[] = "hello";
    cout << "改动前： " << testStr << " " << sizeof(testStr) << endl;
    testStr[0] = '\0';
    cout << "改动后： " << testStr << " " << sizeof(testStr) << endl;
    memset(testStr, '6', sizeof(testStr)-2);
    cout << "改动内存后： " << testStr << " " << sizeof(testStr) << endl;

    int haha = 14 % 4;
    cout << haha << endl;
    system("pause");
    return 0;
}