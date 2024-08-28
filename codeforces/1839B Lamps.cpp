#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 题意：
 * 对于每盏灯给出a[i]和b[i]
 * a[i]表示在a[i]这种灯中最多只能取i盏
 * b[i]表示得分
 * 使得分最大化
 *
 * 将每层的得分从大到小排序
 * 每层从前开始取最多的值
 * */

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end(), greater());
        for (int j = 0; j < min(i, (int)v[i].size()); j++)
            ans += v[i][j];
    }

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


// https://codeforces.com/problemset/problem/1839/B