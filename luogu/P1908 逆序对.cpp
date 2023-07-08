#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 原理：
 *  先求出每个点对应的大小顺序
 *  通过这个顺序更新树状数组中相关的每个点(加1)
 *  这样所有小的数都放在后面 （大的数在前面）
 *  要查询逆序和就相当于查询每个点在树状数组中对应的前缀和
 *  通过lowBit快速查询
 * */

const int N = 5e5 + 10;
int a[N], b[N], c[N];// a原数组，b原数组的大小顺序，c树状数组
int n;

/// 利用sort将b按a的大小排序，b存储a中的大小次序
bool cmp(int x, int y)// TODO ？
{
    if (a[x] == a[y]) return x > y;// 避免元素相同
    return a[x] > a[y];
}

// lowBit跳到下一个或上一个节点
int lowBit(int x)
{
    return x & -x;
}

// 更新包含这个数的每个节点，每加入一个数就上一个标记
void update(int x)
{
    while (x <= n)
    {
        c[x] ++;// 上标记，+1就表示有一个数
        x += lowBit(x);
    }
}

// 查询1~x的前缀和，统计标记点
int query(int x)
{
    int res = 0;
    while (x >= 1)
    {
        res += c[x];
        x -= lowBit(x);
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = i;

    sort(b + 1, b + n + 1, cmp);

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        update(b[i]);
        ans += query(b[i] - 1);// 不包括自己
    }
    cout << ans << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1908