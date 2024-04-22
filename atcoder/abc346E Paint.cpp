#include <chrono>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

void solve();

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
    while (t--) solve();

    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count();
    return 0;
}

/*****************************************************************************/

/*
  给出一个矩阵, 可以为其中一行或一列染色, 求最后剩下的颜色及对应的数量

  思路:
    因为前面的颜色会被后面的颜色覆盖, 直接从后面开始向前推
    如果已经确定了一行后那么这行就不会允许其他的颜色, 对应的与这行存在交叉的列也就会减少1
    也就是说每确定一行, 列的有效范围就会减一, 反之亦然
    所有用过的减去没有用的就是0的个数了, 0可能会有值, 需要清零
*/

// #define int long long
typedef long long ll;
const int N = 2e5 + 10;

void debug() {
#ifdef __LOCAL__
#endif
}

/**
 * @brief 代码写这里!!!
 */
void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<array<int, 3>> k(n);
    for (auto &[t, a, x] : k) cin >> t >> a >> x, a--;

    reverse(k.begin(), k.end());    // 翻转整个数组, 从后面开始处理
    vector<ll> cnt(N, 0);           // 统计存在的个数
    vector<bool> row(h, false);     // 这行是否使用过
    vector<bool> col(w, false);     // 这列是否使用过
    int rowCnt = h, colCnt = w;     // 初始值
    for (auto &[t, a, x] : k) {
        if (t == 1) {
            if (row[a]) continue;    // 如果这行被后面的数覆盖了前面就都没用了

            row[a] = true;
            rowCnt--;            // 被占据的行数加一, 处理列的时侯就会少一个
            cnt[x] += colCnt;    // 加上没有被占据的
        } else {                 // 列同理
            if (col[a]) continue;

            col[a] = true;
            colCnt--;
            cnt[x] += rowCnt;
        }
    }

    cnt[0] = 0;    // 别忘了后面可能还会添加0
    cnt[0] = 1LL * h * w - accumulate(cnt.begin(), cnt.end(), 0LL);
    // accumulate求范围内的和

    vector<pair<int, ll>> ans;
    for (int i = 0; i < N; i++) {
        if (cnt[i]) ans.push_back({i, cnt[i]});
    }
    cout << ans.size() << '\n';
    for (auto [i, c] : ans) {
        cout << i << ' ' << c << '\n';
    }
}


// https://atcoder.jp/contests/abc346/tasks/abc346_e
// 2024年3月27日