#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
#define int long long

const int N = 1e5 + 10;
int f[N][500], g[N][500];
// f[i][j]表示i这个位置在步长为j的情况下的前缀和
// g[i][j]表示f[i][j]的不带系数版本,即a[i]+a[i+j]+...+a[i+j(k-1)],用于计算前缀和

void init() {
    memset(&f, 0, sizeof f);
    memset(&g, 0, sizeof g);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);
    for (auto& i : a) cin >> i;

    // 预处理
    int sq = sqrt(n);
    for (int d = 1; d <= sq; d++) {
        for (int i = 1; i <= n; i++) {
            if (i < d) {// 如果是前缀和中的第一个值
                f[i][d] = a[i - 1] * ((i - 1) / d + 1);// a[1]是必须取的值，接下来每达到一次d就是下一个值的位置,所以就是 (i-1)/d+1
                g[i][d] = a[i - 1];
            } else {
                f[i][d] = f[i - d][d] + a[i - 1] * ((i - 1) / d + 1);
                g[i][d] = g[i - d][d] + a[i - 1];
            }
        }
    }

    while (q --) {
        int s, d, k;
        cin >> s >> d >> k;
        int ans = 0;
        if (d > sq) { // 如果步长大于根号，直接暴力处理
            for (int j = 0; j < k; j++)
                ans += 1ll * a[s + j * d - 1] * (j + 1);
        } else { // 如果小于就用前缀和
            ans = f[s + d * (k - 1)][d] - ((s - d > 0) ? f[s - d][d] : 0);
            ans -= (g[s + d * (k - 1)][d] - ((s - d > 0) ? g[s - d][d] : 0)) * ((s - 1) / d);
        }
        cout << ans << ' ';
    }
    cout << '\n';
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1921/problem/F
// 1981 ms 	783700 KB  差点就过不了了