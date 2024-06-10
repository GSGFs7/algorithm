#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个只包含括号和问号的字符串, 是否有唯一的方法使问号变成括号使所有的括号闭合

  思路:
    贪心
    找出所有问号的位置, 用两种括号去填充这个位置
    如果填充完了后可以发生交换就表明没有唯一解
*/

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pos;
    int l = n / 2, r = n / 2;    // 剩下的可以填充的左右括号的数量
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') l--;
        if (s[i] == ')') r--;
        if (s[i] == '?') pos.push_back(i);    // 记录问号的下标
    }

    for (int i = 0; i < pos.size(); i++) {
        if (i < l) s[pos[i]] = '(';     // 前面全部填充左括号
        else s[pos[i]] = ')';           // 后面填充右括号
    }

    // 一个用来检测是否合法的函数
    auto check = [&]() {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') cnt++;
            if (s[i] == ')') cnt--;
            if (cnt < 0) return false;
        }
        return true;
    };

    bool flag = true;
    if (l > 0 && r > 0) {    // 是否可以交换
        // 只需要判断一次, 选最后填入的, 如果前面的可以交换, 那么后面一定可以
        swap(s[pos[l - 1]], s[pos[l]]);
        if (check()) flag = false;
    }
    cout << (flag ? "YES\n" : "NO\n");
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
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


// https://codeforces.com/contest/1709/problem/C
// 2024年5月22日