#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
// #define int long long

typedef pair<int, int> pii;
const int N = 20;
bool vis[N][N];    // 是否放下了瓷砖
int s[N];
bool flag = false;    // 是否找到了可行方案
vector<pii> a;
int n, h, w;

void debug() {
#ifdef __LOCAL__
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << vis[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
#endif
}

bool cmp(pii _a, pii _b) {
    return _a.first * _a.second > _b.first * _b.second;
}

// 是否能够放下这块砖
bool check(int x, int y, int _a, int _b) {
    if (_a + x > h) return false;    // 如果越界
    if (_b + y > w) return false;

    for (int i = x; i < x + _a; i++) {
        for (int j = y; j < y + _b; j++) {
            if (vis[i][j]) return false;
        }
    }
    return true;
}

void draw(int x, int y, int _a, int _b) {
    for (int i = x; i < x + _a; i++) {
        for (int j = y; j < y + _b; j++) {
            vis[i][j] = true;
        }
    }
}

void undraw(int x, int y, int _a, int _b) {
    for (int i = x; i < x + _a; i++) {
        for (int j = y; j < y + _b; j++) {
            vis[i][j] = false;
        }
    }
}
bool isSuccess() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!vis[i][j]) return false;
        }
    }
    return true;
}

void dfs(int cur, int sum) {
    if (flag == true) return;
    if (cur == n) return;
    if (sum + s[cur] < h * w) return;    // 剪枝

    if (isSuccess()) {
        flag = true;
        debug();
        return;
    }

    debug();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (vis[i][j]) continue;

            if (check(i, j, a[cur].first, a[cur].second)) {    // 正着
                draw(i, j, a[cur].first, a[cur].second);
                dfs(cur + 1, sum + a[cur].first * a[cur].second);
                undraw(i, j, a[cur].first, a[cur].second);
            }
            if (a[cur].first == a[cur].second) continue;       // 如果一样就没有必要了
            if (check(i, j, a[cur].second, a[cur].first)) {    // 横着
                draw(i, j, a[cur].second, a[cur].first);
                dfs(cur + 1, sum + a[cur].second * a[cur].first);
                undraw(i, j, a[cur].second, a[cur].first);
            }
        }
    }
}

void solve() {
    cin >> n >> h >> w;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), cmp);
    // for (auto &i : a) cout << i.first << '\t' << i.second << '\n';
    for (int i = a.size() - 1; i >= 0; i--) {
        s[i] = s[i + 1] + a[i].first * a[i].second;
    }

    // 如果全加上都不够直接返回
    if (s[0] < h * w) return cout << "No\n", void();

    for (int i = 0; i < n; i++) {
        if (s[i] < h * w) break;
        dfs(i, 0);
    }

    if (flag)
        cout << "Yes\n";
    else
        cout << "No\n";
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto start = chrono::system_clock::now();

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count();
    return 0;
}



// https://atcoder.jp/contests/abc345/tasks/abc345_d
// 未完成