/*
 * @Author: GrizzlyHills 
 * @Date: 2017-08-20 02:11:54 
 * @Last Modified by:   GrizzlyHills 
 * @Last Modified time: 2017-08-20 02:11:54 
 */

/*
编程题＃5： 热血格斗场

描述
为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家热血格斗场。
格斗场实行会员制，但是新来的会员不需要交入会费，而只要同一名老会员打一场表演赛，证明自己的实力。
我们假设格斗的实力可以用一个正整数表示，成为实力值。另外，每个人都有一个唯一的id，也是一个正整数。
为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，即比赛双方的实力值之差的绝对值越小越好，
如果有两个人的实力值与他差别相同，则他会选择比他弱的那个（显然，虐人比被虐好）。
不幸的是，Facer一不小心把比赛记录弄丢了，但是他还保留着会员的注册记录。现在请你帮facer恢复比赛纪录，按照时间顺序依次输出每场比赛双方的id。

输入
第一行一个数n(0 < n <=100000)，表示格斗场新来的会员数（不包括facer）。
以后n行每一行两个数，按照入会的时间给出会员的id和实力值。一开始，facer就算是会员，id为1，实力值1000000000。输入保证两人的实力值不同。

输出
N行，每行两个数，为每场比赛双方的id，新手的id写在前面。

样例输入
3
2 1
3 3
4 2

样例输出
2 1
3 2
4 2
*/

#include <iostream>
#include <map>
#include <cmath>
using namespace std;

typedef map<int, int> MAP;

int main()
{
    MAP::key_type strength;
    MAP::mapped_type id;
    MAP member;
    pair<MAP::iterator, bool> pairs;//创建pair模板类的对象

    member[1000000000] = 1;//插入数据
    int id1 = 0, id2 = 0, s1 = 0, s2 = 0;//记录实力左右与他最为接近的人
    id1 = 1;
    s1 = 1000000000;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> id >> strength;//scanf("%d %d", &id, &strength);
        pairs = member.insert(MAP::value_type(strength, id));//插入数据并取得其迭代指针
        MAP::iterator i = pairs.first;

        if (i == member.begin())//如果其实力值最小
        {
            i++;
            cout << id << ' ' << i->second << endl;//printf("%d %d\n", id, i->second);
            continue;
        }
        else
        {
            i--;
            id1 = i->second;//得到比其实力小的邻居
            s1 = i->first;
            i++;

            i++;
            id2 = i->second;//得到比其实力小的邻居
            s2 = i->first;

            if (abs(s2 - strength) == abs(s1 - strength))
            {
                if (s1 < s2)
                {
                    cout << id << ' ' << id1 << endl;
                }
                else
                {
                    cout << id << ' ' << id2 << endl;
                }
            }
            else if ((abs(s1 - strength) < abs(s2 - strength)) || i == member.end())
            {
                cout << id << ' ' << id1 << endl;
            }
            else
            {
                cout << id << ' ' << id2 << endl;
            }
        }       
    }
    system("pause");
    return 0;
}
