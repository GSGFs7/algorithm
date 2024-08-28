#include <iostream>
#include <cstring>

using namespace std;

// 注意数据范围
// n<10 适用暴搜
// 暴力计算量大概为10!*10*10
// 位置尽量靠前

const int N = 12;

bool st[N];
int n;

struct Plane
{
    int t, d, l;
}p[N];

bool dfs(int cur, int last)// last 表示上一架飞机的时间
{
    if (cur == n) return true;

    for (int i = 0; i < n; i++)
    {
        int t = p[i].t, d = p[i].d, l = p[i].l;
        if (!st[i] && t + d >= last)// 如果抵达时间加上停留时间小于上一架飞机降落时间直接跳过
        {
            st[i] = true;// 使用标记
            if (dfs(cur + 1, max(last, t) + l)) return true;// 如果找到，依次回溯
            // 抵达时间和上一架飞机起飞时间取最大值
            st[i] = false;
        }
    }
    return false;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t, d, l;
        cin >> t >> d >> l;
        p[i] = {t, d, l};
    }

    memset(st, false, sizeof st);// 注意清除上一个数据的状态
    if (dfs(0, 0)) puts("YES");
    else puts("NO");
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

// https://www.acwing.com/problem/content/4960/