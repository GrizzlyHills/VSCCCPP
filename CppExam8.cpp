/*
 * @Author: GrizzlyHills 
 * @Date: 2017-08-23 15:16:17 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-08-23 16:49:01

 编程题＃9：人群的排序和分类

描述
对人群按照输入的信息进行排序和分类。

#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
int main()
{
        int t;
        cin >> t;
        set<A*,Comp> ct;
        while( t -- ) {
                int n;
                cin >> n;
                ct.clear();
                for( int i = 0;i < n; ++i)  {
                        char c; int k;
                        cin >> c >> k;
                        if( c == 'A')
                                ct.insert(new A(k));
                        else
                                ct.insert(new B(k));
                }
                for_each(ct.begin(),ct.end(),Print);
                cout << "****" << endl;
        }
}

输入
第一行是整数t,表明一共t组数据. t < 20
对每组数据：
第一行是整数n,表示下面一共有n行。 0 < n < 100
下面的每行代表一个人。每行以一个字母开头，代表该人所属的类别，然后跟着一个整数，代表年龄。字母只会是 'A‘或‘B' 。整数范围0到100。数据保证年龄都不相同。

输出
对每组输入数据，将这些人按年龄从小到大输出。每个人先输出类别，再输出年龄。每组数据的末尾加一行 "****"

样例输入
2
4
A 3
B 4
A 5
B 6
3
A 4
A 3
A 2

样例输出
A 3
B 4
A 5
B 6
****
A 2
A 3
A 4
****
 */

#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

// 在此处补充你的代码
class A
{
  public:
    int age;
    char s;
    A(int a) : age(a), s('A') {}
    A(int a, char str) : age(a), s(str) {}
};

class B : public A
{
  public:
    B(int b) : A(b, 'B') {}
};

struct Comp
{
    bool operator()(const A *a1, const A *a2) const
    {
        return a1->age < a2->age;
    }
};

void Print(const A *a)
{
    cout << a->s << " " << a->age << endl;
}

int main()
{
    int t;
    cin >> t;
    set<A *, Comp> ct;          //A*为指向A的指针
    while (t--)
    {
        int n;
        cin >> n;
        ct.clear();             //很关键
        for (int i = 0; i < n; ++i)
        {
            char c;
            int k;
            cin >> c >> k;
            if (c == 'A')
                ct.insert(new A(k));
            else
                ct.insert(new B(k));
        }
        for_each(ct.begin(), ct.end(), Print);
        cout << "****" << endl;
    }
    system("pause");
}