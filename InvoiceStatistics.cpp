/*
发票统计

描述
有一个小型的报账系统，它有如下功能：
（1）统计每个人所报发票的总钱数
（2）统计每类发票的总钱数
将此系统简化为如下：假设发票类别共有A、B、C三种;一共有三个人，ID分别为1、2、3。

输入
系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，
之后是多个发票类别（字符型，A或B或C）和相应发票金额（单精度浮点型,不超过1000.0）。

输出
输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），后三行为每类发票的总钱数（保留两位小数）。

样例输入
1 5 A 1.0 A 2.0 C 1.0 B 1.0 C 1
3 3 B 1 C 2 C 1
2 4 B 1 A 1 C 1 A 1

样例输出
1 6.00
2 4.00
3 4.00
A 5.00
B 3.00
C 6.00
*/
/*
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void PrintEveryoneInvoiceTotalAmount(int,vector<float>&);
void PrintSortInvoiceTotalAmount(vector<float>&,vector<float>&,vector<float>&,vector<char>&,vector<char>&,vector<char>&);
int main()
{
    int ID,InvoiceNum;
    char sort;
    float amount;
    vector<char> arr1_sort;
    vector<float> arr1_amount;
    vector<char> arr2_sort;
    vector<float> arr2_amount;
    vector<char> arr3_sort;
    vector<float> arr3_amount;
    for(int i = 0;i < 3;i++){
        cin >> ID >> InvoiceNum;
        if(ID == 1){
            for(int j = 0;j < InvoiceNum;j++){
                cin >> sort >> amount;
                arr1_sort.push_back(sort);
                arr1_amount.push_back(amount);
            }
        }else if(ID == 2){
            for(int j = 0;j < InvoiceNum;j++){
                cin >> sort >> amount;
                arr2_sort.push_back(sort);
                arr2_amount.push_back(amount);
            }
        }else if(ID == 3){
            for(int j = 0;j < InvoiceNum;j++){
                cin >> sort >> amount;
                arr3_sort.push_back(sort);
                arr3_amount.push_back(amount);
            }
        }
    }
    PrintEveryoneInvoiceTotalAmount(1,arr1_amount);
    PrintEveryoneInvoiceTotalAmount(2,arr2_amount);
    PrintEveryoneInvoiceTotalAmount(3,arr3_amount);
    PrintSortInvoiceTotalAmount(arr1_amount,arr2_amount,arr3_amount,arr1_sort,arr2_sort,arr3_sort);
    system("pause");
    return 0;
}
void PrintEveryoneInvoiceTotalAmount(int ID,vector<float> &arr_amount)
{
    float EveryoneInvoiceTotalAmount = 0;
    for(auto j:arr_amount){
        EveryoneInvoiceTotalAmount += j;
    }
    cout << fixed << setprecision(2) << ID << " " << EveryoneInvoiceTotalAmount << endl;
    return;
}
void PrintSortInvoiceTotalAmount(vector<float> &a1,vector<float> &a2,vector<float> &a3,vector<char> &s1,vector<char> &s2,vector<char> &s3)
{
    float AmountA=0,AmountB=0,AmountC=0;
    for(int j = 0;j != s1.size();j++){
        if(s1[j] == 'A')
            AmountA += a1[j];
        else if(s1[j] == 'B')
            AmountB += a1[j];
        else if(s1[j] == 'C')
            AmountC += a1[j];
    }
    for(int j = 0;j != s2.size();j++){
        if(s2[j] == 'A')
            AmountA += a2[j];
        else if(s2[j] == 'B')
            AmountB += a2[j];
        else if(s2[j] == 'C')
            AmountC += a2[j];
    }
    for(int j = 0;j != s3.size();j++){
        if(s3[j] == 'A')
            AmountA += a3[j];
        else if(s3[j] == 'B')
            AmountB += a3[j];
        else if(s3[j] == 'C')
            AmountC += a3[j];
    }
    cout << fixed << setprecision(2) << "A " << AmountA << endl
                                     << "B " << AmountB << endl
                                     << "C " << AmountC << endl;
    return;
}
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    float sum[6];
    
    for (int i = 0; i < 3; i++){
        int a;
        cin >> a;
        int n;
        cin >> n;
        for (int j = 0; j < n;j++){
            char b;
            cin >> b;
            float c;
            cin >> c;
            if (b == 'A') {
                sum[a - 1] += c;
                sum[3] += c;
            }
            else if (b == 'B') {
                sum[a - 1] += c;
                sum[4] += c;
            } 
            else if (b == 'C') {
                sum[a - 1] += c;
                sum[5] += c;
            }    
        }
    }
    cout << fixed << setprecision(2) << "1 " << sum[0] << endl
                                     << "2 " << sum[1] << endl
                                     << "3 " << sum[2] << endl
                                     << "A " << sum[3] << endl
                                     << "B " << sum[4] << endl
                                     << "C " << sum[5] << endl;    
    system("pause");
    return 0;
}
//机器评判通过