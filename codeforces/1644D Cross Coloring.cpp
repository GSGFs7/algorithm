#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

/*
  给出一个n*m的白布，可以选择q个点并将这q个对应的行列全部染上k种颜色中的一种，问不同染色的方案数

  因为后面的会直接覆盖掉前面的，如果被完全覆盖也就是这个染色没有任何作用了
  因为一次染上的颜色是相同的，也就是说无论是前是后，只要最后能留下来格子，这些格子都共享k的方案数
  可以直接从后面开始往前推，如果不能染色就直接跳过，如果可以就直接乘上k
  还有一个很坑的点，长宽是不一样的，也就是说长的那一边可以直接吧短的那一边塞满
  不能单独只判断这行或是这列有没有被染色，还要判断是否已经被染满了
*/

#define int long long
int MOD = 998244353;

void solve() {
    int n, m, k, Q;
    cin >> n >> m >> k >> Q;
    vector<pair<int, int>> q(Q);
    for (auto &i : q) cin >> i.first >> i.second;

    int ans = 1;
    int cntx = 0, cnty = 0;
    map<int, int> mp1, mp2;
    for (int i = Q - 1; i >= 0; i--) {
        if (mp1[q[i].first] && mp2[q[i].second]) continue;
        if (cntx >= n || cnty >= m) continue;    // 可能有一边会被塞满

        if (!mp1[q[i].first]) {
            mp1[q[i].first] = 1;
            cntx++;    // 占领一行
        }
        if (!mp2[q[i].second]) {
            mp2[q[i].second] = 1;
            cnty++;    // 占领一列
        }
        ans = 1LL * ans * k % MOD;
    }
    cout << ans << '\n';
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


// https://codeforces.com/contest/1644/problem/D
// 2024-10-08