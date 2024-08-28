#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 区间修改+区间查询
 * 使用二维树状数组
 * */

const int N = 1e5 + 10;
int n, m;
int tree1[N], tree2[N];

inline int lowBit(int x)
{
    return (-x) & x;
}

void update1(int k, int x)
{
    while (k <= n)
    {
        tree1[k] += x;
        k += lowBit(k);
    }
}

void update2(int k, int x)
{
    while (k <= n)
    {
        tree2[k] += x;
        k += lowBit(k);
    }
}

int sum1(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += tree1[x];
        x -= lowBit(x);
    }
    return ans;
}

int sum2(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += tree2[x];
        x -= lowBit(x);
    }
    return ans;
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n >> m;
    int a, last = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        update1(i, a - last);
        update2(i, (i - 1) * (a - last));
        last = a;
    }

    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            update1(l, x);
            update1(r + 1, -x);
            update2(l, (l - 1) * x);
            update2(r + 1, r * (-x));
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << r * sum1(r) - sum2(r) - (l - 1) * sum1(l - 1) + sum2(l - 1) << '\n';
        }
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P3372
// 解法来自算法竞赛


/// 线段数解法
/*
#include <bits/stdc++.h>
#define int long long
using namespace std;

*
 * 线段树问题
 * 1.用于求区间最大值
 * 2.用于求区间和问题
 * 时间复杂度O(mlogn)
 * 线段树：分治思想+二叉树+Lazy-Tag技术
 *
 * 是一颗二叉树，树上的每一个节点都是“线段”（区间）
 * 区间的值可以是区间和，最值或者是其他的题目灵活定义的值
 * 结合分治思想可知，大区间的解可以从小区间的解合并而来
 *
 * 注意：需要开4N的数组，因为最后一排可能浪费（2N）
 *
 * 区间和的核心技术：Lazy-Tag
 *  区间修改+区间查询
 * 利用线段树的特征，定义一个数组，统一记录区间的修改，而不是一个个修改单个的元素，
 * 只有当线段树的一致性被破坏时才把变化值传递给下一层
 * update()函数：
 *  依次向下递归，寻找能够完全覆盖的区间，打上记号，更新并返回这个点的值，向上传递，下面的值暂时不管
 * push_down()函数：
 *  如果当前的更新操作更之前的标记发生冲突，用这个函数来清空标记（一层一层还原真实值）
 * *

const int N = 1e5 + 10;
int nums[N];        // 记录数列中的元素
int tree[N << 2];   // tree[i]表示第i个节点的值，左移两位也表示乘4
int lazy[N << 2];   // lazy[i]表示第i个节点的Lazy-Tag，统一记录区间的修改

/// 左右儿子
inline int ls(int p) { return p << 1; }     // 定位左儿子
inline int rs(int p) { return p << 1 | 1; } // 定位右儿子 或1也表示加1，因为左移后最后一位是0

/// 从下向上传递值
inline void pushUp(int p)
{
    tree[p] = tree[ls(p)] + tree[rs(p)];        // 求区间和
    // tree[p] = min(tree[ls(p)], tree[rs(p)]); // 最小值
}

/// 建树
void build(int p, int pl, int pr)   // pl和pr分别表示当前状态的最左点和最右点
{
    lazy[p] = 0;    // 初始化，貌似没用
    if (pl == pr)   // 如果已经找到了最底层
    {
        tree[p] = nums[pl]; // 赋值
        return ;
    }

    int const mid = (pl + pr) >> 1;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    pushUp(p);
}

/// 打上Lazy-Tag标记并更新
void addTag(int p, int pl, int pr, int d)
{
    lazy[p] += d;
    tree[p] += d * (pr - pl + 1);
}

/// 发生冲突时把标记传递给子树
void pushDown(int p, int pl, int pr)
{
    if (lazy[p])
    {
        int const mid = (pl + pr) >> 1;
        addTag(ls(p), pl, mid, lazy[p]);    // 传递给左儿子
        addTag(rs(p), mid + 1, pr, lazy[p]);// 传递给右儿子
        lazy[p] = 0;
    }
}

/// 区间修改
void update(int L, int R, int p, int pl, int pr, int d)
{
    if (L <= pl && pr <= R) // 如果当前线段被待修改区间完全覆盖，直接更新
    {
        addTag(p, pl, pr, d);
        return ;
    }

    pushDown(p, pl, pr);    // 如果不能完全覆盖，下一层可能会被使用，用lazy标记还原下一层

    int const mid = (pl + pr) >> 1;
    if (L <= mid) update(L, R, ls(p), pl, mid, d);  // 如果左边没有被完全覆盖
    if (R > mid) update(L, R, rs(p), mid + 1, pr, d);
    pushUp(p);  // 更新当前节点
}

/// 查询区间[L,R]
int query(int L, int R, int p, int pl, int pr)
{
    if (pl >= L && pr <= R) return tree[p]; // 如果完全覆盖

    pushDown(p, pl, pr);    // 如果没有完全覆盖，更新下一层

    int res = 0;
    int const mid = (pl + pr) >> 1;
    if (L <= mid) res += query(L, R, ls(p), pl, mid);
    if (R > mid) res += query(L, R, rs(p), mid + 1, pr);
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

    while (m--)
    {
        int p, L, R, d;
        cin >> p;
        if (p == 1)
        {
            cin >> L >> R >> d;
            update(L, R, 1, 1, n, d);
        }
        else
        {
            cin >> L >> R;
            cout << query(L, R, 1, 1, n) << '\n';
        }
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P3372*/