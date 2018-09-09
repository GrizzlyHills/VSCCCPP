/*
编程题 List

描述
写一个程序完成以下命令：

new id ——新建一个指定编号为id的序列(id<10000)

add id num——向编号为id的序列加入整数num

merge id1 id2——合并序列id1和id2中的数，并将id2清空

unique id——去掉序列id中重复的元素

out id ——从小到大输出编号为id的序列中的元素，以空格隔开

输入
第一行一个数n，表示有多少个命令( n＜＝２０００００)。以后n行每行一个命令。

输出
按题目要求输出。

样例输入
16
new 1
new 2
add 1 1
add 1 2
add 1 3
add 2 1
add 2 2
add 2 3
add 2 4
out 1
out 2
merge 1 2
out 1
out 2
unique 1
out 1

样例输出
1 2 3 
1 2 3 4
1 1 2 2 3 3 4

1 2 3 4
*/

#include <iostream>
#include <iterator>
#include <list>
#include <vector>
using namespace std;
list<int> &FindList(vector< list<int> > &l, int id)
{
    int tmp = l.size();
    if (tmp > 0)
    {
        vector< list<int> >::iterator i;
        i = l.begin();
        return *(i + id - 1);
    }
};
int main()
{
    int n;
    cin >> n;
    vector< list<int> > a;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        if (s == "new")
        {
            int id;
            cin >> id;
            a.push_back(list<int>());
        }
        else if (s == "add")
        {
            int id, num;
            cin >> id >> num;
            list<int> &temp = FindList(a, id);
            temp.push_back(num);
            temp.sort();
        }
        else if (s == "merge")
        {
            int id1, id2;
            cin >> id1 >> id2;
            list<int> &temp1 = FindList(a, id1);
            list<int> &temp2 = FindList(a, id2);
            temp1.merge(temp2);
        }
        else if (s == "unique")
        {
            int id;
            cin >> id;
            list<int> &temp = FindList(a, id);
            temp.unique();
        }
        else if (s == "out")
        {
            int id;
            cin >> id;
            list<int> &temp = FindList(a, id);
            temp.sort();
            if (temp.size() > 0)
            {
                list<int>::iterator i;
                for (i = temp.begin(); i != temp.end(); ++i)
                {
                    cout << *i << " ";
                }
            }
            cout << endl;
        }
    }
    system("pause");
    return 0;
}