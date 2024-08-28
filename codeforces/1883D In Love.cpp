#include <bits/stdc++.h>
using namespace std;

/*
 * 对于一个线段区间，加上或者减去一个子线段后，问是否存在不相交的线段
 *
 * 直接开两个堆，一个维护最大左端点，一个维护最小右端点，如果左端点的位置在右端点的右边，则存在这样一个边
 * （怎么这么简单，比赛的时候怎么就没有想到）
 * */

struct node1
{
    int l, r;
    friend bool operator < (node1 k, node1 z)// 友元函数，在multiset使用时可以用来表示外部两个node1
    {
        return k.l > z.l;
    }
};

struct node2
{
    int l, r;
    friend bool operator < (node2 k, node2 z)
    {
        return k.r < z.r;
    }
};

multiset<node1> a;
multiset<node2> b;

void solve()
{
    int n;
    cin >> n;
    while (n --) {
        int l, r;
        string s;
        cin >> s >> l >> r;

        if (s[0] == '+')    // 插入
        {
            a.insert({l, r});
            b.insert({l, r});
        }
        else                // 删除
        {
            a.erase(a.find({l, r}));
            b.erase(b.find({l, r}));
        }

        // 如果最左边的右端点在最右边的左端点之左（最值向错），就存在
        if (a.begin()->l > b.begin()->r) puts("YES");
        else puts("NO");
    }
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

//    int t;
//    cin >> t;
//    while (t--)
    solve();
    return 0;
}


// https://codeforces.com/problemset/problem/1883/D