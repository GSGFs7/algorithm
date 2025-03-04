#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个数组 问以某个点为起点向后看中间没有比终点高的点有多少个
 *
 * 想到是单调栈了 但是没有写出来
 * 首先 因为需要选择的区间是中间没有比较高的点的
 * 那么对于一个起点而言 这个起点可以选择的终点都是单调递增的
 * 那么对于这个点就只需要使用一个单调栈维护就可以了
 * 但是 如果需要对每个点都需要维护呢 这样就比较复杂了
 * 题解使用的方法是差分
 * 将一个位置上的下标按照大小的关系进行差分
 * 就可以快速得到这个点为起点的区间有多少个 和 以这个点为终点的区间有多少个
 * 这样就满足的区间的单调性 前面的不可以穿过一个高的位置向后继续传递
 * 喵啊～
 * */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    stack<int> st;
    vector<int> diff(n + 1);    // 差分
    // 从后往前维护一个递增序列
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] < a[i]) {
            diff[i]++;
            diff[st.top()]--;
            st.pop();
        }
        st.push(i);
    }

    // 单调栈里剩下的都是以0为起点的区间了
    while (!st.empty()) {
        diff[0]++;
        diff[st.top()]--;
        st.pop();
    }

    // 统计答案
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += diff[i];
        cout << ans << ' ';
    }
    cout << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://atcoder.jp/contests/abc372/tasks/abc372_d
// 2024-11-05
