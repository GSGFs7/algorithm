#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/* 概率动态规划 */
/* n个点，m条边，求到n点的概率 */

/// 费马小定理
// 当分数需要mod 1e9+7时可使用（正常情况下小数不可取模）
// 最简分数
// a/b mod p 找到c使得 bc ≡ a(mod p)  (该式含义为bc mod p = a mod p)
// 由费马小定理
// a/b mod p 可写为 b^(p-1) ≡ 1(mod p)   (a不是p的倍数)
// 两边同除b b^(p-2) ≡ b^(-1)(mod p)
// 所以a*b^(p-2) mod p 就可以代替 a/b mod p

const int N = 110, p = 1000000007;
long long f[N];

// 快速幂
long long rp(long long now, int k)
{
    long long res = 1;
    for (; k; k >>= 1, now *= now, now %= p)
        if (k & 1)
            res *= now, res %= p;
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a[N];
    for (int i = 1, x, y; i <= m; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
    }

    memset(&f, 0, sizeof(f));
    f[1] = 1;
    for (int i = 1; i < n; i++)
    {
        int const l = a[i].size();
        for (int j = 0; j < l; j++)
            f[a[i][j]] += f[i] * rp(l, p - 2), f[a[i][j]] %= p;// 状态转移方程
    }
    printf("%d", f[n]);// 模完后的数小于int范围所以可以用%d输出
    return 0;
}