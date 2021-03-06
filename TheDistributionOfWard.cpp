/*
编程题＃1：分配病房

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
某个科室的病房分为重症和普通，只有当病人的疾病严重程度超过了入住重症病房的最低严重值，才可以安排入住重症病房。
现在要求设计一个程序，给病人安排好病房。疾病的严重程度用0到10来表示，0表示小毛病，10表示非常严重。

输入
第一行输入病人的个数m(m < 50)，以及安排住入重症病房的最低严重值a
紧接着m行，每行表示病人编号（三个位，用0补齐）及其疾病的严重程度（浮点数，1位小数）。
每个病人的疾病严重程度都不一样。

输出
要求按照病人的严重程度输出住在重症病房里的病人的编号

注意：
如果当前所有病人的严重程度并不满足住在重症病房里，则输出“None.”（不包括引号）

样例输入
10 7.55
006 6.5
005 8.0
004 3.5
009 8.5
011 7.0
043 9.5
003 5.0
103 6.0
112 4.0
118 9.0

样例输出
043 9.5
118 9.0
009 8.5
005 8.0
*/

#include <iostream>  
#include <iomanip>
using namespace std;  

int main() {  
    int m,number[50];
    float a,degree[50];    
    cin >> m >> a;
    bool flag = false;
    for(int i = 0;i < m;i++){
        cin >> number[i] >> degree[i];
    }
    for (int i = 0; i < m; i++) {  
        if (degree[i] >= a) {  
            flag = true;  
            /*冒泡，把住在ICU的病人，从小到大排序*/  
            for (int j = i + 1; j < m; j++) {  
                if (degree[j] >= a && degree[j] > degree[i]) {  
                    float temp;  
                    temp = degree[j];  
                    degree[j] = degree[i];  
                    degree[i] = temp;  
                    int temp1;  
                    temp1 = number[j];  
                    number[j] = number[i];  
                    number[i] = temp1;  
                }  
            }  
        }  
    }      
    if (flag == false) {  
        cout << "None." << endl;  
        return 0;  
    } else {
        for (int i = 0; i < m; i++) {  
            if (degree[i] >= a)  
            {  
                cout << setfill('0') << setw(3) << number[i] << " " << fixed << setprecision(1) << degree[i] << endl;
            }             
        }          
    }     
    system("pause");
    return 0;  
}  //机器通过