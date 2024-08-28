#include "bits/stdc++.h"

/*
 * 给出一个数组，这个数组是一个边权为0和1的完全二叉树组成，数组中的每个数就是从根节点到对应的最低点的权值之和，求是否存在这样的二叉树
 *  关于权值：对于一个父节点，指向两个子节点的边的权值一定一个是1一个是0
 *
 * 对于这样的二叉树来说，子节点权值为0的数有且只有一个
 * 对于父节点相同的两个叶子节点来说，他们的值一定相差1
 * 删掉这样的数，如果最后删不完就说明了不可能存在这样的二叉树
 * 利用单调栈，记录最近一个比当前这个数小的数，如果这样的数存在，那就表明是前面的数-1的到的
 * 但是后面的数就无法访问，使用一个反方向的单调栈来记录从后面开始的数对
 * */

using namespace std;
#define int long long
using ll = int;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);// 原数组
    vector<ll> sta(n + 1);// 栈
    ll cnt = 0;// 0的个数
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        if (!a[i]) cnt++;
    }
    if (cnt != 1) {// 0必定会且只会出现一次(全都是0的那条路)
        cout << "NO" << '\n';
        return;
    }

    /// 单调栈？
    vector<ll> b(n + 1);// 从前往后的结果
    ll top = 0;
    for (ll i = 1; i <= n; i++) {
        while (top && a[sta[top]] >= a[i]) top--;
        if (top) b[i] = a[sta[top]];// 如果前面有比自己小的数，就设定为那个小的数(如果符合二叉树的规则的话，一般是a[i]-1，不考虑反序)
        else b[i] = -1;// 如果前面没有比自己小的数，就设为-1
//        for (int j = 1; j <= top; j++) cout << sta[j] << ' ';cout << '\n';
        sta[++top] = i;
    }

    // 倒着再来一遍，考虑反序是否符合
    vector<ll> c(n + 1);
    top = 0;
    for (ll i = n; i >= 1; i--) {
        while (top && a[sta[top]] >= a[i]) top--;
        if (top) c[i] = a[sta[top]];
        else c[i] = -1;
//        for (int j = 1; j <= top; j++) cout << sta[j] << ' ';cout << '\n';
        sta[++top] = i;
    }

    /// why?
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
        if (max(b[i], c[i]) != a[i] - 1) ans = 0;// 如果前面的数与后面的数差值不为1，那就代表不存在

    // debug
//    for (int i = 1; i <= n; i++)
//        cout << a[i] << ' ';cout << '\n';
//    for (int i = 1; i <= n; i++)
//        cout << b[i] << ' ';cout << '\n';
//    for (int i = 1; i <= n; i++)
//        cout << c[i] << ' ';cout << '\n';

    if (ans) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1919/problem/D