#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define int long long

const int N = 110;
vector<string> s[N];
int f[N];

/*
 给出一个字符串T，和n个背包，每个背包有一定数量的字符串，求如果需要用背包里的字符串组成T需要多少个

 思路:
    分组背包板子
    分组里面套01背包
    从后往前匹配子序列, 如果匹配成功再判断是否是从头开始
    如果不是就表明需要有个字符串补齐前面那部分, 当前字符串前面必须有个能从头一直接过来的字符串
    也就是前面的f[j-k.size()]必须大于等于1
*/ 

void solve() {
    string T;
    int n;
    cin >> T >> n;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        while (m --) {
            string temp;
            cin >> temp;
            s[i].push_back(temp);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = T.size(); j >= 0; j--) {
            for (auto k: s[i]) {
                if (k.size() <= j + 1) {// 长度不会越界
                    if (k == T.substr(j + 1 - k.size(), k.size())) {// 字符串匹配
                        if (j + 1 == k.size()) { // 如果是从头开始
                            f[j] = 1;
                        } else if (f[j - k.size()]) {
                            if (f[j]) f[j] = min(f[j - k.size()] + 1, f[j]);
                            else f[j] = f[j - k.size()] + 1;
                            // cout << k << '\n';
                        }
                    }
                }
            }
        }
        // for (int j = 0; j < T.size(); j++) {
        //     cout << f[j] << ' ';
        // }cout << '\n';
    }

    if (f[T.size() - 1]) cout << f[T.size() - 1] << '\n';
    else cout << -1 << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://atcoder.jp/contests/abc344/tasks/abc344_d