#include <bits/stdc++.h>
#define int long long
using namespace std;

int const N = 1e5 + 10;
int f[N];

/*
 * 混合背包
 * 根据数量划分为普通的背包分别处理，处理完了直接下一个
 * */

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    string s1, s2;
    int n;
    cin >> s1 >> s2 >> n;

    vector<int> w(n + 1), v(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i] >> s[i];

    // 换算为分钟
    int h1 = 0, m1 = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == ':') {
            for (i++; s1[i] != '\0'; i++)// 别忘记要先跳过冒号
                m1 = 10 * m1 + s1[i] - '0';
            break;
        }

        h1 = 10 * h1 + s1[i] - '0';
    }
    int h2 = 0, m2 = 0;
    for (int i = 0; s2[i] != '\0'; i++) {
        if (s2[i] == ':') {
            for (i++; s2[i] != '\0'; i++)
                m2 = 10 * m2 + s2[i] - '0';
            break;
        }

        h2 = 10 * h2 + s2[i] - '0';
    }
    int t = (h2 - h1) * 60 + m2 - m1;

    //debug
//    cout << t << '\n';
//    cout << h1 << ' ' << m1 << '\n';
//    cout << h2 << ' ' << m2 << '\n';

    for (int i = 1; i <= n; i++)
        if (!s[i])// 完全背包
            for (int j = w[i]; j <= t; j++)
                f[j] = max(f[j], f[j - w[i]] + v[i]);
        else// 多重背包，二进制优化
            for (int k = 1, num = s[i]; k > 0; k <<= 1) {// 只需要把数量拆为二进制即可
                if (k > num) k = num;// 最后一个k
                num -= k;

                for (int j = t; j >= w[i] * k; j--)// 01背包
                    f[j] = max(f[j], f[j - w[i] * k] + v[i] * k);
            }

    cout << f[t] << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P1833
// 二进制优化前288ms，优化后104ms