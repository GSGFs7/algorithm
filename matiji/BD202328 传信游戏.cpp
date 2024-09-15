#include <iostream>
#include <vector>

using namespace std;

/*
  n个人相互传信, 0表示自己收下, 求没有循环传递的人的编号的异或值

  按照题目的要求正着一个一个找太麻烦了
  直接从0开始反向建边, 0抵达不了的点就表明是循环中的点
  很容易证明, 如果一群人成环的话, 是不会有多出来的一条边接向0
*/

const int N = 1010;
vector<int> a[N + 1];
int ans = 0;

// 暴搜
void dfs(int u) {
    for (auto v : a[u]) {
        ans ^= v;
        dfs(v);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x].push_back(i);    // 反向建边
    }

    dfs(0);

    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
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


// https://www.matiji.net/exam/brushquestion/28/4347/179CE77A7B772D15A8C00DD8198AAC74
// 日期