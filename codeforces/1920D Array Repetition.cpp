#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出n个操作和m次查询，操作 1.添加一个数到数组末尾 2.添加数组的x份备份到末尾
  求数组中第k个数是多少

  这题的数据范围非常大，不可能进行模拟
  可以只存到某个位置上的时候的各种信息，比如说数组在这个位置的长度，重复次数等
  以一个循环节为一个分界点，存储长度，重复次数，这次数组后面多出来的数
  查询的时候就通过对比这个长度来计算是否在这段内
  （说着简单，实现其实很麻烦）
*/

#define int long long

struct Node {
    int sz;           // 当前大小
    int c;            // 这段重复了c份
    vector<int> p;    // 这段新增的数
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Node> a(1);
    for (int i = 0; i < n; i++) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            a.back().p.push_back(x);
        } else {
            int sz = a.back().sz * a.back().c + a.back().p.size();
            if (sz < (int)1e18) a.push_back({sz, min(x + 1ll, ((int)1e18 + sz - 1) / sz)});
        }
    }

    while (m--) {
        int x;
        cin >> x;
        for (int i = a.size() - 1; i >= 0; i--) {
            int sz = a[i].sz * a[i].c;
            if (x > sz) {
                cout << a[i].p[x - sz - 1] << ' ';
                break;
            } else {
                x = (x - 1) % a[i].sz + 1;
            }
        }
    }
    cout << '\n';
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


// https://codeforces.com/contest/1920/problem/D
// 2024-09-16