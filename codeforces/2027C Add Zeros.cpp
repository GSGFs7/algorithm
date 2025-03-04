#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个数组 可以选择一个 a[i]==len(a)+1-i 的位置在数组后面加上 i-1 个0
 * 问最大的数组长度
 *
 * 因为能够符合 a[i]==len(a)+1-i 的位置最多只能使用一次
 * 也就是说 len(a)+=i-1 后这个点就用不到了 需要另外找其他的点
 * 那么也就是说需要在数组中找到其他的点来接力 看接力能抵达的最大长度
 * 因为len(a)是一个一直在变化的量 不方便计算 重新写一下式子
 * a[i]=len(a)+1-i 可以写成 len(a)=a[i]+i-1 也就是a[i]加上从0开始的下标
 * 只要前面有方法能够得到 a[i]+i （下标从0开始的情况下）
 * 那么就可以 继续往后走 i-1 因为从0开始 所以直接也就是 i
 * 综上 只需要按照 a[i]+i -> a[i]+i+i 的方式建边
 * 从len(a)这个点开始搜索看最大的长度就可以了
 *
 * 题解的想法是对a[i]加上下标得到len[a]但是我一直想着减去
 * 如果可以的话 出应该还是能出的 但是很麻烦了
 * 喵啊～
 * 💭💡🎈
 * */

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 如果选这个点 这个点就可以继续向后选 +i 的点
    map<int, vector<int>> mp;
    for (int i = 1; i < n; i++) {
        mp[a[i] + i].push_back(a[i] + i + i);
    }

    int ans = 0;
    map<int, bool> vis;
    function<void(int)> dfs = [&](int u) {
        if (vis[u]) return;

        ans = max(ans, u);
        vis[u] = true;
        for (auto v : mp[u]) dfs(v);
    };
    dfs(n);

    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://codeforces.com/contest/2027/problem/C
// 2024-10-27
