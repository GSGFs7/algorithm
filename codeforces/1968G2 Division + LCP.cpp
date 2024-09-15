#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Shash {
    const ll base[2] = {29, 31};
    const ll hashmod[2] = {(ll)1e9 + 9, 998244353};

    array<vector<ll>, 2> hsh;
    array<vector<ll>, 2> pwMod;
    void init(string S) {
        int n = S.size();
        S = ' ' + S;
        hsh[0].resize(n + 1), hsh[1].resize(n + 1);
        pwMod[0].resize(n + 1), pwMod[1].resize(n + 1);
        for (int i = 0; i < 2; ++i) {
            pwMod[i][0] = 1;
            for (int j = 1; j <= n; ++j) {
                pwMod[i][j] = pwMod[i][j - 1] * base[i] % hashmod[i];
                hsh[i][j] = (hsh[i][j - 1] * base[i] + S[j]) % hashmod[i];
            }
        }
    }
    pair<ll, ll> get(int l, int r) {
        pair<ll, ll> ans;
        ans.first = (hsh[0][r] - hsh[0][l - 1] * pwMod[0][r - l + 1]) % hashmod[0];
        ans.second = (hsh[1][r] - hsh[1][l - 1] * pwMod[1][r - l + 1]) % hashmod[1];
        ans.first = (ans.first + hashmod[0]) % hashmod[0];
        ans.second = (ans.second + hashmod[1]) % hashmod[1];
        return ans;
    }
};

bool same(Shash &a, int la, int ra, Shash &b, int lb, int rb) {
    return a.get(la, ra) == b.get(lb, rb);
}

void solve() {
    int n, l1, r1;
    cin >> n >> l1 >> r1;
    string s;
    cin >> s;
    Shash a;
    a.init(s);

    // 找 LCP为x , 最多切几段
    // 从长到短倒着找LCP

    // 以 i 开头的前缀与 1 开头的前缀的 LCP
    vector<vector<int>> g(n + 1);
    auto check = [&](int l, int m) -> bool {    // 以l为起点, 长度为m的子串
        int r = l + m - 1;
        if (r > n) return 0;
        return same(a, 1, m, a, l, r);
    };
    // 二分, 对于一个字符串, 如果前l是匹配的, 那么l1<l也是匹配的
    for (int i = 1; i <= n; i++) {
        int l = 0, r = n + 1;
        while (l + 1 < r) {
            int m = l + r >> 1;
            if (check(i, m))
                l = m;
            else
                r = m;
        }
        g[l].push_back(i);    // 以l为起点的子串有那些匹配值
    }

    // 可以与前缀匹配的点
    vector<int> f(n + 1);
    f[1] = n;    // 可以和自己匹配
    set<int> st;
    st.insert(n + 1);    // 右边界
    for (int len = n; len >= 1; len--) {
        for (auto x : g[len]) st.insert(x);    // 取出这个起点的所有值

        int k = 1;
        int pos = len + 1;
        while (pos <= n) {
            int nx = *st.lower_bound(pos);
            if (nx > n) break;
            k++;
            int r = nx + len - 1;
            pos = r + 1;
        }
        f[k] = max(f[k], len);
    }

    for (int i = n - 1; i >= 1; i--) f[i] = max(f[i], f[i + 1]);
    for (int i = l1; i <= r1; i++) cout << f[i] << ' ';
    cout << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}


// https://codeforces.com/contest/1968/problem/G2
// 2024年5月17日