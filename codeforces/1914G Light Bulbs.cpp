#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出n对数和两个操作，你可以点亮一对亮的灯泡间所有灯泡，灯泡亮了后，另一个也会亮，求最小初始点亮的灯泡和不同的灯泡安排的方式
 * 异或+哈希，处理自闭区间
 * 然后统计变化的次数（跳过相同且连续的两个数），不同区间相乘得到最后的方案数
 *
 * the number of sets S of minimum size (taken modulo 998244353).
 * sets: v,安排
 * 有多少种不同的安排。。。总感觉怪怪的
 * */

const int MOD = 998244353;

// 生成随机数
mt19937_64 rnd(98275314);
int gen()
{
    int x = 0;
    while (x == 0)
        x = rnd();
    return x;
}

vector<int> g;// 记录跳跃
int getBlock(int l, int r)// 统计单个区间有多少方案
{
    int res = 0;
    while (l < r)
    {
        if (g[l] != -1 && g[l] < r) l = g[l];// 跳过重复且连续的两个数
        else res ++, l ++;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    g.clear();
    g.resize(n << 1, -1);
    vector<int> a(n << 1);// 用于存储原数组
    for (int i = 0; i < n << 1; i++) cin >> a[i], a[i] --;// 改为从0开始

    // 哈希种子
    vector<int> val(n);
    for (auto &i : val) i = gen();// 给每个位置标上不同的哈希

    // 处理自闭区间
    int cur = 0;
    int cnt = 1;// 方案数
    int size = 0;// 有多少自闭区间
    map<int, int> last;
    last[0] = 0;
    for (int i = 0; i < n << 1; i++)
    {
        // 异或哈希，只有是自闭区间才会变成0
        cur ^= val[a[i]];// 如果是简单值,可能会出现没有全部重复也归0的情况,所以需要哈希
        if (cur == 0)
        {
            size ++;// 不同的区间
            cnt = (cnt * getBlock(last[0], i + 1)) % MOD;// 不同区间使用乘法
            last.clear();// 重新开始，防止干扰
        }
        else if (last.count(cur)) g[last[cur]] = i + 1;// 第二次出现，把第一次的位置跳到第二次的位置
        last[cur] = i + 1;// 标定第一次出现的位置，或是添加0点
    }

//    for (auto i : a) cout << i << ' '; cout << '\n';
//    for (auto i : g) cout << i << ' '; cout << '\n';
    // 关于g这个数组，用于查找方案数时跳跃
    // 3  4  4  5  3  1  1  5  2  2
    // 对于这组数，两个相同的数相连，那么这两个数就只有一种变化（可以理解为不变），那么就可以直接省略
    // 必须两个点在不相连的位置才可以相互交换，有多种变化
    // -1 3 -1 -1 -1  7 -1 -1 -1 -1
    // g这个数组可以直接指向相同两个数的下一个，跳过这两个数
    // 为什么只有连续的两个数才会被添加？
    // 因为加入了哈希的元素，如果是321123这样的话，就只有两种变化（两个端点不算重复）

    cout << size << ' ' << cnt << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1914/problem/G1
// https://codeforces.com/contest/1914/problem/G2