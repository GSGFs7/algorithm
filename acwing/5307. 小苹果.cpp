#include "bits/stdc++.h"

using namespace std;
#define int long long

/*
 * 给出n个苹果，每隔两个拿走一个，求要拿几次才拿完，还有最后一个苹果是再第几次拿的
 * 这个数据量，打表...看不出来...
 *
 * 首先，苹果间的标号没有意义，也就是说拿走几个后的苹果队列与原本就是足够数量的苹果队列没有区别，既然这样
 * 将苹果每3个分为一组，这个组中的第一个苹果是需要拿走的，这样分的话最后可能会出现余数，直接加2补齐
 * 这样的分区数就是一次操作拿走的值了，数学表达就是 (n+2)/3
 * 对于最后一个数，直接对3取模，如果是分组中的第一个数（模为1）就是了
 * */

void solve()
{
    int n;
    cin >> n;
    int res = n;
    int cnt = 0;
    int m = 0;
    while (res)
    {
        cnt ++;
        if (!m && res % 3 == 1) m = cnt;// 第一个能出去的位置
        res -= (res + 2) / 3;
    }
    cout << cnt << ' ' << m;
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/description/5310/