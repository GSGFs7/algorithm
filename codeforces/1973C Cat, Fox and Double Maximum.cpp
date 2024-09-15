#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
  给出一个1~n的排列a, 给出一个排列b,
  使a[i-1]+b[i-1]<a[i]+b[i]>a[i+1]+b[i+1]的数量最多

  思路:
    很明显, 如果存在这样的凸形数组, 那么最大的数量一定是 n/2-1
    因为起点和终点数量不够, 并且这个凸形都处于奇数位置 (理想情况)
    如果构造不出来这个位置的值(比如说1), 就构造下一个位置的值
    想要构造出这样的数组, 就必须尽量使每个数的值尽可能平均
    尽量少的影响下一个凸形排列
    直接按照a来构造一个值为 n+1-a 的排列b
    从前往后遍历整个数组b, 使遍历到的数的值变成凸的中间那个数
    因为已经在生成b数组的时候平均过了a+b的值, 只需要使b换成一个大于自己的数即可
*/

typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);    // 原数组
    vector<int> b(n + 1);    // n+1-a后的数组, 对应每个数的相反的那个数
    set<pii> st;             // 这个位置的值和位置的下标
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = n + 1 - a[i];     // 需要加1, 因为排列是从1开始的
        st.insert({b[i], i});    // 存入数据池中备用
    }

    // 构造出相连的凸形
    for (int i = 2; i <= n; i++) {
        if (!st.empty()) {
            auto now = st.upper_bound({b[i] + 1, 0});    // 找到一个大于b[i]的值
            if (now == st.end()) continue;               // 如果找不到

            auto [x, y] = *now;
            // 和找到的那个数交换位置
            st.erase(now), st.erase({b[i], i});
            b[y] = b[i], b[i] = x;
            st.insert({b[y], y});    // 后面的哪个数更新了
            i++;    // 已经被这里的凸占用了, 跳过下一个数
        }
    }

    for (int i = 1; i <= n; i++) cout << b[i] << ' ';
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


// https://codeforces.com/contest/1973/problem/C
// 2024年5月19日