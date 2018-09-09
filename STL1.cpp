/*
编程题＃1

描述
下面的程序输出结果是:
1 2 6 7 8 9

请填空：
#include <iostream> 
#include <iterator> 
#include <set> 
using namespace std;
int main() { 
    int a[] = {8,7,8,9,6,2,1}; 
// 在此处补充你的代码
    ostream_iterator<int> o(cout," ");
    copy( v.begin(),v.end(),o); 
    return 0;
}

输入
无

输出
1 2 6 7 8 9

样例输入
无

样例输出
1 2 6 7 8 9
*/

#include <iostream>
#include <iterator>
#include <set>
using namespace std;
int main()
{
    int a[] = {8, 7, 8, 9, 6, 2, 1};

    // 在此处补充你的代码
    set<int> v(a, a + 7);

    ostream_iterator<int> o(cout, " ");
    copy(v.begin(), v.end(), o);

    cout << endl;
    set<int>::iterator i;
    for (i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }

    cout << endl;
    std::ostream_iterator<int> i1(std::cout, ", ");
    std::fill_n(i1, 5, -1);
    std::ostream_iterator<double> i2(std::cout);
    *i2++ = 3.14;

    system("pause");
    return 0;
}