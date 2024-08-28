#include <iostream>
#include <vector>

using namespace std;

/*
  给出a和b两个数组, 表示距离和时间, 两数组间的速度不变,
  求一辆直线行驶的车在x分钟时的位置

  思路:
    小学数学, 注意复杂度(需要二分)和精度即可
    计算公式距离x=v*t
    已知时间求x, 直接根据公式填入值即可
    已知前后两点的距离和时间可以得到中间这段的速度 (a[p]-a[p-1])/(b[p]-b[p-1])
    时间则可以通过减去b[p-1]得到
    最后联立求解
    (两层除法精度可能会出现问题, 需要把一个翻转成乘法)
*/

#define int long long

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; i++) cin >> a[i];    // 距离
    for (int i = 1; i <= k; i++) cin >> b[i];    // 时间

    while (q--) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << 0 << ' ';
            continue;
        }
        
        // 二分快速找到对应的区域
        int p = lower_bound(a.begin(), a.end(), x) - a.begin();
        int ans = (x - a[p - 1]) * (b[p] - b[p - 1]) / (a[p] - a[p - 1]) + b[p - 1];
        // (x - a[p - 1]) / ((a[p] - a[p - 1]) / (b[p] - b[p - 1])) 这样写除法多,
        // 精度损失严重
        cout << ans << ' ';
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


// https://codeforces.com/contest/1971/problem/E
// 二分还花了124ms