/*
 * @Author: GrizzlyHills 
 * @Date: 2017-08-23 19:18:40 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-08-24 13:09:51

    编程题＃11：数据库内的学生信息

    描述
    程序填空，使得下面的程序,先输出
    (Tom,80),(Tom,70),(Jone,90),(Jack,70),(Alice,100),
    (Tom,78),(Tom,78),(Jone,90),(Jack,70),(Alice,100),
    (70,Jack),(70,Tom),(80,Tom),(90,Jone),(100,Alice),
    (70,Error),(70,Error),(80,Tom),(90,Jone),(100,Alice),
    ******
    然后，再根据输入数据按要求产生输出数据

    #include <iostream>
    #include <string>
    #include <map>
    #include <iterator>
    #include <algorithm>
    using namespace std;
    // 在此处补充你的代码
    struct Student
    {
            string name;
            int score;
    };
    template <class T>
    void Print(T first,T last) {
            for(;first!= last; ++ first)
                    cout << * first << ",";
            cout << endl;
    }
    int main()
    {
            Student s[] = { {"Tom",80},{"Jack",70},
                                            {"Jone",90},{"Tom",70},{"Alice",100} 
                                        };
            MyMultimap<string,int> mp;
            for(int i = 0; i<5; ++ i)
                    mp.insert(make_pair(s[i].name,s[i].score));
            Print(mp.begin(),mp.end()); //按姓名从大到小输出
            mp.Set("Tom",78); //把所有名为"Tom"的学生的成绩都设置为78
            Print(mp.begin(),mp.end());
            MyMultimap<int,string,less<int> > mp2;
            for(int i = 0; i<5; ++ i)
                    mp2.insert(make_pair(s[i].score,s[i].name));
            Print(mp2.begin(),mp2.end()); //按成绩从小到大输出
            mp2.Set(70,"Error");          
                //把所有成绩为70的学生，名字都改为"Error"
            Print(mp2.begin(),mp2.end());
            cout << "******" << endl;
            mp.clear();
            
            string name;
            string cmd;
            int score;
            while(cin >> cmd ) {
                    if( cmd == "A") {
                            cin >> name >> score;
                            if(mp.find(name) != mp.end() ) {
                                    cout << "erroe" << endl;
                            }
                            mp.insert(make_pair(name,score));
                    }
                    else if(cmd == "Q") {
                            cin >> name;
                            MyMultimap<string,int>::iterator p = mp.find(name);
                            if( p!= mp.end()) {
                                    cout << p->second << endl;
                            }
                            else {
                                    cout << "Not Found" << endl;
                            }
                    }
            }
            return 0;
    }

    输入
    输入数据的每一行，格式为以下之一：
    A name score
    Q name score
    name是个不带个空格的字符串，长度小于 20
    score是个整数，能用int表示
    A name score 表示往数据库中新增一个姓名为name的学生，其分数为score。开始时数据库中一个学生也没有。
    Q name 表示在数据库中查询姓名为name的学生的分数
    数据保证学生不重名。
    输入数据少于200,000行。

    输出
    对于每个查询，输出学生的分数。如果查不到，则输出 "Not Found"

    样例输入
    A Tom1 30
    A Tom2 40
    Q Tom3
    A Tom4 89
    Q Tom1
    Q Tom2

    样例输出
    (Tom,80),(Tom,70),(Jone,90),(Jack,70),(Alice,100),
    (Tom,78),(Tom,78),(Jone,90),(Jack,70),(Alice,100),
    (70,Jack),(70,Tom),(80,Tom),(90,Jone),(100,Alice),
    (70,Error),(70,Error),(80,Tom),(90,Jone),(100,Alice),
    ******
    Not Found
    30
    40

    提示
    1) 编写模板的时候，连续的两个 “>”最好要用空格分开，以免被编译器看作是 ">>"运算符。VS可能无此问题，但是Dev C++和服务器上的编译环境会有这个问题。
    比如 vector<vector<int>> 有可能出错，要改成 vector<vector<int> >
    2) 在模板中写迭代器时，最好在前面加上 typename关键字，否则可能会编译错。VS可能无此问题，但是Dev C++和服务器上的编译环境会有这个问题。


    1.MyMultimap<string, int>::iterator p = mp.find(name);  
    //网上解释说std::map这些stl容器的多态性不好等，  
    //所以这里自定义的MyMultimap类不是inherit from multimap,而是composition(即把multimap对象作为类成员)  
    //iterator可以有两种情况：  
    //1.这里::双冒号说明是在自定义的类中再定义一个类，class iterator  
    //2.从题目的end(),begin()函数可以看到iterator其实代表std::multimap<key,value>::iterator,所以这里直接在MyMultiple类中  
    //  用typedef 重命名  
    //  typedef typename std::multimap<K, V>::iterator iterator;  
    
    
    2. Print(mp2.begin(), mp2.end()); //按成绩从小到大输出  
    // 这里说明default的MyMultimap排序为升序，因此需要自定义greater<T>函数  
    //C++11版本，关键还是用struct,或者class + public, 还有几个typedef  
    template <class T> struct greater {  
        bool operator() (const T& x, const T& y) const { return x>y; }  
        typedef T first_argument_type;  
        typedef T second_argument_type;  
        typedef bool result_type;  
    };  
    //c++98  
    template <class T> struct greater : binary_function <T, T, bool> {  
        bool operator() (const T& x, const T& y) const { return x>y; }  
    };  
    //因此MyMultimap可以这样声明  
    template<typename K, typename V, class Pred = mygreater<K> >  
    class MyMultimap{  
        ...  
    }  
    
    
    3. mp2.Set(70, "Error");          //把所有成绩为70的学生，名字都改为"Error"  
    //修改mulitmap的pair中second值，不像map一样可以直接mapname[k] = v;  
    //因为multimap存在多个同键值，需要借助equal_range函数，其中myMap是MyMultimap中的multimap成员,K 和V为MyMultimap的  
    //传入类型，iterator前面说了是std::multimap<K, V>::iterator iterator的重命名  
    void Set(K k, V v){  
        //修改multimap的pair的second值，利用equal_range函数  
        iterator ending = myMap.equal_range(k).second;  
        iterator starting = myMap.equal_range(k).first;  
        while (starting != ending){  
            starting->second = v;  
            starting++;  
        }  
    }     
 */

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

// 在此处补充你的代码
template <class T>
struct myGreater
{
    bool operator()(const T &x, const T &y) const { return x > y; }
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;
};

template <typename K, typename V, class Pred = myGreater<K>>
class MyMultimap
{
  public:
    //typedef std::multimap<K, V, Pred> myType;
    typedef multimap<K, V, Pred> myType;
    //typedef typename std::multimap<K, V>::iterator iterator;
    typedef class multimap<K, V>::iterator iterator;            //这样写也可以。。
    myType myMap;
    void insert(std::pair<K, V> _p)
    {
        myMap.insert(_p);
    }
    iterator find(K k)
    {
        return myMap.find(k);
    }
    iterator begin()
    {
        return myMap.begin();
    }
    iterator end()
    {
        return myMap.end();
    }
    void Set(K k, V v)
    {
        //修改multimap的pair的second值，利用equal_range函数
        iterator ending = myMap.equal_range(k).second;
        iterator starting = myMap.equal_range(k).first;
        while (starting != ending)
        {
            starting->second = v;
            starting++;
        }
    } 
    void clear()                        //这个函数可以缓缓
    {
        myMap.clear();
    }
};

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &o, typename std::pair<const T1, T2> _p)
{
    std::cout << "(" << _p.first << "," << _p.second << ")";
    return o;
}

struct Student
{
    string name;
    int score;
};

template <class T>
void Print(T first, T last)
{
    for (; first != last; ++first)
        cout << *first << ",";
    cout << endl;
}

int main()
{
    Student s[] = {{"Tom", 80}, {"Jack", 70}, {"Jone", 90}, {"Tom", 70}, {"Alice", 100}};
    MyMultimap<string, int> mp;
    for (int i = 0; i < 5; ++i)
        mp.insert(make_pair(s[i].name, s[i].score));
    Print(mp.begin(), mp.end());                            //按姓名从大到小输出
    mp.Set("Tom", 78);                                      //把所有名为"Tom"的学生的成绩都设置为78
    Print(mp.begin(), mp.end());
    MyMultimap<int, string, less<int>> mp2;
    for (int i = 0; i < 5; ++i)
        mp2.insert(make_pair(s[i].score, s[i].name));
    Print(mp2.begin(), mp2.end());                          //按成绩从小到大输出
    mp2.Set(70, "Error");
    //把所有成绩为70的学生，名字都改为"Error"
    Print(mp2.begin(), mp2.end());
    cout << "******" << endl;
    mp.clear();

    string name;
    string cmd;
    int score;
    while (cin >> cmd)
    {
        if (cmd == "A")
        {
            cin >> name >> score;
            if (mp.find(name) != mp.end())
            {
                cout << "erroe" << endl;
            }
            mp.insert(make_pair(name, score));
        }
        else if (cmd == "Q")
        {
            cin >> name;
            //MyMultimap<string, int>::iterator p = mp.find(name);
            auto p = mp.find(name);
            if (p != mp.end())
            {
                cout << p->second << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }
        }
    }
    system("pause");
    return 0;
}