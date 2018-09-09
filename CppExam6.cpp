/*
 * @Author: GrizzlyHills 
 * @Date: 2017-08-23 11:06:24 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-08-23 11:57:15

    编程题＃7：字符串排序

    描述
    请按照要求对输入的字符串进行排序。

    #include <iostream>
    #include <string>
    #include <list>
    using namespace std;
    class A{
    private:
            string name;
    public:
            A(string n) :name(n){}
            friend bool operator < (const class A& a1, const class A &a2);
            friend bool operator == (const class A &a1, const class A &a2){
                    if (a1.name.size() == a2.name.size())
                            return true;
                    else
                            return false;
            }
            friend ostream & operator << (ostream &o, const A &a){
                    o << a.name;
                    return o;
            }
            string get_name() const{
                    return name;
            }
            int get_size() const{
                    return name.size();
            }
    };
    // 在此处补充你的代码
    int main(int argc, char* argv[])
    {
            list<A> lst;
            int ncase, n, i = 1;
            string s;
            cin >> ncase;
            while (ncase--){
                    cout << "Case: "<<i++ << endl;
                    cin >> n;
                    for (int i = 0; i < n; i++){
                            cin >> s;
                            lst.push_back(A(s));
                    }
                    lst.sort();
                    Show(lst.begin(), lst.end(), Print());
                    cout << endl;
                    lst.sort(MyLarge<A>());
                    Show(lst.begin(), lst.end(), Print());
                    cout << endl;
                    lst.clear();
            }
            return 0;
    }

    输入
    第一行是正整数T，表示测试数据的组数
    每组测试数据输入共两行，
    第一行是正整数N，表示字符串个数
    第二行是N个字符串, 字符串间用空格分离

    输出
    对于每组测试数据，先输出一行：
    Case: n
    如对第一组数据就输出Case: 1
    第二行按照字符串长度从小到大排序之后输出N个字符串，字符串之间以空格间隔（不会出现字符串长度相同的情况）
    第三行按照字符串首字符ASCII码序从小到大排序之后输出N个字符串，字符串之间以空格间隔（不会出现字符串首字母相同的情况）

    样例输入
    2
    4
    a bnss ds tsdfasg
    5
    aaa bbbb ccccd sa q

    样例输出
    Case: 1
    a ds bnss tsdfasg
    a bnss ds tsdfasg
    Case: 2
    q sa aaa bbbb ccccd
    aaa bbbb ccccd q sa
 */

#include <iostream>
#include <string>
#include <list>
using namespace std;
class A
{
  private:
    string name;

  public:
    A(string n) : name(n) {}
    friend bool operator<(const class A &a1, const class A &a2);
    friend bool operator==(const class A &a1, const class A &a2)
    {
        if (a1.name.size() == a2.name.size())
            return true;
        else
            return false;
    }
    friend ostream &operator<<(ostream &o, const A &a)
    {
        o << a.name;
        return o;
    }
    string get_name() const
    {
        return name;
    }
    int get_size() const
    {
        return name.size();
    }
};

// 在此处补充你的代码
bool operator < (const A& a1, const A& a2)
{
    return a1.get_size() < a2.get_size();
}

template <class Iterator, class Function>//函数模板
void Show(Iterator begin, Iterator end, Function print)
{
    for (Iterator iterator1 = begin; iterator1 != end; iterator1++)
    {
        print(*iterator1);
    }
}

class Print //函数对象类
{
public:
    void operator() (const A &a) const
    {
        cout << a.get_name() << " ";
    }
};

template <class A>  //函数对象类模板
struct MyLarge
{
    inline bool operator() (const A& a1, const A& a2)
    {
        return a1.get_name() < a2.get_name();
    }
};

int main(int argc, char *argv[])
{
    list<A> lst;
    int ncase, n, i = 1;
    string s;
    cin >> ncase;
    while (ncase--)
    {
        cout << "Case: " << i++ << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            lst.push_back(A(s));
        }
        lst.sort();
        Show(lst.begin(), lst.end(), Print());
        cout << endl;
        lst.sort(MyLarge<A>());                             //这种写法糊涂了 
        Show(lst.begin(), lst.end(), Print());
        cout << endl;
        lst.clear();
    }
    system("pause");
    return 0;
}