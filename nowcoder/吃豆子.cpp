#include <iostream>
using namespace std;

// 两个人吃到2n个豆子，路径不能重复
// 所以，必须一个人从2到终点，一个人从3到终点
// up1必须低于down2，让下面的人可以从2到底
// up2必须低于down3，让上面的人可以从3到底/

int main()
{
    int n, m;
    cin >> n >> m;
    int up1 = 1e6, up2 = 1e6, down2 = 0, down3 = 0;// 3条路上的最高点和最低点
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1) up1 = min(up1, b);// 该点之下的路径无效
        if (a == 2) up2 = min(up2, b), max(down2, b);// 两点之间的路径无效，路径会重合
        if (a == 3) down3 = max(down3, b);// 该点之上的路径无效
    }
    if (up1 <= down2 + 1) puts("NO");
    else if (up2 - 1 <= down3) puts("NO");
    else puts("YES");
    return 0;
}


// https://ac.nowcoder.com/acm/contest/53915/F