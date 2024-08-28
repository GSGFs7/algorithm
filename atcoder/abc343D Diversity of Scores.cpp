#include "bits/stdc++.h"

using namespace std;
#define int long long
typedef pair<int, int> pii;

/*
 * 题目描述:
 *  n个人，进行t轮操作
 *  每次操作，选择一个人x，将他的分数加上y
 *  求每次操作后有多少个不同的分数
 * 输入描述:
 *  第一行两个整数n, t
 *  接下来t行，每行两个整数x, y
 * 输出描述:
 *  输出t行，每行一个整数，表示每次操作后不同的分数个数
 *
 * 思路:
 *  离散化
 *  利用两个map，mp 当前分数的人数，cnt 当前编号这个人的得分
 *  进行一次操作后原来的分数就会发生变化，需要减去一
 *  原来的数加上y后就会成为新的分数，需要加上一
 *  如果这个分数的人数变成0，就删掉对应的mp数值，这样直接输出mp的size即可
 * */

void solve() {
    int n, t;
    cin >> n >> t;// n人数，t轮次
    map<int, int> mp;// mp[i] 当前分数的人数
    map<int, int> cnt;// cnt[i] 当前编号的得分
    mp[0] = n;
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        mp[cnt[x]] --;// 原本积分为cnt[x]的减少一人
        if (!mp[cnt[x]]) mp.erase(cnt[x]);// 如果没有人拥有这个分数，删除这个分数
        cnt[x] += y;// 更新这个人的分数
        mp[cnt[x]] ++;// 减少的那个人加入到新的cnt[x]中
        cout << mp.size() << '\n';
    }
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://atcoder.jp/contests/abc343/tasks/abc343_d