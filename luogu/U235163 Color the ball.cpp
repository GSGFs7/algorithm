#include <iostream>
#include <cstring>
using namespace std;

/*
 * 区间修改+单点查询
 * 树状数组结合差分
 * 树状数组用于求前缀和，差分是前缀和的逆操作，得到的每个点都是原始值
 * */

/// 太复杂了，不可用，TLE九个
/*
const int N = 1e5 + 10;
int n;
int tree[N];

int inline lowBit(int x)
{
    return x & (-x);
}

void update(int k, int x)
{
    while (k <= n)
    {
        tree[k] += x;
        k += lowBit(k);
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

    // 时间
    long const start = clock();

    while (scanf("%d", &n) != EOF)
    {
        if (n == 0) break;

        // 别忘了初始化
        memset(&tree, 0, sizeof tree);

        int l, r;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &l, &r);
            update(l, 1);
            update(r + 1, -1);
        }

        for (int i = 1; i <= n; i++)
            cout << query(i) << ' ';
        puts("");
    }

    // 时间
    //cout << clock() - start << "ms" << '\n';

    return 0;
}
 */


/// 简单版本，但是没有树状数组
// 纯粹的差分应用，带上树状数组还要加上log的复杂度
// 因为是最后统一计算结果，所以加不加树状数组都无所谓，因为这个卡了两天，因为一定要树状数组
const int N = 1e5 + 10;
int n;
int a[N];

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    while (scanf("%d", &n) != EOF)
    {
        if (n == 0) break;

        // 初始化
        for (int i = 0; i <= n + 1; i++) a[i] = 0;

        // 差分，时间复杂度O(n)
        int l, r;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &l, &r);
            a[l] ++;
            a[r + 1] --;
        }

        for (int i = 1; i <= n; i++)
        {
            a[i] += a[i - 1];
            printf("%d ", a[i]);
        }
        puts("");
    }
    return 0;
}


// https://www.luogu.com.cn/problem/U235163