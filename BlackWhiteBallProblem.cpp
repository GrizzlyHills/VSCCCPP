/*
 * @Author: GrizzlyHills 
 * @Date: 2017-11-15 16:24:47 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-11-15 17:01:42
 * 
    * ��֪���������ɸ�����ͺ���ÿ�δ���ȡ����������ȡ���ĸ�����Ϊͬɫ����Ż�һ�����򣨴������㹻�İ��򣩣���ȡ����������Ϊ��ɫ����Ż�һ���������ȡ����̵�ģ�����
    * �ж����ʣ�µ�һ�������ɫ��
    // Ҫ���ǣ� 
        // 1����ѭ�����ʵ���ظ�ȡ��С��Ĳ�����
        // 2���ú���ʵ��һ��ȡ�������������ȡ��С�����ɫ��
        // 3��ѡ���������������ȡ�ò�ͬ��ɫ��С���������
        // 4����ӡÿ��ȡ��������С�����ɫ��
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
    //������кڰ������Ŀ
    int BlackNum;
    int WhiteNum;

    //���û�ָ�����еĺڰ�����Ŀ
    cout << "��������а������Ŀ" << endl;
    cin >> WhiteNum;
    cout << "��������к������Ŀ" << endl;
    cin >> BlackNum;
    //��ʼ�����������
    srand((unsigned)time(NULL));
    int times = 0; //ȡ��Ĵ���
    while ((BlackNum + WhiteNum) > 1)
    {
        ++times;
        int FirstBall;
        int SecondBall;
        //ÿ��ȡ�õĵ�һ���͵ڶ�����
        if (WhiteNum == 0) //������û�а�����ֻ��ȡ����
        {
            FirstBall = black;
            cout << "�� " << times << " ��ȡ���ĵ�һ����Ϊ��ɫ" << endl;
            --BlackNum;
        }
        else if (BlackNum == 0) //������û�к���
        {
            FirstBall = white;
            cout << "�� " << times << " ��ȡ���ĵ�һ����Ϊ��ɫ" << endl;
            --WhiteNum;
        }
        else //�������ȡ��һ����
        {
            FirstBall = rand() % 2;
            if (FirstBall == white)
            {
                cout << "�� " << times << " ��ȡ���ĵ�һ����Ϊ��ɫ" << endl;
                --WhiteNum;
            }
            else
            {
                cout << "�� " << times << " ��ȡ���ĵ�һ����Ϊ��ɫ" << endl;
                --BlackNum;
            }
        }

        if (WhiteNum == 0) //������û�а�����ֻ��ȡ����
        {
            SecondBall = black;
            cout << "�� " << times << " ��ȡ���ĵ�һ����Ϊ��ɫ" << endl;
            --BlackNum;
        }
        else if (BlackNum == 0) //������û�к���
        {
            SecondBall = white;
            cout << "�� " << times << " ��ȡ���ĵ�һ����Ϊ��ɫ" << endl;
            --WhiteNum;
        }
        else
        {
            SecondBall = rand() % 2;
            if (FirstBall == white)
            {
                cout << "�� " << times << " ��ȡ���ĵڶ�����Ϊ��ɫ" << endl;
                --WhiteNum;
            }
            else
            {
                cout << "�� " << times << " ��ȡ���ĵڶ�����Ϊ��ɫ" << endl;
                --BlackNum;
            }
        }

        //����ȡ�������������ɫ�Ƿ�����������Ƿź����ȥ���ǰ����ȥ
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
        cout << "���һ����Ϊ����" << endl;
    }
    else
        cout << "���һ����Ϊ����" << endl;
    system("pause");
}