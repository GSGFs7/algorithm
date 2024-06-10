#include <iostream>
#include <vector>

using namespace std;

/*
  给出圆上n个点, 使一些点的度为奇数, 一些为偶数, 求一个方法连接n-1条边满足给出的条件

  思路:
    画图, 对于一条边, 起点必定是奇数
    对于终点而言直接全部连到任意一个奇数点上即可
*/

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> odd;             // 奇数点
    vector<bool> a(n, false);    // 是否是奇数点
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            odd.push_back(i);
            a[i] = true;
        }
    }

    // 至少存在两个叶子节点, 并且奇数度数的节点成对存在
    // (因为一条边连两个点, 不可能存在总度数为奇数的情况)
    if (odd.empty() || odd.size() % 2) return cout << "No\n", void();

    cout << "Yes\n";
    vector<pair<int, int>> ans;
    vector<int> b;    // 尾巴
    for (auto i : odd) {
        while (!a[(i + 1) % n]) ans.push_back({i, (i + 1) % n}), i++, i %= n;
        b.push_back(i);    // 在最后一个偶数点停下
    }
    // 剩下的数与任意一条边相连
    // cout << b.size() << '\n'; b的大小总为偶数
    for (int i = 1; i < b.size(); i++) ans.push_back({b[0], b[i]});
    for (auto i : ans) cout << i.first + 1 << ' ' << i.second + 1 << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://codeforces.com/contest/1682/problem/D
// 2024年5月29日