/*
    描述
    写一个自己的 CMyistream_iterator 模板，使之能和 istream_iterator 模板达到一样的效果，即：

    输入：
    79 90 20 hello me

    输出：
    79
    79,90,20
    hello,me

    #include <iostream>
    #include <string>
    using namespace std;
    // 在此处补充你的代码
    int main()
    {
        CMyistream_iterator<int> inputInt(cin);
        int n1,n2,n3;
        n1 = * inputInt; //读入 n1
        int tmp = * inputInt;
        cout << tmp << endl;
        inputInt ++;
        n2 = * inputInt; //读入 n2
        inputInt ++;
        n3 = * inputInt; //读入 n3
        cout << n1 << "," << n2<< "," << n3 << endl;
        CMyistream_iterator<string> inputStr(cin);
        string s1,s2;
        s1 = * inputStr;
        inputStr ++;
        s2 = * inputStr;
        cout << s1 << "," << s2 << endl;
        return 0;
    }

    输入
    79 90 20 hello me

    输出
    79
    79,90,20
    hello,me

    样例输入
    79 90 20 hello me

    样例输出
    79
    79,90,20
    hello,me

    提示
    istream_iterator模版使用说明：
    其构造函数执行过程中就会要求输入，然后每次执行++，则读取输入流中的下一个项目，执行 * 则返回上次从输入流中读取的项目。
    例如，下面程序运行时，就会等待用户输入数据，输入数据后程序才会结束：

    #include <iostream>
    #include <iterator>
    using namespace std;
    int main() {
            istream_iterator<int> inputInt(cin);
            return 0;
    }

    下面程序运行时，如果输入 12 34 程序输出结果是： 12,12
    #include <iostream>
    #include <iterator>
    using namespace std;
    int main()
    {
            istream_iterator<int> inputInt(cin);
            cout << * inputInt << "," << * inputInt << endl;
            return 0;
    }

    下面程序运行时，如果输入 12 34 56程序输出结果是： 12,56
    #include <iostream>
    #include <iterator>
    using namespace std;
    int main()
    {
            istream_iterator<int> inputInt(cin);
            cout << * inputInt << "," ;
            inputInt ++;
            inputInt ++;
            cout << * inputInt;
            return 0;
    }

*/

#include <iostream>
#include <iterator>
#include <string>
using namespace std;

// 在此处补充你的代码
template <class T>
class CMyistream_iterator : public iterator<input_iterator_tag, T> {
    private:
        basic_istream* in_stream;
        T value;
    public:
        typedef basic_istream istream_type;
        CMyistream_iterator() : in_stream(0) {}
        CMyistream_iterator(istream_type& s) : in_stream(&s) { ++*this; }
        CMyistream_iterator(const istream_iterator<T, charT, traits, Distance>& x)
            : in_stream(x.in_stream), value(x.value) {}
        ~CMyistream_iterator() {}

        const T& operator*() const { return value; }
        const T* operator->() const { return &value; }
        CMyistream_iterator<T,charT,traits,Distance>& operator++() 
        {
            if (in_stream && !(*in_stream >> value)) in_stream=0;
            return *this;
        }
        CMyistream_iterator<T, charT, traits, Distance> operator++(int) 
        {
            istream_iterator<T, charT, traits, Distance> tmp = *this;
            ++*this;
            return tmp;
        }
};

int main()
{
    CMyistream_iterator<int> inputInt(cin);
    int n1,n2,n3;
    n1 = * inputInt; //读入 n1
    int tmp = * inputInt;
    cout << tmp << endl;
    inputInt ++;
    n2 = * inputInt; //读入 n2
    inputInt ++;
    n3 = * inputInt; //读入 n3
    cout << n1 << "," << n2<< "," << n3 << endl;
    CMyistream_iterator<string> inputStr(cin);
    string s1,s2;
    s1 = * inputStr;
    inputStr ++;
    s2 = * inputStr;
    cout << s1 << "," << s2 << endl;
    system("pause");
    return 0;
}