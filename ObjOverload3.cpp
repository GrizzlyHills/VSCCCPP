/*
编程题＃4：大整数的加减乘除

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
给出两个正整数以及四则运算操作符（+ - * /），求运算结果。

输入
第一行：正整数a，长度不超过100
第二行：四则运算符o，o是“+”，“-”，“*”，“/”中的某一个
第三行：正整数b，长度不超过100

保证输入不含多余的空格或其它字符

输出
一行：表达式“a o b”的值。

补充说明：
1. 减法结果有可能为负数
2. 除法结果向下取整
3. 输出符合日常书写习惯，不能有多余的0、空格或其它字符

样例输入
9876543210
+
9876543210

样例输出
19753086420
*/
#include <iostream>
#include <cstring>
using namespace std;

const int MAXLEN = 100;

class Integer
{
  private:
    int is_neg;       //是否为负
    int len;          // 位数
    int s[MAXLEN];    // 表示整数的数组
    char str[MAXLEN]; //原字符串

  public:
    Integer(const char *string = "")
    {
        memset(s, 0, MAXLEN * sizeof(int));
        memset(str, 0, MAXLEN * sizeof(char));
        strcpy(str, string);
        is_neg = 0;
        len = strlen(str);
        for (int i = 0; i < len; i++)
            s[i] = int(str[len - 1 - i]) - 48;
    }
    Integer &operator=(const Integer &oth)
    {
        if (this == &oth)
            return *this;
        memset(s, 0, MAXLEN * sizeof(int));
        memset(str, 0, MAXLEN * sizeof(char));
        is_neg = oth.is_neg;
        len = oth.len;
        for (int i = 0; i < oth.len; i++)
            s[i] = oth.s[i];
        strcpy(str, oth.str);
        return *this;
    }

    bool operator==(const Integer &oth)
    {
        if (this == &oth)
            return true;
        bool ret = true;
        if (len != oth.len || is_neg != oth.is_neg)
            ret = false;
        if (strcmp(str, oth.str))
            ret = false;
        for (int i = 0; i < oth.len; i++)
        {
            if (s[i] != oth.s[i])
                ret = false;
        }
        return ret;
    }

    bool operator!=(const Integer &oth)
    {
        return !(*this == oth);
    }

    Integer operator+(const Integer &oth)
    {
        Integer c;
        int length = len >= oth.len ? len : oth.len;
        length += 1; //可能会进位
        c.len = length;
        for (int i = 0; i < c.len; i++)
        {
            c.s[i] += s[i] + oth.s[i];
            c.s[i + 1] += c.s[i] / 10;
            c.s[i] = c.s[i] % 10;
        }
        while ((c.len > 1) && (c.s[c.len - 1] == 0))
            c.len--;
        int k = 0;
        for (int i = c.len - 1; i >= 0; i--)
        {
            c.str[k++] = (char)(c.s[i] + 48);
        }
        return c;
    }

    Integer operator-(const Integer &oth)
    {
        Integer c;
        int flag = 0;

        if (len > oth.len)
            flag = 1;
        else if (len < oth.len)
            flag = -1;
        else
            flag = strcmp(str, oth.str);

        if (flag >= 0)
        {
            c.len = len;
            int borrow = 0;
            for (int i = 0; i < c.len; i++)
            {
                c.s[i] += s[i] - oth.s[i];
                if (borrow)
                    c.s[i] -= 1;
                if (c.s[i] < 0)
                {
                    c.s[i] += 10;
                    borrow = 1;
                }
                else
                    borrow = 0;
            }
            while ((c.len > 1) && (c.s[c.len - 1] == 0))
                c.len--;
        }
        else
        {
            c.is_neg = 1;
            c.len = oth.len;
            int borrow = 0;
            for (int i = 0; i < c.len; i++)
            {
                c.s[i] += oth.s[i] - s[i];
                if (borrow)
                    c.s[i] -= 1;
                if (c.s[i] < 0)
                {
                    c.s[i] += 10;
                    borrow = 1;
                }
                else
                    borrow = 0;
            }
            while ((c.len > 1) && (c.s[c.len - 1] == 0))
                c.len--;
        }

        int k = 0;
        for (int i = c.len - 1; i >= 0; i--)
        {
            c.str[k++] = (char)(c.s[i] + 48);
        }
        return c;
    }

    Integer operator*(const Integer &oth)
    {
        Integer c;
        c.len = len + oth.len + 1;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < oth.len; j++)
            {
                c.s[i + j] += s[i] * oth.s[j];
                c.s[i + j + 1] += c.s[i + j] / 10;
                c.s[i + j] = c.s[i + j] % 10;
            }
        }
        while ((c.len > 1) && (c.s[c.len - 1] == 0))
            c.len--;
        int k = 0;
        for (int i = c.len - 1; i >= 0; i--)
        {
            c.str[k++] = (char)(c.s[i] + 48);
        }
        return c;
    }

    Integer operator/(const Integer &oth)
    {
        Integer c("0");
        int flag = 0;

        if (len > oth.len)
            flag = 1;
        else if (len < oth.len)
            flag = -1;
        else
            flag = strcmp(str, oth.str);

        Integer one("1");
        Integer zero("0");
        Integer t;
        if (flag >= 0) //被除数大于除数，就一直减除数
        {
            while (this->is_neg == 0 && *this != zero)
            {
                t = *this - oth;
                *this = t;
                c = c + one;
            }
        }
        else //被除数小于除数，就为0
        {
            int k = 0;
            for (int i = c.len - 1; i >= 0; i--)
            {
                c.str[k++] = (char)(c.s[i] + 48);
            }
            return c;
        }

        int k = 0;
        for (int i = c.len - 1; i >= 0; i--)
        {
            c.str[k++] = (char)(c.s[i] + 48);
        }
        return c;
    }

    friend ostream &operator<<(ostream &out, const Integer &oth)
    {
        if (oth.is_neg)
            out << "-";
        for (int k = oth.len - 1; k >= 0; k--)
            out << oth.s[k];
        return out;
    }
};

int main()
{
    Integer c;
    char s1[MAXLEN], s2[MAXLEN];

    cout << "Input the first number: " << endl;
    cin >> s1;

    cout << "Input the second number: " << endl;
    cin >> s2;

    Integer a(s1);
    Integer b(s2);

    c = a + b;
    cout << "The plus result is : " << c << endl;

    c = a - b;
    cout << "The minus result is : " << c << endl;

    c = a * b;
    cout << "The multipy result is : " << c << endl;

    c = a / b;
    cout << "The divide result is : " << c << endl;

    system("pause");
    return 0;
}
