#include <bits/stdc++.h>

using namespace std;

/*
  给出一个数组, 问l和r之间连续子段和的绝对值的最大值是多少
  即找出x,y, 符合l<=x<=y<=r, 使得abs(a[x]+a[x+1]...+a[y])最大

  用ST表求静态区间极值(RMQ)
  用ST表处理前缀和, 记录下前缀和的大小
    区间子数组的绝对值最大和=区间前缀和的最大值-区间前缀和的最小值
  即可得到结果
*/

#define int long long
const int N = 2e5 + 10;
int n;
int a[N];
int sum[N];
int mi[N][20], ma[N][20];

void init() {
    for (int i = 1; i <= n; i++) ma[i][0] = mi[i][0] = sum[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 <= n; i++) {
            mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
            ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int getmax(int l, int r) {
    if (l > r) return 0;
    int k = __lg(r - l + 1);
    return max(ma[l][k], ma[r - (1 << k) + 1][k]);
}

int getmin(int l, int r) {
    if (l > r) return 0;
    int k = __lg(r - l + 1);
    return min(mi[l][k], mi[r - (1 << k) + 1][k]);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    init();

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // 区间子数组的绝对值最大和=区间前缀和的最大值-区间前缀和的最小值
        int lft, rit;
        lft = getmax(l, r);
        rit = getmin(l, r);
        lft = max(lft, sum[l - 1]);    // 如果是不取的情况
        rit = min(rit, sum[l - 1]);
        cout << lft - rit << '\n';
    }
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://ac.nowcoder.com/acm/contest/86034/F
// 2024年7月15日