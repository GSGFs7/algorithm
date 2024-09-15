#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
  给出一个数组, 求对整个数组是否存在[i,j]区间, 使区间最大值不小于区间之和

  思路:
    线段树维护区间(包括子区间的)最大值
    这样只需要枚举每个点然后用O(logn)的复杂度查询即可, 总复杂度O(nlogn)

    也可以用ST表实现
*/

#define int long long
const int N = 2e5 + 10;
int n;
int a[N];
int L[N], R[N];    // 左右第一个大于的位置
int sum[N];        // 前缀和

// ST表
int mi[N][20], ma[N][20];
int getmin(int l, int r) {                            // 找最小值
    if (l > r) return 0;                              //
    int k = __lg(r - l + 1);                          // 还原长度
    return min(mi[l][k], mi[r - (1 << k) + 1][k]);    // +1
}

int getmax(int l, int r) {    // 找最大值
    if (l > r) return 0;
    int k = __lg(r - l + 1);
    return max(ma[l][k], ma[r - (1 << k) + 1][k]);
}

void init() {
    for (int i = 1; i <= n; i++) ma[i][0] = mi[i][0] = sum[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 <= n; i++) {
            mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
            ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 用前缀和建立ST表
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    init();

    // 两个单调栈
    a[0] = a[n + 1] = 1e9 + 10;    // a[i]可以等于1e9!!!
    stack<int> st;
    for (int i = 0; i <= n; i++) {    // 从大到小的单调栈
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (st.empty()) st.push(i);
        L[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();

    // for (int i = 1; i <= n; i++) cout << L[i] << ' ';
    // cout << '\n';

    for (int i = n + 1; i >= 1; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (st.empty()) st.push(i);
        R[i] = st.top() - 1;
        st.push(i);
    }

    for (int i = 1; i <= n; i++) {
        int minn = getmin(L[i] - 1, i - 1);    // 区间最小值, 因为是前缀和
        int maxn = getmax(i, R[i]);            // 区间最大值
        if (maxn - minn > a[i]) return cout << "NO\n", void();
    }
    cout << "YES\n";
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


// https://codeforces.com/contest/1691/problem/D
// 2024年5月23日