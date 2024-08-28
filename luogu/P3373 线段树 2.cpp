#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 同时存在加法与乘法的线段树
 * 加法标记不会影响到乘法标记，但是乘法标记会影响到加法标记
 * 在计算乘法时也要注意加法的更新
 * */

const int N = 1e5 + 10;
int mod;
int nums[N];
int tree[N << 2];       // 线段树
int mulLazy[N << 2];    // 乘法Lazy标记
int addLazy[N << 2];    // 加法Lazy标记

void build(int p, int start, int end)
{
    mulLazy[p] = 1; // 初始化

    if (start == end)
    {
        tree[p] = nums[start];
        tree[p] %= mod;
        return ;
    }

    int const mid = (start + end) >> 1;
    build(p << 1, start, mid);
    build(p << 1 | 1, mid + 1, end);
    tree[p] = (tree[p << 1] + tree[p << 1 | 1]) % mod;
}

void pushDown(int p, int start, int end)
{
    int const mid = (start + end) >> 1;

    // 清除乘法标记
    if (mulLazy[p] != 1)
    {
        // 左子树
        tree[p << 1] *= mulLazy[p];
        mulLazy[p << 1] *= mulLazy[p];
        addLazy[p << 1] *= mulLazy[p];  // 需要同步计算加法，乘法会影响加法

        // 右子树
        tree[p << 1 | 1] *= mulLazy[p];
        mulLazy[p << 1 | 1] *= mulLazy[p];
        addLazy[p << 1 | 1] *= mulLazy[p];

        // 取模
        tree[p << 1] %= mod;
        tree[p << 1 | 1] %= mod;
        mulLazy[p << 1] %= mod;
        mulLazy[p << 1 | 1] %= mod;
        addLazy[p << 1] %= mod;
        addLazy[p << 1 | 1] %= mod;

        mulLazy[p] = 1;

    }

    // 清除加法标记
    if (addLazy[p])
    {
        // 左子树
        tree[p << 1] += addLazy[p] * (mid - start + 1);
        addLazy[p << 1] += addLazy[p];

        // 右子树
        tree[p << 1 | 1] += addLazy[p] * (end - mid);
        addLazy[p << 1 | 1] += addLazy[p];

        // 取模
        tree[p << 1] %= mod;
        tree[p << 1 | 1] %= mod;
        addLazy[p << 1] %= mod;
        addLazy[p << 1 | 1] %= mod;

        addLazy[p] = 0;
    }

}

void mul(int p, int start, int end, int L, int R,int d)
{
    if (L <= start && end <= R)
    {
        mulLazy[p] *= d;
        mulLazy[p] %= mod;
        tree[p] *= d;
        tree[p] %= mod;
        addLazy[p] *= d;    // 注意！乘操作会影响加操作，在清除Lazy标记时也需要传递到子树上
        addLazy[p] %= mod;
        return ;
    }

    pushDown(p, start, end);    // 会用到下一层，提前更新

    int const mid = (start + end) >> 1;
    if (L <= mid) mul(p << 1, start, mid, L, R, d);         // 左子树为p << 1，写代码时又忘记了，写了p
    if (mid < R) mul(p << 1 | 1, mid + 1, end, L, R, d);
    tree[p] = (tree[p << 1] + tree[p << 1 | 1]) % mod;              // pushUp操作，保证上面的所有值都是正确的
}

void add(int p, int start, int end, int L, int R, int d)
{
    if (L <= start && end <= R)
    {
        addLazy[p] += d;
        addLazy[p] %= mod;
        tree[p] += d * (end - start + 1);
        tree[p] %= mod;
        return ;
    }

    pushDown(p, start, end);

    int const mid = (start + end) >> 1;
    if (L <= mid) add(p << 1, start, mid, L, R, d);
    if (mid < R) add(p << 1 | 1, mid + 1, end, L, R, d);
    tree[p] = (tree[p << 1] + tree[p << 1 | 1]) % mod;
}

int query(int p, int start, int end, int L, int R)
{
    if (L <= start && end <= R) return tree[p] % mod;

    pushDown(p, start, end);

    int res = 0;
    int const mid = (start + end) >> 1;
    if (L <= mid) res += query(p << 1, start, mid, L, R);
    if (mid < R) res += query(p << 1 | 1, mid + 1, end, L, R);
    return res % mod;
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    build(1, 1, n);

    while (m --)
    {
        int op, l, r, d;
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r >> d;
            mul(1, 1, n, l, r, d);
        }
        else if (op == 2)
        {
            cin >> l >> r >> d;
            add(1, 1, n, l, r, d);
        }
        else
        {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P3373