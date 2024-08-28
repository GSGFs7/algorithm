#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n, m;
int tree[N];

inline int lowBit(int x)
{
    return (-x) & x;
}

void update(int x, int k)
{
    while (x <= n && x > 0)
    {
        tree[x] += k;
        x += lowBit(x);
    }
}

int query(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += tree[x];
        x -= lowBit(x);
    }
    return res;
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n >> m;

    while (m--)
    {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op[0] == 'x') update(a, b);
        if (op[0] == 'y') cout << query(b) - query(a - 1) << '\n';
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P2068