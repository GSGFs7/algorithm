#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
#define int long long

/*
 * 给出n个整数, 求有多少个连续的区间能够满足区间和是k的整数倍
 *
 * 思路:
 *  一眼前缀和, but需要特殊优化, n和k是1e5级, 一般普通前缀和的复杂度为O(n^2)
 *  原式 (sum[r]-sum[l-1])%k==0 把sum[l-1]移动到右边
 *  得到 sum[r]%k==sum[l-1]%k
 *  这原本的枚举头尾就变成了O(n)的查重, 只需要看相同的值中可以组出多少对, 有∑cnt[sum[i]]!个, 别忘了sum[0]原本就是结果(对k取模为0)
 * */

void solve() {
    int n, k;
    cin >> n >> k;;
    vector<int> a(n);       // 原数组
    vector<int> sum(n + 1); // 前缀和
    vector<int> cnt(k);     // 出现次数

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = (sum[i] + a[i]) % k;   // 前缀和取模
        ans += cnt[sum[i + 1]];             // 记录次数，排列
        cnt[sum[i + 1]] ++;                 // 出现次数
    }
    cout << ans + cnt[0] << '\n';// cnt[0]表示的就是sum%k==0那部分
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
//    cout << duration.count();
    return 0;
}


// https://www.acwing.com/problem/content/description/1232/