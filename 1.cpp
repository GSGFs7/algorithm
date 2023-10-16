#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int nums[N];
int tree[N << 2];
int lazy[N << 2];

void build(int p, int start, int end)
{
    if (start == end)
    {
        tree[p] = nums[start];
        return ;
    }

    int const mid = (start + end) >> 1;
    build(p << 1, start, mid);          // p忘记乘2卡了好久
    build(p << 1 | 1, mid + 1, end);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

/*
inline int pushDown(int p, int start, int end)  // 这个函数会编译器报错
{
    int const mid = (start + end) >> 1;

    // 更新左子节点
    lazy[p << 1] += lazy[p];                    // 添加lazy标记
    tree[p << 1] += lazy[p] * (mid - start + 1);// 还原该节点的值

    // 更新右子系欸但
    lazy[p << 1 | 1] += lazy[p];
    tree[p << 1 | 1] += lazy[p] * (end - mid);

    lazy[p] = 0;    // 清空
}
 */

void addTag(int p, int start, int end, int d)
{
    tree[p] += d * (end - start + 1);
    lazy[p] += d;
}

void pushDown(int p, int start, int end)
{
    if (lazy[p])
    {
        int const mid = (start + end) >> 1;

        addTag(p << 1, start, mid, lazy[p]);
        addTag(p << 1 | 1, mid + 1, end, lazy[p]);

        lazy[p] = 0;
    }
}

void update(int p, int start, int end, int L ,int R, int d)
{
    if (start >= L && end <= R)
    {
        addTag(p, start, end, d);
        return ;
    }

    pushDown(p, start, end);   // 会用到下一层，所以先还原下一层

    int const mid = (start + end) >> 1;
    if (L <= mid) update(p << 1, start, mid, L, R, d);    // 搞混L和start了，卡了一个多小时start >= L
    if (R > mid) update(p << 1 | 1, mid + 1, end, L, R, d);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

int query(int p, int start, int end, int L, int R)
{
    if (start >= L && end <= R) return tree[p];

    pushDown(p, start, end);

    int res = 0;
    int const mid = (start + end) >> 1;
    if (mid >= L) res += query(p << 1, start, mid, L, R);// 这里L和start也搞混了
    if (mid < R) res += query(p << 1 | 1, mid + 1, end, L, R);
    return res;
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    build(1, 1, n);

    int op, L, R, d;
    while (m --)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> L >> R >> d;
            update(1, 1, n, L, R, d);
        }
        else
        {
            cin >> L >> R;
            cout << query(1, 1, n, L, R) << '\n';
        }
    }
    return 0;
}