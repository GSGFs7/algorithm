#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define int long long

/*
 * 题目描述:
 *  给出n个数, 求是否有一种划分数组的方法, 使得每段数组的MEX(缺失的最小非负整数)相同
 * 输入描述:
 *  第一行一个整数n, 表示数组的长度
 *  第二行n个整数, 表示数组a
 * 输出描述:
 *  如果存在满足条件的划分, 输出任意一种划分方案, 否则输出-1
 *
 * 思路:
 *  先求出数组中每个数的出现次数, 然后从左到右遍历数组, 找到第一个为0的数, 这个数就是整个数组的MEX
 *  可划分出来的子数组的MEX必须相同, 因此所有的MEX一定是等于整个数组的MEX的, 不然就没有划分办法的
 *  证明:说不清,略
 * */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);// 原数组
    vector<int> cnt(n);// 每个数出现的次数
    for (auto& i : a) {
        cin >> i;
        cnt[i] ++;
    }

    int k = 1;// MEX
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {// 遇到的第一个为0的数就是整个数组的MEX
            k = i;
            break;
        }
    }
    // 关于这个得到的MEX值,整个数组的MEX肯定就是各个子数组的MEX值,不然就无法划分出几个相同的MEX
    // 而且找到两个MEX就必定有解,因为整个数组直到cnt为0的地方才是MEX,也就是说不会有正好是MEX+1的数来增加MEX值,可以是除了他之外的任何数
    // 我也不知道怎么解释了,就很神奇

    vector<int> ans;
    map<int, int> mp;
    int p = 0;
    for (int i = 0; i < n; i++) {// 划分为子数组
        if (!mp[a[i]]) {
            mp[a[i]] = 1;
            if (a[i] < k) p ++;
            if (p == k) {// 如果这个数组满足条件,开启下一个数组
                ans.push_back(i);
                mp.clear();
                p = 0;
            }
        }
    }

    if (ans.back() < n) ans.back() = n - 1;// 补个尾巴

    int l = 1;
    if (ans.size() < 2) cout << -1 << '\n';// 如果找不到两个及以上的分组,无解
    else {
        cout << ans.size() << '\n';
        for (auto i : ans) {
            cout << l << ' ' << i + 1 << '\n';
            l = i + 2;
        }
    }
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1935/problem/B