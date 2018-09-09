/*
排队游戏

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
在幼儿园中，老师安排小朋友做一个排队的游戏。首先老师精心的把数目相同的小男孩和小女孩编排在一个队列中，
每个小孩按其在队列中的位置发给一个编号（编 号从0开始）。然后老师告诉小朋友们，
站在前边的小男孩可以和他后边相邻的小女孩手拉手离开队列，剩余的小朋友重新站拢，
再按前后相邻的小男孩小女孩手拉 手离开队列游戏，如此往复。由于教师精心的安排，
恰好可以保证每两个小朋友都能手拉手离开队列，并且最后离开的两个小朋友是编号最小的和最大的两个小朋友。
（注：只有小男孩在前，小女孩在后，且他们两之间没有其他的小朋友，他们才能手拉手离开队列）。
请根据老师的排队，按小女孩编号从小到大的顺序，给出 所有手拉手离开队列的小男孩和小女孩的编号对。

输入
用一个字符串代表小朋友队列。字符串中只会出现两个字符（样例输入里用的是 括号但实际数据则不一定），
分别代表小男孩和小女孩，首先出现的字符代表小男孩，另一个字符代表小女孩。小孩总数不超过100

输出
按小女孩编号顺序，顺序输出手拉手离开队列的小男孩和小女孩的编号对，每行一对编号，编号之间用一个空格分隔。

样例输入
((()(())())(()))

样例输出
2 3
5 6
4 7
8 9
1 10
12 13
11 14
0 15
*/

//方法一
#include<iostream>
using namespace std;

char children[101];
int boy = 0;//记录男生的数目
int couple = 0;//记录狗男女的数目
char m, f;//男，女
int date() {//函数名叫yue pao 。。。
	for (int i = 0; i < 2 * boy; i++) {
		bool stay = true;
		if (children[i] == m) {
			for (int j = i + 1; j < 2 * boy; j++) {
				if (children[j] == m)
					break;//不考虑男同问题，所以这里break，先让后面的继续
				if (children[j] == f) {
					children[i] = ' ';
					children[j] = ' ';
					cout << i <<' '<< j << endl;
					couple++;
					stay = false;//约到了，就不用在这浪费时间了，所以把位子清空，可以嘿嘿嘿去了。。。。
					break;
				}
			}
		}
		if (stay == false)
			break;//有人约到就跳出这层循环
	}
	if (couple != boy)//因为只考虑异性恋，所以如果情侣数目跟男生数目不相等，就证明还有男的是单身狗，所以继续递归
		date();
		return 0;
}
int main(){
	cin.getline(children, 101);
	m = children[0];//根据题意，无论第一个人长什么样，我们都把他当男的看
	for (int i = 0; i < 100; i++) {
		if (children[i] != m) {
			f = children[i];//不考虑有第三种性别的存在，所以长得跟男的不一样的，一律视为女的
			break;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (children[i] == m)
			boy++;//数数有多少个男生
	}
	date();
    system("pause");
	return 0;
}
//机器评判通过

/*
//方法二(该方法无法判断 "()()" 这种情况)
#include <iostream>  
using namespace std;  
char man;  
//参数;char str[],字符串  
//int s,开始位置  
//返回值：返回本层的右括号位置  
int Pair(char str[], int s)  
{  
    int n;  
    if (str[s] != man)  
    {  
        return s;  
    }  
    if (str[s] == man)
    {  
        n = Pair(str, s + 1);  
        cout << s << ' ' << n << endl;  
        return Pair(str, n + 1);  
    }  
}  
int main()  
{  
    char str[101] = { 0 };  
    cin >> str;  
    man = str[0];  
    int n = Pair(str, 1);  
    cout << "0 " << n << endl;  
    system("pause");
    return 0;  
}  
*/