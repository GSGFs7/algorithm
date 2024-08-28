#include <iostream>
using namespace std;

// 快速幂 + 前缀和 + 取模
// 特别注意：超出取模范围的数全部重新开始

int const N = 1e5 + 10;
int arr[N];
int const mod = 10000;

// 快速幂
int quickPower(int x, int y)
{
    long long ans = 1, base = x;

    while (y)
    {
        if (y & 1) { ans *= base; ans = ans % mod; }

        base *= base;// 自增
        base = base % mod;

        y >>= 1;
    }

    return ans % mod;
}

inline void solve()
{
    int a, b;
    cin >> a >> b;
    arr[0] = 0;

    // 预处理，求前缀和数组
    for (int i = 1; i <= mod; i++)// 开到10000即可，否则1e9的数据量必炸，因为数据对10000取模，10000往后的数据全部重复
        arr[i] = (quickPower(i, b) + arr[i - 1]) % mod;

    // O(1)求出答案？？？？？？？？？？
    cout << (a / mod * arr[mod] + arr[a % mod]) % mod << endl;
    // 超出10000的部分全部是重复的
    // a / mod表示a在arr中重复了多少次，重复的次数乘以他们的和 再加上超出的部分就是结果
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.luogu.com.cn/problem/P1630