#include <bits/stdc++.h>
#define int long long
using namespace std;

/// 线段树+开方

/*
 * 1.选择一个区间，对区间内的每一个数进行开方（向下取整）
 * 2.选择一个区间，对区间内的数求和
 *
 * 因为每个数的最大值为2^63，经过最多7次开方就会变为1，对1开方依旧为1
 * 当区间内的数全部变成1时就可以直接忽略，提升运行速度
 * 时间复杂度：
 *  对N个数开方7次，7N，经行M次修改，线段树的修改时间复杂度O(logn)，合起来就是O(mlogn)的复杂度
 *
 * 区间修改时对于不是1的元素直接修改（lazy标记难搞，反正不用运行多少次）
 * 当一整个区间全部变成1时，直接跳过
 * */

const int N = 1e5 + 10;
int nums[N];
int tree[N << 2];
int cases = 0;

void build(int p, int start, int end)
{
    if (start == end)
    {
        tree[p] = nums[start];
        return ;
    }

    int const mid = (start + end) >> 1;
    build(p << 1, start, mid);
    build(p << 1 | 1, mid + 1, end);

    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

void update(int p, int start, int end, int L, int R)
{
    if (start == end)   // 不用lazy标记，直接计算
    {
        tree[p] = sqrt(tree[p]);
        return ;
    }

    if (L <= start && end <= R && tree[p] == end - start + 1)   // 特判，对1开方还为1，直接略过
        return ;

    int const mid = (start + end) >> 1;
    if (L <= mid) update(p << 1, start, mid, L, R);
    if (R > mid) update(p << 1 | 1, mid + 1, end, L, R);

    tree[p] = tree[p << 1] + tree[p << 1 | 1];  // 上报
}

int query(int p, int start, int end, int L, int R)
{
    if (L <= start && end <= R) return tree[p];

    int res = 0;
    int const mid = (start + end) >> 1;
    if (L <= mid) res += query(p << 1, start, mid, L, R);
    if (R > mid) res += query(p << 1 | 1, mid + 1, end, L, R);
    return res;
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    while (cin >> n)
    {
        cout << "Case #" << ++ cases << ":\n";

        for (int i = 1; i <= n; i++) cin >> nums[i];
        build(1, 1, n);

        int m;
        cin >> m;
        int op, l, r;
        while (m--)
        {
            cin >> op >> l >> r;
            if (r < l) swap(l, r);  // 天坑，前面的l可以比r大！！！

            if (op) cout << query(1, 1, n, l, r) << '\n';
            else update(1, 1, n, l, r);
        }

    }
}


// https://acm.hdu.edu.cn/showproblem.php?pid=4027
// 764MS	4600K