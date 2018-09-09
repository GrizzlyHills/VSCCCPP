#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cmath>
using namespace std;

//直观判断法
bool isPrime_1(int num);

// 上述判断方法，明显存在效率极低的问题。对于每个数n，其实并不需要从2判断到n-1，
// 我们知道，一个数若可以进行因数分解，那么分解时得到的两个数一定是一个小于等于sqrt(n)，一个大于等于sqrt(n)，
// 据此，上述代码中并不需要遍历到n-1，遍历到sqrt(n)即可，因为若sqrt(n)左侧找不到约数，那么右侧也一定找不到约数。
// C++代码如下：
bool isPrime_2(int num);

// 方法（2）应该是最常见的判断算法了，时间复杂度O(sqrt(n))，速度上比方法（1）的O(n)快得多。最近在网上偶然看到另一种更高效的方法，暂且称为方法（3）吧，
// 由于找不到原始的出处，这里就不贴出链接了，如果有原创者看到，烦请联系我，必定补上版权引用。下面讲一下这种更快速的判断方法；
// 首先看一个关于质数分布的规律：大于等于5的质数一定和6的倍数相邻。例如5和7，11和13,17和19等等；

// 证明：令x≥1，将大于等于5的自然数表示如下：
// ······ 6x-1，6x，6x+1，6x+2，6x+3，6x+4，6x+5，6(x+1），6(x+1)+1 ······
// 可以看到，不在6的倍数两侧，即6x两侧的数为6x+2，6x+3，6x+4，由于2(3x+1)，3(2x+1)，2(3x+2)，所以它们一定不是素数，再除去6x本身，显然，素数要出现只可能出现在6x的相邻两侧。
// 这里有个题外话，关于孪生素数，有兴趣的道友可以再另行了解一下，由于与我们主题无关，暂且跳过。这里要注意的一点是，在6的倍数相邻两侧并不是一定就是质数。
// 此时判断质数可以6个为单元快进，即将方法（2）循环中i++步长加大为6，加快判断速度，
// 原因是，假如要判定的数为n，则n必定是6x-1或6x+1的形式，对于循环中6i-1，6i，6i+1,6i+2，6i+3，6i+4，
// 其中如果n能被6i，6i+2，6i+4整除，则n至少得是一个偶数，但是6x-1或6x+1的形式明显是一个奇数，故不成立；
// 另外，如果n能被6i+3整除，则n至少能被3整除，但是6x能被3整除，故6x-1或6x+1（即n）不可能被3整除，故不成立。
// 综上，循环中只需要考虑6i-1和6i+1的情况，即循环的步长可以定为6，每次判断循环变量k和k+2的情况即可，理论上讲整体速度应该会是方法（2）的3倍。
// 代码如下：
bool isPrime_3(int num);

int main()
{
    int test_num = 100;
    int tstart, tstop; //分别记录起始和结束时间
    //测试第一个判断质数函数
    tstart = clock();
    for (int i = 1; i <= test_num; i++)
        if (isPrime_1(i))
        {
            cout << i << "\t";
        }
    tstop = clock();
    cout << "方法(1)时间(ms):" << tstop - tstart << endl; //ms为单位
    //测试第二个判断质数函数
    tstart = clock();
    for (int i = 1; i <= test_num; i++)
        isPrime_2(i);
    tstop = clock();
    cout << "方法(2)时间(ms):" << tstop - tstart << endl;
    //测试第三个判断质数函数
    tstart = clock();
    for (int i = 1; i <= test_num; i++)
        isPrime_3(i);
    tstop = clock();
    cout << "方法(3)时间(ms):" << tstop - tstart << endl;
    cout << endl;
    system("pause");
    return 0;
}

bool isPrime_1(int num)
{
    int tmp = num - 1;
    for (int i = 2; i <= tmp; i++)
        if (num % i == 0)
            return 0;
    return 1;
}

bool isPrime_2(int num)
{
    int tmp = sqrt(num);
    for (int i = 2; i <= tmp; i++)
        if (num % i == 0)
            return 0;
    return 1;
}

bool isPrime_3(int num)
{
    //两个较小数另外处理
    if (num == 2 || num == 3)
        return 1;
    //不在6的倍数两侧的一定不是质数
    if (num % 6 != 1 && num % 6 != 5)
        return 0;
    int tmp = sqrt(num);
    //在6的倍数两侧的也可能不是质数
    for (int i = 5; i <= tmp; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    //排除所有，剩余的是质数
    return 1;
}
