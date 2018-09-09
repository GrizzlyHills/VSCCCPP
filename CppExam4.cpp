/*
 * @Author: GrizzlyHills 
 * @Date: 2017-08-22 19:17:10 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-08-23 09:34:40

    编程题＃5：计算数组的低3位之和

    描述
    输入一个正整数构成的数组a[0], a[1], a[2], ... , a[n-1], 计算它们的二进制低3位之和。

    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;
    // 在此处补充你的代码
    int main(int argc, char* argv[]) {
            int v, my_sum=0;
            vector<int> vec;
            cin>>v;
            while ( v ) {
                    vec.push_back(v);
                    cin>>v;
            }
            for_each(vec.begin(), vec.end(), CMy_add(my_sum));
            cout<<my_sum<<endl;
            return 0;
    }

    输入
    数组a,以0表示输入结束。

    输出
    一个整数 , 所输入数组各元素的二进制低3位之和。

    样例输入
    1 3 9 7 3 6 20 15 18 17 4 8 18 0

    样例输出
    41
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 在此处补充你的代码
class CMy_add
{
    private:
        int& sum;
    public:
        CMy_add(int& n): sum(n) {}
        void operator() (int x)
        {
            x %= 8;                 //得到其低3位
            sum += x;
        }
};

int main(int argc, char *argv[])
{
    int v, my_sum = 0;
    vector<int> vec;
    cin >> v;
    while (v)
    {
        vec.push_back(v);
        cin >> v;
    }
    for_each(vec.begin(), vec.end(), CMy_add(my_sum));
    cout << my_sum << endl;

    my_sum = 0;
    for(auto &tmp : vec) {                      //自己另外加的 for range 循环，比 for_each 方法简单
        my_sum += tmp % 8;
    }
    cout << my_sum << endl;

    system("pause");
    return 0;
}