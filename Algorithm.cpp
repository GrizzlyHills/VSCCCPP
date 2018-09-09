// 枚举思想之熄灯问题
/*
 * @Author: GrizzlyHills 
 * @Date: 2017-08-31 16:12:24 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-09-03 21:43:15
    1. 枚举过程 enumerate()
       - press[1][] 中每一个元素表示一个二进制数 0/1， 通过模拟二进制加法方式实现枚举； 需要处理进位
    2. 推测验证过程 guess()
       - 用 6*8 按钮矩阵来简化下一行按钮值的计算公式
       - 根据 press[1][] 和 puzzle 数组， 用公式来计算使得 1-4 行所有灯熄灭的 press 其他行的值，
         再判断所计算的 press 数组能否熄灭矩阵的第 5 行的所有灯

 */


#include <iostream>
#include <ctime>
using namespace::std;

int puzzle[6][8], press[6][8];
bool guess()
{
    int c, r;
    for (r = 1; r < 5; r++)
        for (c = 1; c < 7; c++)
            press[r + 1][c] = (puzzle[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1]) % 2;   //根据 press 第一行和 puzzle 数组， 计算 press 其他行的值
            for (c = 1; c < 7; c++) if ((press[5][c - 1] + press[5][c] + press[5][c + 1] + press[4][c]) % 2 != puzzle[5][c]) //判断所计算的 press 数组能否熄灭第 5 行的所有灯
                return false;
    return true;
}
bool enumerate()
{
    int c;
    bool success = true;
    for (c = 1; c < 7; c++)
        press[1][c] = 0;
    while (!guess())
    {
        press[1][1]++;
        c = 1;
        while (press[1][c] > 1)
        { //对 press 第一行的元素的各种取值情况进行枚举
            press[1][c] = 0;
            c++;
            press[1][c]++;
        }
    }
    return success;
}

int main()
{
    srand(time(NULL));
    int cases = 0, i, r, c;
    bool flag = true;
    //scanf("%d", &cases);
    for (r = 0; r < 6; r++)
        press[r][0] = press[r][7] = 0;
    for (c = 1; r < 7; r++)
        press[0][c] = 0;
    //for (i = 0; i < cases; i++)
    //{
    while (flag) {
        for (r = 1; r < 6; r++)
            for (c = 1; c < 7; c++)
                //scanf("%d", &puzzle[r][c]);               //手工输入太慢了
                puzzle[r][c] = rand() % 2;
        cout << "Random PUZZLE #" << cases << " :";
        for (r = 1; r < 6; r++){
            cout << endl;
            for (c = 1; c < 7; c++)     
                cout << puzzle[r][c] << " ";  
        }        
        //读入输入数据
        flag = !enumerate();
        printf("\nSolution press[][] #%d :\n", cases);
        for (r = 1; r < 6; r++)
        {
            for (c = 1; c < 7; c++)
                printf("%d ", press[r][c]); 
            printf("\n");
        }  
        cases++;  
    }

    //}
    system("pause");
    return 0;
}