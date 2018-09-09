/*
编程题＃2：字符串中次数第2多的字母

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
输入一串长度不超过500个符号的字符串，输出在串中出现第2多的英语字母(大小写字母认为相同)和次数（如果串中有其它符号，则忽略不考虑）。
如果有多个字母的次数都是第2多，则按串中字母出现的顺序输出第1个。
例 ab&dcAab&c9defgb
这里，a 和 b都出现3次，c和d都出现2次，e、f 和 g 各出现1次，其中的符号&和9均忽略不考虑。
因此，出现第2多的应该是 c 和 d，但是 d 开始出现的位置在 c 的前面，因此，输出为
D+d:2
(假定在字符串中，次数第2多的字母总存在)

输入
一个字符串

输出
大写字母+小写字母:个数

样例输入
ab&dcAab&c9defgb

样例输出
D+d:2
*/
/*
#include<iostream>
using namespace std;

struct Letter{
    char letter;
    int OccurrenceNumber;
    int rank;
};

int main()
{
    char str[501] = {0};
    cin.getline(str,501);    
    Letter alphbet[27];
    for(int i = 0;i < 26;i++){
        alphbet[i].letter = (char)('a' + i);
        alphbet[i].OccurrenceNumber = 0;
        alphbet[i].rank = 0;
    }    
    int count = 1;                    //letterNum这里待修改
    for(int i = 0;str[i] != '\0';i++){
        if(str[i] >= 'A' || str[i] <= 'Z'){
            alphbet[str[i] - 'A'].OccurrenceNumber++;
            if(alphbet[str[i] - 'A'].rank == 0)
                alphbet[str[i] - 'A'].rank = count;
        }
        if(str[i] >= 'a' || str[i] <= 'z'){
            alphbet[str[i] - 'a'].OccurrenceNumber++;
            if(alphbet[str[i] - 'a'].rank == 0)
                alphbet[str[i] - 'a'].rank = count;           
        }
        count++;
    }
    for(int i = 0;i < 26;i++){
        for(int j = i + 1;j < 26;j++){
            Letter temp;
            if(alphbet[i].OccurrenceNumber < alphbet[j].OccurrenceNumber && alphbet[i].letter != '\0' && alphbet[j].letter != '\0'){
                temp = alphbet[i];
                alphbet[i] = alphbet[j];
                alphbet[j] = temp;
            }
        }
    }
    int first,second,flag = 0;
    first = alphbet[0].OccurrenceNumber;
    for(int i = 0;i < 26;i++){
        if(first > alphbet[i].OccurrenceNumber && alphbet[i].letter != '\0'){
            second = alphbet[i].OccurrenceNumber;
            flag = i;
            for(int j = i;j < 26;j++){
                if(alphbet[j].rank <= alphbet[flag].rank && second == alphbet[j].OccurrenceNumber){
                    flag = j;
                }
            }
            cout << (char)(alphbet[flag].letter - 32) << "+" << (char)(alphbet[flag].letter) << ":" << alphbet[flag].OccurrenceNumber << endl;
            break;
        }
    }
    cout << "first->" << (char)(alphbet[0].letter - 32) << "+" << (char)(alphbet[0].letter) << ":" << alphbet[0].OccurrenceNumber << endl;
    system("pause");
    return 0;
}                       //应该没有错误了  为何无法通过？
//机器评判通过
*/
#include<iostream>           //网上解法
using namespace std;
int k = 0;//出现的字母个数
struct zimu{//用于保存出现的字母以及其个数
	char letter;
	int time;
};
zimu appaerZimu[27];//保存所有出现过的字母
int deal(char input) {//对于字母，进行处理，
	bool find = false;
	for (int i = 0; i < k+1; i++) {//出现过的字母，个数+1
		if (input == appaerZimu[i].letter) {
			find = true;
			appaerZimu[i].time++;
			break;
		}
	}
	if (find == false) {//没出现过的字母，进行初始化，保存其字母，出现次数设定为1
		appaerZimu[k].letter = input;
		appaerZimu[k].time = 1;
		k++;
	}
	return 0;
}
int main() {
	char input[501];//用于保存输入
	cin.getline(input, 501);//接受输入数据

	for (int i = 0; i < 501; i++) {//判断是否是英文字母，如果是英文字母，则进行处理
		if (input[i] == '\0')
			break;
		else {
			if (input[i] >= 'a'&&input[i] <= 'z')
				deal(input[i]);
			if (input[i] >= 'A'&&input[i] <= 'Z') {
				char temp = input[i] + 32;
				deal(temp);
			}
		}
	}
	zimu larggest = { ' ',0 };
	zimu second = { ' ',0 };
	for (int i = 0; i < k-1; i++) {//通过最大值和次大值两个变量，最后找到次大值
		if (appaerZimu[i].time > larggest.time) {
			second = larggest;
			larggest = appaerZimu[i];
		}
		else if (appaerZimu[i].time > second.time&& appaerZimu[i].time < larggest.time) {
		 	second = appaerZimu[i];
		}
	}
	char temp = second.letter - 32;
	cout << temp << '+' << second.letter << ':' << second.time;
    system("pause");
	return 0;
}