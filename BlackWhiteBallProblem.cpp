/*
 * @Author: GrizzlyHills 
 * @Date: 2017-11-15 16:24:47 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-11-15 17:01:42
 * 
    * 已知袋中有若干个白球和黑球，每次从中取出两个球。如取出的各个球为同色，则放回一个白球（袋外有足够的白球）；如取出的两个球为异色，则放回一黑球。试设计取球过程的模拟程序。
    * 判断最后剩下的一个球的颜色。
    // 要求是： 
        // 1，用循环语句实现重复取出小球的操作。
        // 2，用函数实现一次取球，由随机数决定取出小球的颜色。
        // 3，选择条件语句来处理取得不同颜色的小球后的情况。
        // 4，打印每次取出的两个小球的颜色。
 */

#include <iostream>
#include <time.h>
using namespace std;
enum Ball
{
    white,
    black
};
int main(int argc, char *argv[])
{
    //定义袋中黑白球的数目
    int BlackNum;
    int WhiteNum;

    //由用户指定袋中的黑白球数目
    cout << "请输入袋中白球的数目" << endl;
    cin >> WhiteNum;
    cout << "请输入袋中黑球的数目" << endl;
    cin >> BlackNum;
    //初始化随机数种子
    srand((unsigned)time(NULL));
    int times = 0; //取球的次数
    while ((BlackNum + WhiteNum) > 1)
    {
        ++times;
        int FirstBall;
        int SecondBall;
        //每次取得的第一个和第二个球
        if (WhiteNum == 0) //袋中已没有白球，则只能取黑球
        {
            FirstBall = black;
            cout << "第 " << times << " 次取出的第一个球为黑色" << endl;
            --BlackNum;
        }
        else if (BlackNum == 0) //袋中已没有黑球
        {
            FirstBall = white;
            cout << "第 " << times << " 次取出的第一个球为白色" << endl;
            --WhiteNum;
        }
        else //否则随机取得一个球
        {
            FirstBall = rand() % 2;
            if (FirstBall == white)
            {
                cout << "第 " << times << " 次取出的第一个球为白色" << endl;
                --WhiteNum;
            }
            else
            {
                cout << "第 " << times << " 次取出的第一个球为黑色" << endl;
                --BlackNum;
            }
        }

        if (WhiteNum == 0) //袋中已没有白球，则只能取黑球
        {
            SecondBall = black;
            cout << "第 " << times << " 次取出的第一个球为黑色" << endl;
            --BlackNum;
        }
        else if (BlackNum == 0) //袋中已没有黑球
        {
            SecondBall = white;
            cout << "第 " << times << " 次取出的第一个球为白色" << endl;
            --WhiteNum;
        }
        else
        {
            SecondBall = rand() % 2;
            if (FirstBall == white)
            {
                cout << "第 " << times << " 次取出的第二个球为白色" << endl;
                --WhiteNum;
            }
            else
            {
                cout << "第 " << times << " 次取出的第二个球为黑色" << endl;
                --BlackNum;
            }
        }

        //根据取出的两个球的颜色是否相等来觉得是放黑球进去还是白球进去
        if (FirstBall == SecondBall)
        {
            ++WhiteNum;
        }
        else
        {
            ++BlackNum;
        }
    }
    if (WhiteNum == 1)
    {
        cout << "最后一个球为白球" << endl;
    }
    else
        cout << "最后一个球为黑球" << endl;
    system("pause");
}