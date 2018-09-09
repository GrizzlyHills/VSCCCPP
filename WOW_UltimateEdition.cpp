/*
编程题＃4： 魔兽世界终极版

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 2000ms 内存限制: 65536kB

描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市，城市从西向东依次编号为1,2,3 .... N ( N <= 20 )。
红魔军的司令部算作编号为0的城市，蓝魔军的司令部算作编号为N+1的城市。司令部有生命元，用于制造武士。

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

武士在刚降生的时候有一个初始的生命值，生命值在战斗中会发生变化，如果生命值减少到0（生命值变为负数时应当做变为0处理），则武士死亡（消失）。

有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。
每次战斗只有一方发起主动进攻一次。被攻击者生命值会减去进攻者的攻击力值和进攻者手中sword的攻击力值。
被进攻者若没死，就会发起反击，被反击者的生命值要减去反击者攻击力值的一半(去尾取整)和反击者手中sword的攻击力值。反击可能致敌人于死地。

如果武士在战斗中杀死敌人（不论是主动进攻杀死还是反击杀死），则其司令部会立即向其发送8个生命元作为奖励，使其生命值增加8。
当然前提是司令部得有8个生命元。如果司令部的生命元不足以奖励所有的武士，则优先奖励距离敌方司令部近的武士。

如果某武士在某城市的战斗中杀死了敌人，则该武士的司令部立即取得该城市中所有的生命元。
注意，司令部总是先完成全部奖励工作，然后才开始从各个打了胜仗的城市回收生命元。对于因司令部生命元不足而领不到奖励的武士，司令部也不会在取得战利品生命元后为其补发奖励。

如果一次战斗的结果是双方都幸存(平局)，则双方都不能拿走发生战斗的城市的生命元。

城市可以插旗子，一开始所有城市都没有旗子。在插红旗的城市，以及编号为奇数的无旗城市，由红武士主动发起进攻。
在插蓝旗的城市，以及编号为偶数的无旗城市，由蓝武士主动发起进攻。

当某个城市有连续两场战斗都是同一方的武士杀死敌人(两场战斗之间如果有若干个战斗时刻并没有发生战斗，则这两场战斗仍然算是连续的；
但如果中间有平局的战斗，就不算连续了) ，那么该城市就会插上胜方的旗帜，若原来插着败方的旗帜，则败方旗帜落下。
旗帜一旦插上，就一直插着，直到被敌人更换。一个城市最多只能插一面旗帜，旗帜没被敌人更换前，也不会再次插同颜色的旗。

各种武器有其特点：

sword武器的初始攻击力为拥有它的武士的攻击力的20%（去尾取整）。但是sword每经过一次战斗(不论是主动攻击还是反击)，就会变钝，攻击力变为本次战斗前的80% (去尾取整)。
sword攻击力变为0时，视为武士失去了sword。如果武士降生时得到了一个初始攻击力为0的sword，则视为武士没有sword.

arrow有一个攻击力值R。如果下一步要走到的城市有敌人，那么拥有arrow的武士就会放箭攻击下一个城市的敌人（不能攻击对方司令部里的敌人）而不被还击。
arrow使敌人的生命值减少R，若减至小于等于0，则敌人被杀死。arrow使用3次后即被耗尽，武士失去arrow。两个相邻的武士可能同时放箭把对方射死。

拥有bomb的武士，在战斗开始前如果判断自己将被杀死（不论主动攻击敌人，或者被敌人主动攻击都可能导致自己被杀死，而且假设武士可以知道敌人的攻击力和生命值），
那么就会使用bomb和敌人同归于尽。武士不预测对方是否会使用bomb。

武士使用bomb和敌人同归于尽的情况下，不算是一场战斗，双方都不能拿走城市的生命元，也不影响城市的旗帜。

不同的武士有不同的特点。

dragon可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，
其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。dragon 在一次在它主动进攻的战斗结束后，如果还没有战死，而且士气值大于0.8，就会欢呼。
dragon每取得一次战斗的胜利(敌人被杀死)，士气就会增加0.2，每经历一次未能获胜的战斗，士气值就会减少0.2。士气增减发生在欢呼之前。

ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。ninja 挨打了也从不反击敌人。

iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。iceman 每前进两步，在第2步完成的时候，生命值会减少9，攻击力会增加20。
但是若生命值减9后会小于等于0，则生命值不减9,而是变为1。即iceman不会因走多了而死。

lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。每经过一场未能杀死敌人的战斗，忠诚度就降低K。
忠诚度降至0或0以下，则该lion逃离战场,永远消失。但是已经到达敌人司令部的lion不会逃跑。Lion在己方司令部可能逃跑。
lion 若是战死，则其战斗前的生命值就会转移到对手身上。所谓“战斗前”，就是每个小时的40分前的一瞬间。

wolf降生时没有武器，但是在战斗中如果获胜（杀死敌人），就会缴获敌人的武器，但自己已有的武器就不缴获了。被缴获的武器当然不能算新的，已经被用到什么样了，就是什么样的。

以下是不同时间会发生的不同事件：

在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某武士，那么司令部就等待，直到获得足够生命元后的第一个整点，才制造该武士。
例如，在2:00，红方司令部本该制造一个 wolf ，如果此时生命元不足，那么就会等待，直到生命元足够后的下一个整点，才制造一个 wolf。

在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。

在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。

在每个小时的第20分：每个城市产出10个生命元。生命元留在城市，直到被武士取走。

在每个小时的第30分：如果某个城市中只有一个武士，那么该武士取走该城市中的所有生命元，并立即将这些生命元传送到其所属的司令部。

在每个小时的第35分，拥有arrow的武士放箭，对敌人造成伤害。放箭事件应算发生在箭发出的城市。注意，放箭不算是战斗，因此放箭的武士不会得到任何好处。
武士在没有敌人的城市被箭射死也不影响其所在城市的旗帜更换情况。

在每个小时的第38分，拥有bomb的武士评估是否应该使用bomb。如果是，就用bomb和敌人同归于尽。

在每个小时的第40分：在有两个武士的城市，会发生战斗。 如果敌人在5分钟前已经被飞来的arrow射死，那么仍然视为发生了一场战斗，
而且存活者视为获得了战斗的胜利。此情况下不会有“武士主动攻击”，“武士反击”，“武士战死”的事件发生，但战斗胜利后应该发生的事情都会发生。
如Wolf一样能缴获武器，旗帜也可能更换，等等。在此情况下,Dragon同样会通过判断是否应该轮到自己主动攻击来决定是否欢呼。

在每个小时的第50分，司令部报告它拥有的生命元数量。

在每个小时的第55分，每个武士报告其拥有的武器情况。

武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。

任何一方的司令部里若是出现了2个敌人，则认为该司令部已被敌人占领。

任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。

给定一个时间，要求你将从0点0分开始到此时间为止的所有事件按顺序输出。事件及其对应的输出样例如下：


1) 武士降生
输出样例： 000:00 blue lion 1 born

表示在 0点0分，编号为1的蓝魔lion武士降生
如果造出的是dragon，那么还要多输出一行，例：

000:00 blue dragon 1 born
Its morale is 23.34

表示该该dragon降生时士气是23. 34(四舍五入到小数点后两位)

如果造出的是lion，那么还要多输出一行，例:
000:00 blue lion 1 born
Its loyalty is 24

表示该lion降生时的忠诚度是24

2) lion逃跑
输出样例： 000:05 blue lion 1 ran away 
表示在 0点5分，编号为1的蓝魔lion武士逃走

3) 武士前进到某一城市
输出样例： 000:10 red iceman 1 marched to city 1 with 20 elements and force 30
表示在 0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30
对于iceman,输出的生命值和攻击力应该是变化后的数值

4)武士放箭
输出样例： 000:35 blue dragon 1 shot
表示在 0点35分，编号为1的蓝魔dragon武士射出一支箭。如果射出的箭杀死了敌人，则应如下输出：
000:35 blue dragon 1 shot and killed red lion 4
表示在 0点35分，编号为1的蓝魔dragon武士射出一支箭，杀死了编号为4的红魔lion。

5)武士使用bomb
输出样例： 000:38 blue dragon 1 used a bomb and killed red lion 7
表示在 0点38分，编号为1的蓝魔dragon武士用炸弹和编号为7的红魔lion同归于尽。

6) 武士主动进攻
输出样例：000:40 red iceman 1 attacked blue lion 1 in city 1 with 20 elements and force 30
表示在0点40分，1号城市中，红魔1号武士iceman 进攻蓝魔1号武士lion,在发起进攻前，红魔1号武士iceman生命值为20，攻击力为 30

7) 武士反击
输出样例：001:40 blue dragon 2 fought back against red lion 2 in city 1 
表示在1点40分，1号城市中，蓝魔2号武士dragon反击红魔2号武士lion

8) 武士战死
输出样例：001:40 red lion 2 was killed in city 1
被箭射死的武士就不会有这一条输出。

9) 武士欢呼
输出样例：003:40 blue dragon 2 yelled in city 4

10) 武士获取生命元( elements )
输出样例：001:40 blue dragon 2 earned 10 elements for his headquarter

11) 旗帜升起
输出样例：004:40 blue flag raised in city 4

12) 武士抵达敌军司令部
输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
(此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值

13) 司令部被占领
输出样例：003:10 blue headquarter was taken

14)司令部报告生命元数量
000:50 100 elements in red headquarter 
000:50 120 elements in blue headquarter
表示在0点50分，红方司令部有100个生命元，蓝方有120个

15)武士报告武器情况
000:55 blue wolf 2 has arrow(2),bomb,sword(23)
000:55 blue wolf 4 has no weapon
000:55 blue wolf 5 has sword(20)
表示在0点55分，蓝魔2号武士wolf有一支arrow（这支arrow还可以用2次），一个bomb，还有一支攻击力为23的sword。
蓝魔4号武士wolf没武器。
蓝魔5号武士wolf有一支攻击力为20的sword。
交代武器情况时，次序依次是：arrow,bomb,sword。如果没有某种武器，某种武器就不用提。报告时，先按从西向东的顺序所有的红武士报告，然后再从西向东所有的蓝武士报告。

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。

在一次战斗中有可能发生上面的 6 至 11 号事件。这些事件都算同时发生，其时间就是战斗开始时间。一次战斗中的这些事件，序号小的应该先输出。

两个武士同时抵达同一城市，则先输出红武士的前进事件，后输出蓝武士的。

显然，13号事件发生之前的一瞬间一定发生了12号事件。输出时，这两件事算同一时间发生，但是应先输出12号事件

虽然任何一方的司令部被占领之后，就不会有任何事情发生了。但和司令部被占领同时发生的事件，全都要输出。

输入
第一行是t,代表测试数据组数
每组样例共三行。
第一行，五个整数 M,N,R,K, T。其含义为：

每个司令部一开始都有M个生命元( 1 <= M <= 10000)
两个司令部之间一共有N个城市( 1 <= N <= 20 )
arrow的攻击力是R
lion每经过一场未能杀死敌人的战斗，忠诚度就降低K。
要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 5000

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于10000

输出
对每组数据，先输出一行：
Case n:
如对第一组数据就输出 Case1:
然后按恰当的顺序和格式输出到时间T为止发生的所有事件。每个事件都以事件发生的时间开头，时间格式是“时: 分”，“时”有三位，“分”有两位。

样例输入
1
20 1 10 10 1000
20 20 30 10 20
5 5 5 5 5
样例输出
Case 1:
000:00 blue lion 1 born
Its loyalty is 10
000:10 blue lion 1 marched to city 1 with 10 elements and force 5
000:30 blue lion 1 earned 10 elements for his headquarter
000:50 20 elements in red headquarter
000:50 20 elements in blue headquarter
000:55 blue lion 1 has no weapon
001:00 blue dragon 2 born
Its morale is 0.00
001:10 blue lion 1 reached red headquarter with 10 elements and force 5
001:10 blue dragon 2 marched to city 1 with 20 elements and force 5
001:30 blue dragon 2 earned 10 elements for his headquarter
001:50 20 elements in red headquarter
001:50 10 elements in blue headquarter
001:55 blue lion 1 has no weapon
001:55 blue dragon 2 has arrow(3)
002:10 blue dragon 2 reached red headquarter with 20 elements and force 5
002:10 red headquarter was taken
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
enum Knight_name
{
    dragon,
    ninja,
    iceman,
    lion,
    wolf
}; //武士名称
enum Weapon_name
{
    sword,
    bomb,
    arrow
};                                                                //武器名称
string Knight[5] = {"dragon", "ninja", "iceman", "lion", "wolf"}; //武士名称，输出使用
Knight_name Order[2][5] = {{iceman, lion, wolf, ninja, dragon},   //制造顺序
                           {lion, dragon, ninja, iceman, wolf}};
string Color[2] = {"red", "blue"};               //司令部颜色，输出使用
string Weapons_[3] = {"sword", "bomb", "arrow"}; //武器名称，输出使用
int Attack_[5];                                  //各武士初始攻击力
int Loyal_reduce;                                //lion未杀死敌人所减少士气
int Hour, Minute;                                //计时器
int Total_Minutes;                               //终止时间
int Life_Make[5];                                //制造各种武士所需生命元
int arrow_attack;                                //arrow攻击力
void Print_time()
{ //输出前面时间
    cout.width(3);
    cout.fill('0');
    cout << Hour << ':';
    cout.width(2);
    cout << Minute << ' ';
}
class City;
class Command;
class Weapon
{ //武器
  private:
    int name, sword_attack, arrow_usetime; //武器名称，sword攻击力，arrow剩余使用次数
  public:
    Weapon(int i, int satt) : name(i), sword_attack(satt), arrow_usetime(3) {} //武器状态初始化
    bool sword_dull()
    { //sword变钝
        sword_attack = int(sword_attack * 0.8);
        return sword_attack;
    }
    int &usetime() { return arrow_usetime; }
    int sw_atk() { return sword_attack; }
};
class Warrior
{ //士兵
  private:
    int Num, Life, Attack, Loyal, Step, l_life; //编号，生命力，攻击力，忠诚度，步数
    Knight_name name;                           //武士名称
    double Morale;                              //士气
    City *City_Belong_to;                       //所属城市
    Command *Command_Belong_to;                 //所属司令部
    bool If_win, If_kill;                       //战斗是否获胜，是否杀死敌人
    Weapon *weapon[3];                          //装备
  public:
    Warrior(int n, Knight_name &name_, int &life, int &t_life, Command *COMD)
    { //初始化士兵属性
        Num = n;
        name = name_;
        Life = life;
        Attack = Attack_[name];
        Step = 0;
        l_life = 0;
        weapon[0] = NULL;
        weapon[1] = NULL;
        weapon[2] = NULL;
        switch (name)
        {
        case dragon:
        case iceman:
            weapon[Num % 3] = new Weapon(Num % 3, int(Attack_[name] * 0.2));
            break;
        case ninja:
            weapon[Num % 3] = new Weapon(Num % 3, int(Attack_[name] * 0.2));
            weapon[(Num + 1) % 3] = new Weapon((Num + 1) % 3, int(Attack_[name] * 0.2));
            break;
        default:
            break;
        };
        if (weapon[sword])
            if (!weapon[sword]->sw_atk())
                weapon[sword] = NULL; //若初始武器攻击为0，则delete
        Morale = double(t_life) / double(Life);
        Loyal = t_life;
        If_win = false;
        If_kill = false;
        City_Belong_to = NULL;
        Command_Belong_to = COMD;
        cout << Knight[name] << ' ' << Num << " born\n";
        if (name == dragon)
        {
            cout << "Its morale is ";
            cout.precision(2);
            cout << fixed << Morale << endl;
        }
        if (name == lion)
        {
            cout << "Its loyalty is " << Loyal << endl;
        }
    }
    bool &IF_win() { return If_win; }
    int life() { return Life; }
    bool Minute_5();      //lion是否逃跑 输出
    void Minute_10(bool); //武士前进输出
    void Minute_30(int);  //获取城市生命元及输出
    void arrow_shot();    //使用弓箭输出
    void Be_shoted();     //被射中处理及输出
    void Change_City(City *Cp) { City_Belong_to = Cp; }
    void Morale_Change() { If_win ? Morale += 0.2 : Morale -= 0.2; }
    bool weapon_(Weapon_name name) { return weapon[name]; }
    void Use_bomb(Warrior *); //使用bomb输出
    int fight(Warrior *Wp)
    { //假设战斗，判断是否会获胜
        if (Life > 0 && Wp->Life > 0)
        {
            int swatk = 0;
            if (weapon[sword])
                swatk = weapon[sword]->sw_atk();
            if (Wp->Life - Attack - swatk > 0)
            {
                if (Wp->name == ninja)
                    return 0;
                else
                {
                    int E_swatk = 0;
                    if (Wp->weapon[sword])
                        E_swatk = (Wp->weapon[sword])->sw_atk();
                    if (Life - (Wp->Attack / 2) - E_swatk > 0)
                        return 0;
                    else
                        return -1;
                }
            }
            else
                return 1;
        }
        return 0;
    }
    bool bomb(Warrior *, int); //判断是否使用bomb
    void Fight(Warrior *);     //武士战斗处理及输出
    void Dead();               //武士死亡输出
    void account(Warrior *Wp)
    { //部分战后处理
        If_win = true;
        if (If_kill)
        {
            Wp->Dead();
            If_kill = false;
        }
        if (Wp->name == lion)
            Life += Wp->l_life;
        if (name == wolf)
            for (int i = 0; i < 3; ++i)
                if (Wp->weapon[i] && !weapon[i])
                {
                    weapon[i] = Wp->weapon[i];
                    Wp->weapon[i] = NULL;
                }
        Morale_Change();
    }
    void Reward(); //战胜后获取奖励
    void ADD(int); //所属司令部增加生命元
    void Loyal_Reduce() { Loyal -= Loyal_reduce; }
    void Report_weapon(); //报告武器使用情况
    ~Warrior()
    {
        for (int i = 0; i < 3; ++i)
            if (weapon[i])
                delete weapon[i];
    }
};
class City
{
  private:
    int Number, Life, Flag, Flag_G[2]; //城市编号，生命元，旗帜，各方士兵连续胜利场次
    Warrior *Warrior_In_City[2];

  public:
    int Num() { return Number; }
    int Life_() { return Life; }
    City(int N)
    {
        Number = N;
        Life = 0;
        Flag = -1; //-1 表示无旗城市
        Warrior_In_City[0] = NULL;
        Flag_G[0] = 0;
        Warrior_In_City[1] = NULL;
        Flag_G[1] = 0;
    }
    void Minute_5()
    { //处理逃跑lion
        for (int i = 0; i < 2; ++i)
            if (Warrior_In_City[i])
                if (Warrior_In_City[i]->Minute_5())
                {
                    delete Warrior_In_City[i];
                    Warrior_In_City[i] = NULL;
                }
    }
    void Move(City *Cp, int i)
    { //warrior前进
        Warrior_In_City[i] = Cp->Warrior_In_City[i];
        if (Warrior_In_City[i])
            Warrior_In_City[i]->Change_City(this);
    }
    void Move(Command *, int); //warrior进入敌方司令部
    void Move(Warrior *Wp, int i)
    { //warrior从command进入city
        Warrior_In_City[i] = Wp;
        if (Warrior_In_City[i])
            Warrior_In_City[i]->Change_City(this);
    }
    bool If_exist(int i) { return Warrior_In_City[i]; }
    void Minute_10()
    { //warrior前进输出
        if (Warrior_In_City[0])
            Warrior_In_City[0]->Minute_10(false);
        if (Warrior_In_City[1])
            Warrior_In_City[1]->Minute_10(false);
    }
    void Add_Life() { Life += 10; }
    void Minute_30()
    { //城内单独warrior获取生命元
        for (int i = 0; i < 2; ++i)
            if ((Warrior_In_City[i]) && (!Warrior_In_City[1 - i]))
            {
                Warrior_In_City[i]->Minute_30(Life);
                Life = 0;
                break;
            }
    }
    void Minute_35(City *Cp[])
    { //处理arrow事件
        for (int j = 0; j < 2; ++j)
            if (Warrior_In_City[j])
                if (Warrior_In_City[j]->weapon_(arrow))
                    if (Cp[1 - j])
                        if ((Cp[1 - j]->Warrior_In_City[1 - j]))
                        {
                            Warrior_In_City[j]->arrow_shot();
                            Cp[1 - j]->Warrior_In_City[1 - j]->Be_shoted();
                        }
    }
    void Minute_38()
    { //处理bomb事件，顺带处理35分钟时城市中两只warrior均被被射死的情况
        if (Warrior_In_City[0] && Warrior_In_City[1])
        {
            bool p = false;
            for (int i = 0; i < 2; ++i)
                if (Warrior_In_City[i]->weapon_(bomb))
                {
                    if (Flag == -1)
                        p = Warrior_In_City[i]->bomb(Warrior_In_City[1 - i], Number);
                    else
                        p = Warrior_In_City[i]->bomb(Warrior_In_City[1 - i], Flag + 1);
                    if (p)
                    {
                        delete Warrior_In_City[0];
                        Warrior_In_City[0] = NULL;
                        delete Warrior_In_City[1];
                        Warrior_In_City[1] = NULL;
                        break;
                    }
                }
            if (!p && Warrior_In_City[0]->life() <= 0 && Warrior_In_City[1]->life() <= 0)
            {
                delete Warrior_In_City[0];
                Warrior_In_City[0] = NULL;
                delete Warrior_In_City[1];
                Warrior_In_City[1] = NULL;
            }
        }
    }
    void Battle()
    { //战斗及输出，不进行生命元奖励、获取处理
        if (Warrior_In_City[0] && Warrior_In_City[1])
        {
            if (Flag == -1)
            {
                if (Number % 2)
                    Warrior_In_City[0]->Fight(Warrior_In_City[1]);
                else
                    Warrior_In_City[1]->Fight(Warrior_In_City[0]);
            }
            else
                Warrior_In_City[Flag]->Fight(Warrior_In_City[1 - Flag]);
        }
    }
    void Flag_Set(int i)
    { //战斗后旗帜设置
        if (i == -1)
        {
            Flag_G[0] = 0;
            Flag_G[1] = 0;
        }
        else
        {
            ++Flag_G[i];
            Flag_G[1 - i] = 0;
            if (Flag_G[i] == 2 && Flag != i)
            {
                Flag = i;
                Print_time();
                cout << Color[i] << " flag raised in city " << Number << endl;
            }
        }
    }
    void Reward(int i)
    {
        if (Warrior_In_City[i])
            Warrior_In_City[i]->Reward();
    }
    void Warrior_report(int i)
    {
        if (Warrior_In_City[i])
            Warrior_In_City[i]->Report_weapon();
    }
    void Win_get()
    { //奖励获胜士兵生命元
        for (int i = 0; i < 2; ++i)
            if (Warrior_In_City[i])
            {
                if (Warrior_In_City[i]->IF_win())
                {
                    Warrior_In_City[i]->ADD(Life);
                    Life = 0;
                    Warrior_In_City[i]->IF_win() = false;
                }
                else if (Warrior_In_City[i]->life() <= 0)
                {
                    delete Warrior_In_City[i];
                    Warrior_In_City[i] = NULL;
                }
            }
    }
};
class Command
{
  private:
    int Total_Life, Knights_Num, Colour, Enemy_Enter; //生命元，造士兵数量，command颜色，有多少敌人进入
    bool Weather_Enter;                               //是否有敌人进入
    Warrior *Enemys[2];                               //进入的敌人
    Warrior *Knight;                                  //warrior
  public:
    int colour() { return Colour; }
    string colour(bool p) { return p ? Color[Colour] : Color[1 - Colour]; }
    Command(int TLife, int col)
    {
        Total_Life = TLife;
        Colour = col;
        Knights_Num = 0;
        Knight = NULL;
        Enemy_Enter = 0;
        Weather_Enter = false;
        Enemys[0] = NULL;
        Enemys[1] = NULL;
    }
    void Minute_0()
    { //制造warrior及输出
        if (Total_Life >= Life_Make[Order[Colour][Knights_Num % 5]])
        {
            Total_Life -= Life_Make[Order[Colour][Knights_Num % 5]];
            Print_time();
            cout << Color[Colour] << ' ';
            Knight = new Warrior(Knights_Num + 1, Order[Colour][Knights_Num % 5], Life_Make[Order[Colour][Knights_Num % 5]], Total_Life, this);
            Knights_Num++;
        }
    }
    void Minute_5()
    { //处理逃跑lion
        if (Knight)
            if (Knight->Minute_5())
            {
                delete Knight;
                Knight = NULL;
            }
    }
    void Move(City *Cp, int i)
    {
        Cp->Move(Knight, i);
        Knight = NULL;
    } //warrior走出command
    void Enemy_Move_In(Warrior *enemy)
    { //敌方warrior进入
        Enemys[Enemy_Enter] = enemy;
        Weather_Enter = true;
        ++Enemy_Enter;
    }
    void Minute_10()
    { //敌方warrior进入输出
        if (Weather_Enter)
        {
            Enemys[Enemy_Enter - 1]->Minute_10(true);
            Weather_Enter = false;
        }
    }
    bool If_occupied()
    { //command是否被占领
        if (Enemy_Enter == 2)
        {
            Print_time();
            cout << Color[Colour] << " headquarter was taken\n";
            return true;
        }
        return false;
    }
    void Minute_30(int Add_life) { Total_Life += Add_life; }
    int &Life() { return Total_Life; }
    void Report_life()
    { //command报告生命元
        Print_time();
        cout << Total_Life << " elements in " << Color[Colour] << " headquarter\n";
    }
    void Report()
    {
        if (Enemy_Enter)
            Enemys[Enemy_Enter - 1]->Report_weapon();
    } //已进入command的warrior仍要report
    ~Command()
    {
        if (Knight)
            delete Knight;
        if (Enemys[0])
            delete Enemys[0];
        if (Enemys[1])
            delete Enemys[1];
    }
};
void Game_Start()
{
    int times = 0;
    cin >> times;
    for (int t = 0; t < times; ++t)
    {
        int M, N; //初始command生命元，城市数量
        cin >> M >> N >> arrow_attack >> Loyal_reduce >> Total_Minutes;
        Command COM[2] = {Command(M, 0), Command(M, 1)};
        vector<City> Citys;
        for (int i = 0; i < N; ++i)
        {
            City temp(i + 1);
            Citys.push_back(temp);
        }
        for (int i = 0; i < 5; ++i)
            cin >> Life_Make[i];
        for (int i = 0; i < 5; ++i)
            cin >> Attack_[i];
        cout << "Case " << t + 1 << ":\n";
        Hour = 0;
        Minute = 0; //计时开始
        while (Hour * 60 <= Total_Minutes)
        {
            COM[0].Minute_0();
            COM[1].Minute_0();
            Minute = 5; //第0分钟
            if (Hour * 60 + Minute > Total_Minutes)
                break; //第5分钟
            else
            {
                COM[0].Minute_5();
                for (vector<City>::iterator i = Citys.begin(); i != Citys.end(); ++i)
                    (*i).Minute_5();
                COM[1].Minute_5();
                Minute = 10;
            }
            if (Hour * 60 + Minute > Total_Minutes)
                break; //第10分钟
            else
            {
                if (Citys[0].If_exist(1))
                    Citys[0].Move(&COM[0], 1); //warrior前进
                for (int i = 0; i < N - 1; ++i)
                    Citys[i].Move(&Citys[i + 1], 1);
                COM[1].Move(&Citys[N - 1], 1);
                if (Citys[N - 1].If_exist(0))
                    Citys[N - 1].Move(&COM[1], 0);
                for (int i = N - 1; i > 0; --i)
                    Citys[i].Move(&Citys[i - 1], 0);
                COM[0].Move(&Citys[0], 0);
                COM[0].Minute_10(); //warrior移动输出
                bool p = COM[0].If_occupied();
                for (int i = 0; i < N; ++i)
                    Citys[i].Minute_10();
                COM[1].Minute_10();
                if (p + COM[1].If_occupied())
                    break;
            }
            Minute = 20;
            if (Hour * 60 + Minute > Total_Minutes)
                break; //第20分钟
            else
                for (int i = 0; i < N; ++i)
                    Citys[i].Add_Life();
            Minute = 30;

            if (Hour * 60 + Minute > Total_Minutes)
                break; //第30分钟
            else
                for (int i = 0; i < N; ++i)
                    Citys[i].Minute_30();
            Minute = 35;
            if (Hour * 60 + Minute > Total_Minutes)
                break; //第35分钟
            else if (N > 1)
            { //city数大于1时才会发生arrow事件
                City *Cp[2] = {};
                Cp[0] = NULL;
                Cp[1] = &Citys[1];
                Citys[0].Minute_35(Cp);
                for (int i = 1; i < N - 1; ++i)
                {
                    Cp[0] = &Citys[i - 1];
                    Cp[1] = &Citys[i + 1];
                    Citys[i].Minute_35(Cp);
                }
                Cp[0] = &Citys[N - 2];
                Cp[1] = NULL;
                Citys[N - 1].Minute_35(Cp);
            }
            Minute = 38;
            if (Hour * 60 + Minute > Total_Minutes)
                break; //第38分钟
            else
                for (vector<City>::iterator i = Citys.begin(); i != Citys.end(); ++i)
                    (*i).Minute_38();
            Minute = 40;
            if (Hour * 60 + Minute > Total_Minutes)
                break; //第40分钟
            else
            {
                for (vector<City>::iterator i = Citys.begin(); i != Citys.end(); ++i) //战斗及输出
                    (*i).Battle();
                for (vector<City>::iterator i = Citys.begin(); i != Citys.end(); ++i) //奖励生命元
                    (*i).Reward(0);
                for (vector<City>::reverse_iterator i = Citys.rbegin(); i != Citys.rend(); ++i)
                    (*i).Reward(1);
                for (vector<City>::iterator i = Citys.begin(); i != Citys.end(); ++i) //获取city生命元
                    (*i).Win_get();
            }
            Minute = 50;
            if (Hour * 60 + Minute > Total_Minutes)
                break; //第50分钟
            else
                COM[0].Report_life();
            COM[1].Report_life();
            Minute = 55;
            if (Hour * 60 + Minute > Total_Minutes)
                break; //第55分钟
            else
            {
                for (vector<City>::iterator i = Citys.begin(); i != Citys.end(); ++i)
                    (*i).Warrior_report(0);
                COM[1].Report();
                COM[0].Report();
                for (vector<City>::iterator i = Citys.begin(); i != Citys.end(); ++i)
                    (*i).Warrior_report(1);
            }
            Minute = 0;
            Hour++;
        }
    }
}
int main()
{
    //	freopen("d:\\anser.txt", "w", stdout);
    Game_Start();
    //	fclose(stdout);
    system("pause");
    return 0;
}
bool Warrior::Minute_5()
{
    if (name == lion)
        if (Loyal <= 0)
        {
            Print_time();
            cout << Command_Belong_to->colour(true) << " lion " << Num << " ran away\n";
            return true;
        }
    return false;
}
void Warrior::Minute_10(bool If_arrive)
{
    ++Step;
    if (name == iceman && !(Step % 2))
    {
        if (Life < 10)
            Life = 1;
        else
            Life -= 9;
        Attack += 20;
    }
    Print_time();
    cout << Command_Belong_to->colour(true) << ' ' << Knight[name] << ' ' << Num;
    if (If_arrive)
        cout << " reached " << Command_Belong_to->colour(false) << " headquarter";
    else
        cout << " marched to city " << City_Belong_to->Num();
    cout << " with " << Life << " elements and force " << Attack << endl;
}
void Warrior::Minute_30(int Add_life)
{
    Print_time();
    cout << Command_Belong_to->colour(true) << ' ' << Knight[name] << ' ' << Num << " earned " << Add_life << " elements for his headquarter\n";
    Command_Belong_to->Minute_30(Add_life);
}
void Warrior::arrow_shot()
{
    Print_time();
    cout << Command_Belong_to->colour(true) << ' ' << Knight[name] << ' ' << Num << " shot";
    weapon[arrow]->usetime()--;
    if (!weapon[arrow]->usetime())
    {
        delete weapon[arrow];
        weapon[arrow] = NULL;
    }
}
void Warrior::Be_shoted()
{
    Life -= arrow_attack;
    if (Life <= 0)
    {
        cout << " and killed " << Command_Belong_to->colour(true) << ' ' << Knight[name] << ' ' << Num;
    }
    cout << endl;
}
void City::Move(Command *Cp, int i)
{
    Cp->Enemy_Move_In(Warrior_In_City[i]);
    Warrior_In_City[i] = NULL;
}
void Warrior::Use_bomb(Warrior *Wp)
{
    Print_time();
    cout << Command_Belong_to->colour(true) << ' ' << Knight[name] << ' ' << Num << " used a bomb and killed " << (Wp->Command_Belong_to)->colour(true) << ' ' << Knight[Wp->name] << ' ' << Wp->Num << endl;
}
bool Warrior::bomb(Warrior *Wp, int p)
{
    if ((p + Command_Belong_to->colour()) % 2)
    {
        if (fight(Wp) == -1)
        {
            Use_bomb(Wp);
            return true;
        }
    }
    else if (Wp->fight(this) == 1)
    {
        Use_bomb(Wp);
        return true;
    }
    return false;
}
void Warrior::Dead()
{
    Print_time();
    cout << Command_Belong_to->colour(true) << ' ' << Knight[name] << ' ' << Num << " was killed in city " << City_Belong_to->Num() << endl;
}
void Warrior::Fight(Warrior *Wp)
{
    Warrior *Wp_win = NULL;
    Warrior *Wp_lose = NULL;
    l_life = Life;
    Wp->l_life = Wp->Life;
    if (Life > 0 and (Wp->Life) > 0)
    {
        int swatk = 0;
        if (weapon[sword])
            swatk = weapon[sword]->sw_atk();
        Print_time();
        cout << Command_Belong_to->colour(true) << ' ' << Knight[name] << ' ' << Num << " attacked " << (Wp->Command_Belong_to)->colour(true) << ' ' << Knight[Wp->name] << ' ' << Wp->Num << " in city " << City_Belong_to->Num() << " with " << Life << " elements and force " << Attack << endl;
        Wp->Life = Wp->Life - Attack - swatk;
        if (swatk)
            if (!weapon[sword]->sword_dull())
            {
                delete weapon[sword];
                weapon[sword] = NULL;
            }
        if (Wp->Life > 0)
        {
            if (Wp->name == ninja)
            {
                City_Belong_to->Flag_Set(-1);
                Morale_Change();
                Loyal_Reduce();
            }
            else
            {
                int E_swatk = 0;
                if (Wp->weapon[sword])
                    E_swatk = (Wp->weapon[sword])->sw_atk();
                Print_time();
                cout << (Wp->Command_Belong_to)->colour(true) << ' ' << Knight[Wp->name] << ' ' << Wp->Num << " fought back against " << Command_Belong_to->colour(true) << ' ' << Knight[name] << ' ' << Num << " in city " << City_Belong_to->Num() << endl;
                Life = Life - (Wp->Attack / 2) - E_swatk;
                if (E_swatk)
                    if (!(Wp->weapon[sword])->sword_dull())
                    {
                        delete Wp->weapon[sword];
                        Wp->weapon[sword] = NULL;
                    }
                if (Life > 0)
                {
                    City_Belong_to->Flag_Set(-1);
                    Morale_Change();
                    Wp->Morale_Change();
                    Loyal_Reduce();
                    Wp->Loyal_Reduce();
                }
                else
                {
                    Wp->If_kill = true;
                    Wp_lose = this;
                    Wp_win = Wp;
                }
            }
        }
        else
        {
            If_kill = true;
            Wp_win = this;
            Wp_lose = Wp;
        }
    }
    else
    {
        if (Life > 0)
        {
            Wp->l_life = 0;
            Wp_win = this;
            Wp_lose = Wp;
        }
        else
        {
            l_life = 0;
            Wp_lose = this;
            Wp_win = Wp;
        }
    }
    if (Wp_win)
    {
        Wp_win->account(Wp_lose);
    }
    if (name == dragon and Life > 0 and Morale > 0.8)
    {
        Print_time();
        cout << Command_Belong_to->colour(true) << ' ' << Knight[name] << ' ' << Num << " yelled in city " << City_Belong_to->Num() << endl;
    }
    if (Wp_win)
    {
        Print_time();
        cout << (Wp_win->Command_Belong_to)->colour(true) << ' ' << Knight[Wp_win->name] << ' ' << Wp_win->Num << " earned " << City_Belong_to->Life_() << " elements for his headquarter\n";
        (Wp_win->City_Belong_to)->Flag_Set((Wp_win->Command_Belong_to)->colour());
    }
}
void Warrior::Reward()
{
    if (If_win)
        if (Command_Belong_to->Life() > 7)
        {
            Command_Belong_to->Life() -= 8;
            Life += 8;
        }
}
void Warrior::ADD(int life) { Command_Belong_to->Life() += life; }
void Warrior::Report_weapon()
{
    bool p = false;
    Print_time();
    cout << Command_Belong_to->colour(true) << ' ' << Knight[name] << ' ' << Num << " has ";
    for (int i = 2; i >= 0; --i)
        if (weapon[i])
        {
            if (p)
                cout << ',';
            else
                p = true;
            cout << Weapons_[i];
            if (i == 2)
                cout << '(' << weapon[arrow]->usetime() << ')';
            if (i == 0)
                cout << '(' << weapon[sword]->sw_atk() << ')';
        }
    if (!p)
        cout << "no weapon";
    cout << endl;
}
