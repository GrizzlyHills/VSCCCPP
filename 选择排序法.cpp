#include <iostream>
#include <iomanip>
using namespace::std;

int main(void)
{
    int a[10];//用于存放输入的数据
    int i = 0, j = 0; //用于循环计数
    int temp = 0; //临时变量，用于暂存要交换的数据
    for(i = 0; i < 10; i++) //依次输入10个待排序的数据
        cin >> a[i];
    for(i = 0; i < 9; i++) //依次为数组的第i个元素选择最大的数
        for(j = i + 1; j < 10; j++) { //从第i+1个元素开始寻找比a[i]更大的数
            if(a[j] > a[i]) {//如果找到比a[i]更大的数，就将它与a[i]交换
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    for(i = 0; i < 10; i++)
        cout << a[i] << "    ";
    system("pause");
    return 0;
}