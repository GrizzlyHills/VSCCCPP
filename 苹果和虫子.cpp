/*
����
������һ��n��ƻ�����ܲ��ҵ�������ʱ����������һ�����ӡ�
����ÿxСʱ�ܳԵ�һ��ƻ������������ڳ���һ��ƻ��֮ǰ�������һ����
��ô����yСʱ�㻹�ж��ٸ�������ƻ����

����
�����һ�У�����n��x��y����Ϊ���������������ݱ�֤y <= n * x��

���
���Ҳ��һ�У�ʣ�µ�ƻ������

��������
10 4 9

�������
7
*/

#include <iostream>
using namespace::std;

int main(void)
{
    //��������ƻ����n����һ��ƻ��ʱ��x����ʱy
    int n,x,y;
    do{
        cout << "���������ݣ�";
        cin >> n >> x >> y;
        cout << endl;
    }while(y > n * x);
    //���㻹ʣ����ƻ��
    int nRemaining = n - (y/x + 1);
    cout << nRemaining << endl;
    system("pause");
    return 0;
}

/*�����ܽ��ܵİ汾����ϸ���˿����ҹ�Ȼ��©�˺ܶ�ط�
#include<iostream>
using namespace std;
int main()
{
    int n, x, y;
    float q; //  WHY NOT  int q ?    They are all right!
    cin >> n >> x >> y;
    q = y % x;
    if(y > n * x)
        cout << 0;     //���һ
    else {
        if(q == 0)
            n = n - y / x;  //�����
        else
            n = n - y / x - 1;  //���������ֻ���ǵ������������������
        cout << n;
    }
    return 0;
}
*/