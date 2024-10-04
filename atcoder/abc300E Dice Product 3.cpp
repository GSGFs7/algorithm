#include <iostream>
#include <unordered_map>

using namespace std;

/*
  有一个六面骰子，每次可以投出1-6点，可以投无限多次，问投出的点数的乘积是N的概率是多少

  因为点数是1-6,那么质因数也就只有2，3，5
  假设最后的概率是dp[n]，那么推出dp[n]这个点的方式就是dp[n]=1/6*dp[n/1]+1/6*dp[n/2]...1/6*dp[n/6]
  也就是说得到dp[n]这个点的概率是得到n/2这个点的基础上在使用1/6的概率投出2点
  如果N中出现除了2，3，5这三个质因数之外的数也就是永远都不可能投出来
  简化上面的式子，除掉1这一部分变成 dp[n]=1/5*dp[n/2]+1/5dp[n/3]...1/5*dp[n/6]
  也就是说直接从2，3，5开始向上递推，再使用记忆化就可以得出每一步的结果，最后得到dp[n]
*/

#define int long long

const int MOD = 998244353;
unordered_map<int, int> mp;

// 快速幂
int fastpow(int x, int y) {
    int res = 1;
    int base = x;
    while (y) {
        if (y & 1) res = res * base % MOD;
        base = base * base % MOD;
        y >>= 1;
    }
    return res;
}

// 逆元
inline int inv(int n) { return fastpow(n, MOD - 2); }

// 记忆化
int dfs(int u) {
    if (u == 1) return 1;
    if (mp.find(u) != mp.end()) return mp[u];    // 如果之前存在过

    int ans = 0;
    for (int i = 2; i <= 6; i++) {    // 枚举除了1之外的每个点
        if (u % i == 0) ans = (ans + dfs(u / i)) % MOD;    // 从最下面开始向上回溯
    }
    mp[u] = ans * inv(5) % MOD;// 计算到u的概率
    return mp[u];
}

void solve() {
    int n;
    cin >> n;
    int back = n;
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;
    if (n != 1) return cout << 0 << '\n', void();

    cout << dfs(back) << '\n';
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


// https://atcoder.jp/contests/abc300/tasks/abc300_e
// 2024-09-21