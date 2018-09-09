// 枚举思想之讨厌的青蛙
/*
* @Author: GrizzlyHills 
* @Date: 2017-09-09 18:11:07 
 * @Last Modified by: GrizzlyHills
 * @Last Modified time: 2017-09-09 18:16:49
    测试数据集
    样例输入
    6 7 //6行7列
    14
    2 1 
    6 6 
    4 2 
    2 5
    2 6
    2 7
    3 4
    6 1
    6 2
    2 3
    6 3
    6 4
    6 5
    6 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int r, c, n;
struct PLANT {
    int x, y;
};
PLANT plants[5001];
PLANT plant;
int searchPath(PLANT secPlant, int dX, int dY) ;
int main()
{
    int i, j, dX, dY, pX, pY, steps, max = 2;
    scanf("%d%d", &r, &c);
    //行数和列数, x方向是上下, y方向是左右
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d %d", &plants[i].x, &plants[i].y);
    //将水稻按x坐标从小到大排序, x坐标相同按y从小到大排序
    sort(plants, plants + n);
    for (i = 0; i < n - 2; i++) //plants[i]是第一个点
        for ( j = i + 1; j < n - 1 ; j++) { //plants[j]是第二个点
            dX = plants[ j ].x - plants[i].x;
            dY = plants[ j ].y - plants[i].y;
            pX = plants[ i ].x - dX;
            pY = plants[ i ].y - dY;
            if (pX <= r && pX >= 1 && pY <= c && pY >= 1)
                continue;
            // 第一点的前一点在稻田里,
            // 说明本次选的第二点导致的x方向步长不合理(太小)
            // 取下一个点作为第二点
            if (plants[ i ].x + (max - 1) * dX > r)
                break;
            //x方向过早越界了. 说明本次选的第二点不成立
            //如果换下一个点作为第二点, x方向步长只会更大, 更不成立, 所以应该
            //认为本次选的第一点必然是不成立的, 那么取下一个点作为第一点再试 19
            pY = plants[ i ].y + (max - 1) * dY;
            if ( pY > c || pY < 1)
                continue; //y方向过早越界了, 应换一个点作为第二点再试
            steps = searchPath(plants[ j ], dX, dY);
            //看看从这两点出发, 一共能走几步
            if (steps > max) max = steps;
        }
    if ( max == 2 ) max = 0;
    printf("%d\n", max);
    system("pause");
    return 0;
}
bool operator < ( const PLANT &p1, const PLANT &p2)
{
    if ( p1.x == p2.x )
        return p1.y < p2.y;
    return p1.x < p2.x ;
}
//判断从 secPlant点开始, 步长为dx, dy, 那么最多能走几步
int searchPath(PLANT secPlant, int dX, int dY)
{
    PLANT plant;
    int steps;
    plant.x = secPlant.x + dX;
    plant.y = secPlant.y + dY;
    steps = 2;
    while (plant.x <= r && plant.x >= 1 && plant.y <= c && plant.y >= 1) {
        if (! binary_search(plants, plants + n, plant)) {
            //每一步都必须踩倒水稻才算合理, 否则这就不是一条行走路径
            steps = 0;
            break;
        }
        plant.x += dX;
        plant.y += dY;
        steps++;
    }
    return(steps);
}