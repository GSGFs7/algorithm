#include <bits/stdc++.h>
using namespace std;

/*
 * 树状数组
 * 二分+数组
 * 用类似二分的方式划分一个数组（形状类似二叉树）
 *  每次修改所花费的时间为从底部到根节点的时间，为O(logn)
 * 用一个数组存储，每个位置存储最上面的点，如tree[2]存储的就是a[1]+a[2]，而并非a[2]
 * （只需要求出奇数个的之即可，偶数为上的数不会用到，去掉后刚好压缩为一维数组，使用lowbit操作定位下一个点）
 *
 * 求前缀和
 * 对于一个位置，要求这个点的前缀和，需要将前面所有最上方的数相加，时间复杂度O(logn)
 *  如sum[9]=tree[8]+tree[9]，因为8就是最高点，注意tree[9]为a[9]
 *  对此可得到一个规律，一个数的结果就是将他的每个二进制对应的位置 从右往左递推后 相加
 *  如sum[10]=tree[8]+tree[10]，注意：tree[10]为a[9]+a[10]
 *
 * 使用lowbit可以快速得到最后一个1的位置
 *  x & -x
 *  因为-x是x的反码加一，可以快速定位到一个相同的地方，如：
 *  x=6=00000110,-x=-6=11111010，结果为10，也就是2
 *
 * 修改一个点的数值
 *  将这个点加上这个数后一直向上爬，每到一个点都加上这个数，定位依旧使用lowbit
 * */

const int N = 5e5 + 10;
int n, m;
int tree[N];

inline int lowBit(int k)
{
    return k & (-k);
}

void update(int k, int num)
{
    while (k <= n)
    {
        tree[k] += num;
        k += lowBit(k);
    }
}

int query(int k)
{
    int sum = 0;
    while (k > 0)
    {
        sum += tree[k];
        k -= lowBit(k);
    }
    return sum;
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        update(i + 1, a);
    }

    for (int i = 1; i <= m; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;

        if (op == 1) update(x, y);
        else cout << query(y) - query(x - 1) << '\n';
    }

    return 0;
}


// https://www.luogu.com.cn/problem/P3374