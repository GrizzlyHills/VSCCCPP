/*
编程题＃1

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
写一个MyString 类，使得下面程序的输出结果是：
1. abcd-efgh-abcd-
2. abcd-
3.
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz

about
big
me
take
abcd
qrst-abcd-

要求：MyString类必须是从C++的标准类string类派生而来。
提示1：如果将程序中所有 "MyString" 用"string" 替换，那么题目的程序中除了最后两条语句编译无法通过外，
其他语句都没有问题，而且输出和前面给的结果吻合。也就是说，MyString类对 string类的功能扩充只体现在最后两条语句上面。
提示2: string类有一个成员函数 string substr(int start,int length); 能够求从 start位置开始，长度为length的子串

程序：
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
// 在此处补充你的代码
int CompareString( const void * e1, const void * e2) {
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( *s1 < *s2 ) return -1;
    else if( *s1 == *s2 ) return 0;
    else if( *s1 > *s2 ) return 1;
}
int main() {
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3; s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1; s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString), CompareString);
    for( int i = 0;i < 4;++i )
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}
输入
无

输出
1. abcd-efgh-abcd-
2. abcd-
3.
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-

样例输入
无

样例输出
1. abcd-efgh-abcd-
2. abcd-
3.
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-
*/
//此题考查的点很多，要多复习
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace::std;
// 在此处补充你的代码
class MyString : public string
{
  public:
    MyString(){}
    //1.0继承类继承父类所有的成员变量和成员函数，但不继承构造函数和析构函数
    //1.1继承类的无参构造函数，会隐式调用父类的无参构造函数
    MyString(const char *st) : string(st){}
    //1.2继承类的有参构造函数，如果父类也有有参构造函数，则必须显示调用它
    //2.0这里的参数根据reference有两种选择，此处必须用const char*,"xxx"的类型是const char*
    MyString(const MyString &s) : string(s) {}
    //1.3继承类的复制构造函数必须要显式的调用父类的复制构造函数，不然就会默认调用父类的无参构造函数

//然后再说一下string类中的c_str()函数，先看下C++Reference中对它的定义
// const char* c_str() const noexcept;
// The pointer returned points to the internal array currently used by the string object to store the characters that conform its value.
// 说白了就是把string中存储的内容给放到一个char数组中，然后返回这个数组的首地址，const char* 类型
// 这里由于我们重写operator+的返回值要求是MyString类型的，所以在return的时候要构建MyString类的对象，
//而它的有参构造函数就只能接受const char*类型的参数，所以我们有必要做出这么一步转换。
    MyString operator+(MyString &op2)
    {
        string s1 = *this;
        string s2 = op2;
        string s = s1 + s2;
        return *new MyString(s.c_str());
    }
    MyString &operator+(const char *cs2)
    {
        string str1 = *this;
        string s = str1 + cs2;
        return *new MyString(s.c_str());
    }

    MyString &operator()(int s, int l)
    {
        string str = substr(s, l);
        return *new MyString(str.c_str());
    }
};
MyString operator+(const char * op1, MyString & op2)
{
    string st2 = op2;
    string s = op1 + st2;
    return *new MyString(s.c_str());
}
int CompareString(const void *e1, const void *e2)
{
    MyString *s1 = (MyString *)e1;
    MyString *s2 = (MyString *)e2;
    if (*s1 < *s2)
        return -1;
    else if (*s1 == *s2)
        return 0;
    else if (*s1 > *s2)
        return 1;
}
int main()
{
    MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
    MyString SArray[4] = {"big", "me", "about", "take"};
    cout << "1. " << s1 << s2 << s3 << s4 << endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A';
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for (int i = 0; i < 4; ++i)
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5, 10) << endl;
    system("pause");
    return 0;
}
