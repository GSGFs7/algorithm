#include <iostream>
using namespace std;

// 给定回型轨道，求最小距离
// 区间划分 + 端点选择

void solve()
{
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // 全部映射到左上角的区域中
    if (x1 > n / 2) x1 = n + 1 - x1;
    if (y1 > n / 2) y1 = n + 1 - y1;
    if (x2 > n / 2) x2 = n + 1 - x2;
    if (y2 > n / 2) y2 = n + 1 - y2;

    // 观察可知，x，y中较小的坐标为轨道的拐点，对比拐点即可求出距离
    int ans = abs(min(x1, y1) - min(x2, y2));
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.luogu.com.cn/problem/CF1811B
// https://codeforces.com/problemset/problem/1811/B