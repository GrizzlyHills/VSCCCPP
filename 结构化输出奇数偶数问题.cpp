#include <iostream>
#include <iomanip>
using namespace::std;

int main(void)
{
    int all[10], odd[10], even[10]; //odd��¼������even��¼ż��
    int i = 0, j = 0; //i,jΪѭ����������
    for(; i < 10; i++)
        cin >> all[i];
    int numOdd = 0;
    int numEven = 0; //numOdd,numEve�ֱ��¼������ż���ĸ���
    for(i = 0; i < 10; i++)
        if(all[i] % 2 != 0) { //��ǰ��Ϊ�������
            odd[numOdd] = all[i];
            numOdd++;
        } else { //��ǰ��Ϊż�����
            even[numEven] = all[i];
            numEven++;
        }
    for(i = 0; i < numOdd; i++) //�������
        cout << setw(10) << odd[i];
    cout << endl;
    for(i = 0; i < numEven; i++) //���ż��
        cout << setw(10) << even[i];
    system("pause");
    return 0;
}