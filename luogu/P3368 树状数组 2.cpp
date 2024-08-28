#include <bits/stdc++.h>
using namespace std;

/*
 * 树状数组+差分
 * 将原数组转化为差分的形式
 * 即粗存前后两点的差值
 * 可以快速统计整个区间的值
 * */

const int N = 5e5 + 10;
int n, m;
int tree[N];

// lowBit定位下一个数
inline int lowBit(int k)
{
    return k & (-k);
}

// 更新某个点
void update(int k, int num)
{
    while (k <= n)
    {
        tree[k] += num;
        k += lowBit(k);
    }
}

// 统计前缀和
long long query(int k)
{
    long long sum = 0;
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
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        int now;
        cin >> now;
        update(i + 1, now - last);// 存储差分
        last = now;// 存储上一个值，用于计算差分
    }

    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;

            update(x, k);       // 前面的正标记
            update(y + 1, -k);  // 后面的负标记
        }
        else
        {
            int x;
            cin >> x;

            cout << query(x) << '\n';
        }
    }

    return 0;
}


// https://www.luogu.com.cn/problem/P3368