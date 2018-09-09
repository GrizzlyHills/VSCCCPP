//用于转换十进制数到k进制数

#include <iostream>
#include <stack>
using namespace ::std;

int main()
{
    long long n, k;
    stack<int> stk;
    cin >> n >> k;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    while (n)
    {
        stk.push(n % k);
        n /= k;
    }
    bool flag = false;
    while (!stk.empty())
    {
        if (k == 16)
        {
            if (flag == false)
            {
                cout << "0x";
                flag = true;
            }
            switch (stk.top())
            {
                case 10:
                    cout << "A";
                    break;
                case 11:
                    cout << "B";
                    break;
                case 12:
                    cout << "C";
                    break;
                case 13:
                    cout << "D";
                    break;
                case 14:
                    cout << "E";
                    break;
                case 15:
                    cout << "F";
                    break;
                default:
                    cout << stk.top();
                    break;
            }
            stk.pop();
        }
        else if (k == 8)
        {
            if (flag == false)
            {
                cout << "0";
                flag = true;
            }
            cout << stk.top();
            stk.pop();
        }
        else
        {
            cout << stk.top();
            stk.pop();
        }
    }
    cout << endl;
    system("pause");
    return 0;
}