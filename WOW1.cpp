/*
编程题＃4：魔兽世界之一：备战

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
红司令部，City 1，City 2，……，City n，蓝司令部
两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。
双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。
武士在刚降生的时候有一个生命值。
在每个整点，双方的司令部中各有一个武士降生。
红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
制造武士需要生命元。
制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。
如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。
（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在10点整，红方司令部停止制造武士
输出事件时：
首先按时间顺序输出；
同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数，代表测试数据组数。
每组测试数据共两行。
第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入
1
20
3 4 5 6 7

样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors
*/
/*
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
class wushiRed
{
  public:
    static int wushiNum[6];
    int type; //武士种类 0 dragon 、1 ninja、2 iceman、3 lion、4 wolf
    int no;   //编号
    int life; //生命值
    int gong; //攻击力
    wushiRed(int t, int n, int l, int g = 0) : type(t), no(n + 1), life(l), gong(g)
    {
        wushiNum[5]++; //总数
        wushiNum[t]++; //对应武士种类
    }
};
class wushiBlue
{
  public:
    int type; //武士种类 0 dragon 、1 ninja、2 iceman、3 lion、4 wolf
    int no;   //编号
    int life; //生命值
    int gong; //攻击力
    static int wushiNum[6];
    wushiBlue(int t, int n, int l, int g = 0) : type(t), no(n + 1), life(l), gong(g)
    {
        wushiNum[5]++; //总数
        wushiNum[t]++; //对应武士种类
    }
};
int minLife(int array[], int n)
{
    int min = array[0];
    for (int i = 1; i < n; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }
    }
    return min;
}
int wushiRed::wushiNum[] = {0};
int wushiBlue::wushiNum[] = {0};
int main()
{
    //freopen("in.txt","r",stdin);
    int testn;         //测试数据组数
    int casen = 0;     //目前测试组数
    int totalLife;     //总的生命元
    int redLife;       //红魔生命元
    int blueLife;      //蓝魔生命元
    int redWushi = 0;  //当前建造红魔武士次序号
    int blueWushi = 0; //当前建造蓝魔武士次序号
    string wushiName[] = {"dragon", "ninja", "iceman", "lion", "wolf"};
    int redWushiSeq[] = {2, 3, 4, 1, 0};  //红魔武士顺序
    int blueWushiSeq[] = {3, 0, 1, 2, 4}; //蓝魔武士顺序
    int wushiLife[5];                     //武士的生命值数组
    bool redStop = false;                 //红魔是否停止
    bool blueStop = false;                //蓝魔是否停止
    int minWushiLife = 0;                 //武士生命值的最小值
    int time = 0;                         //时刻
    cin >> testn;                         //输入测试数据组数
    while (testn > casen)
    {
        memset(wushiRed::wushiNum, 0, sizeof(int) * 6);
        memset(wushiBlue::wushiNum, 0, sizeof(int) * 6);
        time = 0;
        //输入总生命元和武士生命值
        cin >> totalLife >> wushiLife[0] >> wushiLife[1] >> wushiLife[2] >> wushiLife[3] >> wushiLife[4];
        casen++;                              //当前测试数据组
        cout << "Case:" << casen << endl;     //输出当前测试数据组
        minWushiLife = minLife(wushiLife, 5); //求出武士生命最小值
        //cout<<"最小武士生命："<<minWushiLife<<endl;
        redLife = totalLife;  //红魔目前的生命元
        blueLife = totalLife; //蓝魔目前的生命元
        redWushi = 0;         //红魔循环建造武士次序号
        blueWushi = 0;        //蓝魔循环建造武士次序号
        redStop = false;
        blueStop = false;
        while (!redStop || !blueStop) //红魔或者蓝魔有一方还没有停止建造
        {
            if (!redStop && redLife >= 0) //红魔还有生命元并且没有停止建造
            {
                int wType = redWushiSeq[redWushi]; //当前准备建造的武士种类
                //cout<<casen<<" 红魔剩余生命:"<<redLife <<"当前武士生命:"<<wushiLife[wType]<<"最小武士生命："<<minWushiLife<<endl;
                if (redLife >= wushiLife[wType])
                {
                    wushiRed wRed(wType, wushiRed::wushiNum[5], wushiLife[wType]);
                    //cout << "004 blue lion 5 born with strength 5,2 lion in red headquarter" << endl;
                    cout.fill('0'); //设置填充字符
                    cout.width(3);  //设置域宽
                    cout << time;
                    cout << " red " << wushiName[wType] << " " << wRed.no << " born with strength " << wushiLife[wType] << "," 
                         << wushiRed::wushiNum[wType] << " " << wushiName[wType] << " in red headquarter" << endl;
                    redLife -= wushiLife[wType];
                    redWushi = (redWushi + 1) % 5; //下一个
                }
                else if (redLife >= minWushiLife)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        redWushi = (redWushi + 1) % 5; //下一个
                        wType = redWushiSeq[redWushi];
                        if (redLife >= wushiLife[wType]) //造武士
                        {
                            wushiRed wRed(wType, wushiRed::wushiNum[5], wushiLife[wType]);
                            //cout << "004 blue lion 5 born with strength 5,2 lion in red headquarter" << endl;
                            cout.fill('0'); //设置填充字符
                            cout.width(3);  //设置域宽
                            cout << time;
                            cout << " red " << wushiName[wType] << " " << wRed.no << " born with strength " << wushiLife[wType] << "," 
                                 << wushiRed::wushiNum[wType] << " " << wushiName[wType] << " in red headquarter" << endl;
                            redLife -= wushiLife[wType];
                            redWushi = (redWushi + 1) % 5; //下一个
                            break;
                        }
                    }
                }
                else
                {
                    redStop = true;
                    cout.fill('0'); //设置填充字符
                    cout.width(3);  //设置域宽
                    cout << time;
                    cout << " red headquarter stops making warriors" << endl;
                }
            }

            if (!blueStop && blueLife >= 0) //蓝魔还有生命元并且没有停止建造
            {
                int wType = blueWushiSeq[blueWushi]; //当前准备建造的武士种类
                //cout<<"蓝魔剩余生命:"<<blueLife <<"当前武士生命:"<<wushiLife[wType]<<"最小武士生命："<<minWushiLife<<endl;
                if (blueLife >= wushiLife[wType])
                {
                    wushiBlue wBlue(wType, wushiBlue::wushiNum[5], wushiLife[wType]);
                    //cout << "004 blue lion 5 born with strength 5,2 lion in red headquarter" << endl;
                    cout.fill('0'); //设置填充字符
                    cout.width(3);  //设置域宽
                    cout << time;
                    cout << " blue " << wushiName[wType] << " " << wBlue.no << " born with strength " << wushiLife[wType] << "," 
                         << wushiBlue::wushiNum[wType] << " " << wushiName[wType] << " in blue headquarter" << endl;
                    blueLife -= wushiLife[wType];
                    blueWushi = (blueWushi + 1) % 5;
                }
                else if (blueLife >= minWushiLife)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        blueWushi = (blueWushi + 1) % 5;
                        wType = blueWushiSeq[blueWushi];
                        if (blueLife >= wushiLife[wType]) //造武士
                        {
                            wushiBlue wBlue(wType, wushiBlue::wushiNum[5], wushiLife[wType]);
                            //cout << "004 blue lion 5 born with strength 5,2 lion in red headquarter" << endl;
                            cout.fill('0'); //设置填充字符
                            cout.width(3);  //设置域宽
                            cout << time;
                            cout << " blue " << wushiName[wType] << " " << wBlue.no << " born with strength " << wushiLife[wType] << "," 
                                 << wushiBlue::wushiNum[wType] << " " << wushiName[wType] << " in blue headquarter" << endl;
                            blueLife -= wushiLife[wType];
                            blueWushi = (blueWushi + 1) % 5;
                            break;
                        }
                    }
                }
                else
                {
                    blueStop = true;
                    cout.fill('0'); //设置填充字符
                    cout.width(3);  //设置域宽
                    cout << time;
                    cout << " blue headquarter stops making warriors" << endl;
                }
            }
            time++; //下一时刻
        }
    }
    system("pause");
}
*/
//下面这个程序比上面这个好
//两军司令部都会制造武士有 dragon ninja iceman lion wolf 五种 每种武士都有编号（number），生命值（health） ，攻击力（attack）三种属性
//红方司令部按照 iceman lion wolf ninja gradon的顺序制造武士
//蓝方司令部按照 lion gradon ninja iceman wolf的顺序制造武士
//每制造一个生命值为M的武士司令部的生命值就要减少m
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class hero
{
  public:
    void set_health()
    {
        int h;
        cin >> h;
        health = h;
    }
    int print_health()
    {
        return health;
    }

  private:
    int number;
    int health;
    int attack;
} dragon, ninja, iceman, lion, wolf;
int main()
{
    int s; //测试组数
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int counter = 1; //计数器 计算英雄生成的周期
        int R, B;        //红蓝司令部的生命值
        int r[5], b[5];  //储存五种对象分别的生命值
        int time = 0;    //创建时间
        int number = 1;
        string s_r[5] = {"iceman", "lion", "wolf", "ninja", "dragon"}; //将对象名用字符串表示
        string s_b[5] = {"lion", "dragon", "ninja", "iceman", "wolf"};
        cin >> R; //输入生命值
        B = R;    // 红蓝司令部的生命值相等

        //依次输入 dragon ninja iceman lion wolf的生命值
        dragon.set_health();
        b[1] = r[4] = dragon.print_health();
        ninja.set_health();
        b[2] = r[3] = ninja.print_health();
        iceman.set_health();
        b[3] = r[0] = iceman.print_health();
        lion.set_health();
        b[0] = r[1] = lion.print_health();
        wolf.set_health();
        b[4] = r[2] = wolf.print_health();
        cout << "case:" << i + 1 << endl;
        
        int first_r = 1, first_b = 1; //设置计数器，控制红方/蓝方最后一行只输出一次终止信息
        for (int i = 0;; i++, time++, number++)
        { //循环输出创建英雄的信息

            R -= r[i];
            if (R >= 0)
            {
                cout << setfill('0') << setw(3) << time << " "
                     << "red"
                     << " " << s_r[i] << " " << number << " born with strength " << r[i] << "," << counter << " " << s_r[i] << " in red headquarter" << endl;
            }
            else
            {
                if (first_r)
                {
                    cout << setfill('0') << setw(3) << time << " red headquarter stops making warriors" << endl;
                    first_r = 0;
                }
            }
            B -= b[i];
            if (B >= 0)
            {
                cout << setfill('0') << setw(3) << time << " "
                     << "blue"
                     << " " << s_b[i] << " " << number << " born with strength " << b[i] << "," << counter << " " << s_b[i] << " in blue headquarter" << endl;
            }
            else
            {
                if (first_b)
                {
                    cout << setfill('0') << setw(3) << time << " bule headquarter stops making warriors" << endl;
                    first_b = 0;
                }
            }
            if (i == 4)
            {
                i = -1;
                counter++;
            }
            if (first_r == 0 && first_b == 0)
            {
                break;
            }
        }
    }
    system("pause");
    return 0;
}