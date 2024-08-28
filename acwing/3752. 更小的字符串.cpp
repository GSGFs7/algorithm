#include <iostream>
using namespace std;

/*
 * 数位DP
 * 判断当前数位的可能情况的数量，将所有数量相加得到最后的数位DP结果
 * */

typedef long long LL;
const int N = 1e5 + 10, MOD = 1e9 + 7;
LL p[N];// 预处理数组，记得开long long不然也会爆
int cases = 0;

void solve()
{
    int n, m;
    string s;
    cin >> n >> m >> s;

    /// 预处理
    p[0] = 1;// 预处理值，表示在当前自由度下可取的值
    for (int i = 1; i <= n; i++)
        p[i] = (LL)(p[i - 1] * m) % MOD;// 求出在没有限制的情况下的最大值

    /// 数位统计DP
    int const mid = (n + 1) / 2;// 自由度
    LL res = 0;
    for (int i = 0; i < mid; i++)
    {
        // 当前位置剩下的可选值乘以后续无限制的值，表示当前位置的值
        res += (LL)(s[i] - 'a') * p[mid - i - 1] % MOD;
        res %= MOD;
    }

    /// 检查最后一次计算的结果的字典序是否小于题目给出的，直接检查原数组看是否能塞下
    int t = 0;
    for (int i = mid - 1, j = n - 1 - i; i >= 0; i --, j ++)
        if (s[i] != s[j])
        {
            if (s[i] < s[j]) t = 1;
            break;
        }

    res = (LL)(res + t) % MOD;
    cout << "Case #" << ++ cases << ": " << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/description/3755/