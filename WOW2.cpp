/*
编程题＃2： 魔兽世界之二：装备

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
红司令部，City 1，City 2，……，City n，蓝司令部
两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。
有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。
不同的武士有不同的特点。
dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。
dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。
iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
wolf没特点。
请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。
武士在刚降生的时候有一个生命值。
在每个整点，双方的司令部中各有一个武士降生。
红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。
蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。
制造武士需要生命元。
制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。
如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。
(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
如果造出的是dragon，那么还要输出一行，例：
It has a arrow,and it's morale is 23.34
表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
如果造出的是ninjia，那么还要输出一行，例：
It has a bomb and a arrow
表示该ninjia降生时得到了bomb和arrow。
如果造出的是iceman，那么还要输出一行，例：
It has a sword
表示该iceman降生时得到了sword。
如果造出的是lion，那么还要输出一行，例：
It's loyalty is 24
表示该lion降生时的忠诚度是24。

2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在 10点整，红方司令部停止制造武士
输出事件时：
首先按时间顺序输出；
同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数,代表测试数据组数。
每组测试数据共两行。
第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入
1
20
3 4 5 6 7

样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
004 blue headquarter stops making warriors
*/
//此题考查的点很多，要多复习
// 思路：
// 从整体上说一下这个程序还有几个需要改进的细节：
// （1）关于headquarters，正常来说我们应该给它做成Camp的继承类，在这个题里简单只有两个阵营可以用简单的0、1来标示，如果将来扩展了就会比较麻烦。
// （2）关于红蓝两个阵营的maker数组，按理这是属于“私人信息”应当放在每个headquarter的内部，不能让其他阵营知晓，这就要求我们实现（1）的假象。
// （3）感觉这个题目其实是非常形象的表达了面向对象程序的逻辑，我们可以想象有两个阵营，然后他们各自有一个兵工厂，每个阵营的工厂都有各自的造兵信息，
//     以及自己的剩余生命元，然后对于每一个新创造出来的Warrior，兵工厂会根据自己的记录情况赋予该Warrior相应的信息————这里传递的是单向的信息，
//     而不是双向的，即Camp掌握Warrior的信息并传给他，Warrior在这里只能作为接收方接受。
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int M; //两大阵营开始都有M个生命元
int r_maker[5] = {2, 3, 4, 1, 0};
int b_maker[5] = {3, 0, 1, 2, 4};
string weapon[3] = {"sword", "bomb", "arrow"};
int HP[5];
/*
dragon: 0
ninja : 1
iceman: 2
lion  : 3
wolf  : 4
*/

/*
red :0
blue:1
*/
class Warrior
{
  private:
    int num; //勇士编号
    int hp;  //勇士生命值
  public:
    Warrior(int from, int name, int warrior_t, int left_t);
};

Warrior::Warrior(int from, int name, int warrior_t, int left_t)
{
    //阵营名
    string camp_name;
    if (from == 0)
        camp_name = "red";
    else
        camp_name = "blue";
    //武士名
    string warrior_name;
    switch (name)
    {
        case 0:
            warrior_name = "dragon";
            break;
        case 1:
            warrior_name = "ninja";
            break;
        case 2:
            warrior_name = "iceman";
            break;
        case 3:
            warrior_name = "lion";
            break;
        case 4:
            warrior_name = "wolf";
            break;
    }
    //武士编号
    int warrior_num = warrior_t;
    //生命值
    int life = HP[name];
    //各自阵营left
    int left = left_t;
    //输出所有的信息
    cout << camp_name << ' ' << warrior_name << ' ' << warrior_num << ' ';
    cout << "born with strength " << life << ',' << left << ' ' << warrior_name;
    cout << " in " << camp_name << " headquarter" << endl;
    //最后设置该warrior的参数
    num = warrior_num;
    hp = life;
}

class Dragon : public Warrior
{
  private:
    double morale;
    int weapon_num;
    string weapon_name;

  public:
    Dragon(int mark, int num1, int num2, int before_left);
};

Dragon::Dragon(int mark, int num1, int num2, int before_left) : Warrior(mark, 0, num1, num2)
{
    int left = before_left - HP[0];
    morale = (double)left / HP[0];
    int cur_num = num1; //当前的编号
    weapon_num = cur_num % 3;
    weapon_name = weapon[weapon_num];
    //输出Dragon特有的信息
    cout << "It has a " << weapon_name << ',' << "and it's morale is ";
    printf("%.2f\n", morale);
}

class Ninja : public Warrior
{
  private:
    int weapon_num1, weapon_num2;
    string weapon_name1, weapon_name2;

  public:
    Ninja(int mark, int num1, int num2);
};

Ninja::Ninja(int mark, int num1, int num2) : Warrior(mark, 1, num1, num2)
{
    int cur_n = num1; //当前武士编号
    weapon_num1 = cur_n % 3;
    weapon_num2 = (cur_n + 1) % 3;
    weapon_name1 = weapon[weapon_num1];
    weapon_name2 = weapon[weapon_num2];
    //输出Ninja特有的信息
    cout << "It has a " << weapon_name1 << " and a " << weapon_name2 << endl;
}

class Iceman : public Warrior
{
  private:
    int weapon_num;
    string weapon_name;

  public:
    Iceman(int mark, int num1, int num2);
};

Iceman::Iceman(int mark, int num1, int num2) : Warrior(mark, 2, num1, num2)
{
    int cur_n = num1;
    weapon_num = cur_n % 3;
    weapon_name = weapon[weapon_num];
    //输出Ninja特有的信息
    cout << "It has a " << weapon_name << endl;
}

class Lion : public Warrior
{
  private:
    int loyalty;

  public:
    Lion(int mark, int num1, int num2, int before_left);
};

Lion::Lion(int mark, int num1, int num2, int before_left) : Warrior(mark, 3, num1, num2)
{
    loyalty = before_left - HP[3];
    //输出Ninja特有的信息
    cout << "It's loyalty is " << loyalty << endl;
}

class Wolf : public Warrior
{
  public:
    Wolf(int mark, int num1, int num2) : Warrior(mark, 4, num1, num2) {}
};

class Camp
{
  private:
    int mark;      //阵营标记
    int M_left[2]; //两个阵营剩余的生命元
    int state;
    int num[2];      //两个阵营分别现有的武士数量
    int w_num[5][2]; //两个阵营各个武士的现有数量
  public:
    Camp(int nn, int m);
    ~Camp();
    void change(int name);         //make完一个warrior后要改变相应的参数
    void make(int from, int name); //核心函数，制造新的武士
    int alive();
    int get(int mark);
};

Camp::Camp(int nn, int m)
{
    mark = nn;
    M_left[nn] = m;
    state = 1;
    num[0] = num[1] = 1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 2; j++)
            w_num[i][j] = 0;
}

Camp::~Camp()
{
    state = 0;
    if (mark == 0)
        cout << "red headquarter stops making warriors" << endl;
    else
        cout << "blue headquarter stops making warriors" << endl;
}

void Camp::make(int from, int name)
{
    int n3, n4;
    n3 = num[mark];             //当前阵营现有的武士数量
    n4 = w_num[name][mark] + 1; //当前阵营该武士现有的数量
    if (name == 0)
        Dragon tmp(from, n3, n4, M_left[from]);
    else if (name == 1)
        Ninja tmp(from, n3, n4);
    else if (name == 2)
        Iceman tmp(from, n3, n4);
    else if (name == 3)
        Lion tmp(from, n3, n4, M_left[from]);
    else
        Wolf tmp(from, n3, n4);
    //    Warrior tmp(from,name,n3,n4);
    change(name);
}

void Camp::change(int name)
{
    num[mark]++;
    M_left[mark] -= HP[name];
    w_num[name][mark]++;
}

int Camp::get(int mark)
{
    return M_left[mark];
}

int Camp::alive()
{
    return state;
}

int main()
{
    int C = 0; //Case:测试样例的数量
    int T;
    cin >> T;
    while (T--)
    {
        int order[2] = {0, 0}; //两大阵营现在分别造到第几个
        cin >> M;
        for (int i = 0; i < 5; i++)
            cin >> HP[i];
        cout << "Case:" << ++C << endl;
        //创建两个阵营
        Camp *R = new Camp(0, M);
        Camp *B = new Camp(1, M);
        Camp *P;
        //默认进行999秒循环，内部中止
        for (int T = 0; T <= 999; T++)
        {
            if (!R && !B)
                break;
            for (int j = 0; j < 2; j++)
            {
                //确定阵营
                if (j == 0)
                    P = R;
                else
                    P = B;
                if (P->alive())
                {
                    //确定本次要创建新士兵
                    int flag = 0;
                    int nn;
                    int cur, tmp;
                    int left = P->get(j);
                    int tt = (order[j] + 5) % 5;                //这个表达方式考虑到了多个士兵的制造，很好~
                    if (j == 0)
                        tmp = r_maker[tt];
                    else
                        tmp = b_maker[tt];
                    if (left >= HP[tmp])
                        cur = tmp;
                    else
                    {
                        int cnt = 1;
                        for (int i = tt + 1; cnt <= 4; i++, cnt++)
                        {
                            nn = (i + 5) % 5;
                            int n;
                            if (j == 0)
                                n = r_maker[nn];
                            else
                                n = b_maker[nn];
                            if (left >= HP[n])
                            {
                                cur = n;
                                flag = 1;
                                break;
                            }
                        }
                        if (cnt == 5)
                        {
                            printf("%03d ", T);
                            delete P;                       //停止制造
                            continue;                       //该司令部的制造停止，下面的不再执行了
                        }
                    }
                    //创建这个士兵并做好相应数据的记录
                    printf("%03d ", T);
                    P->make(j, cur);
                    if (flag)
                        order[j] = nn + 1;
                    else
                        order[j]++; //当前阵营下一个要创造的武士
                }
            }
        }
    }
    system("pause");
    return 0;
}
