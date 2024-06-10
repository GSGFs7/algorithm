#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 10;
int n, m;
int col[maxn], ans[maxn];    // col记录每个点的颜色
vector<int> G[maxn];
vector<pair<int, int>> ask[maxn];
//................................
// 树状数组
int tr[maxn];
inline int lowbit(int x) { return x & (-x); }

inline void add(int x, int val) {
    while (x < maxn) {
        tr[x] += val;
        x += lowbit(x);
    }
}

inline int sum(int x) {
    int res = 0;
    while (x) {
        res += tr[x];
        x -= lowbit(x);
    }
    return res;
}

//................................
int siz[maxn], son[maxn];
void find_son(int u, int fa) {
    siz[u] = 1;
    son[u] = 0;
    for (auto it : G[u]) {
        if (it == fa) continue;
        find_son(it, u);
        siz[u] = siz[u] + siz[it];
        if (siz[son[u]] < siz[it]) son[u] = it;
    }
}

int flag;
int cnt[maxn], Sum;    // cnt记录每个颜色出现的次数，Sum记录有多少个点插入了树状数组
unordered_map<int, int> po;
int num[maxn], idx;

void Count(int u, int fa) {
    num[idx++] = col[u];

    if (po.count(cnt[col[u]])) {
        if (--po[cnt[col[u]]] == 0) po.erase(cnt[col[u]]);
    }

    if (cnt[col[u]]) add(cnt[col[u]], -1), Sum--;
    add(++cnt[col[u]], 1), Sum++;

    if (po.count(cnt[col[u]]))
        po[cnt[col[u]]]++;
    else
        po[cnt[col[u]]] = 1;


    for (auto it : G[u]) {
        if (it == fa || it == flag) continue;
        Count(it, u);
    }
}

void dsu(int u, int fa, int keep) {

    for (auto it : G[u]) {
        if (it == fa || it == son[u]) continue;
        dsu(it, u, 0);
    }

    if (son[u]) {
        dsu(son[u], u, 1);
        flag = son[u];
    }

    Count(u, fa);

    for (auto it : ask[u]) ans[it.second] = Sum - sum(it.first - 1);
    flag = 0;

    if (!keep) {
        for (auto it : po) add(it.first, -it.second);    // 清空树状数组
        for (int i = 0; i < idx; ++i) cnt[num[i]] = 0;    // 清空记录颜色个数的数组
        idx = 0;
        Sum = 0;
        po.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //...................
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> col[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < m; i++) {
        int u, k;
        cin >> u >> k;
        ask[u].push_back({k, i});    // 记录询问
    }

    find_son(1, 0);
    dsu(1, 0, 1);

    for (int i = 0; i < m; ++i) cout << ans[i] << "\n";
    return 0;
}
