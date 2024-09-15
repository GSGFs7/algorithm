#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;

void solve()
{

}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {// 放solve函数里过不了？第六个点一直是0，但是单独拿出来就是1（标准答案就是1）
        int n;
        cin >> n;

        int ans = INF;
        vector<int> a(n * 2);
        for (int i = 0; i < n; i++) cin >> a[i], a[i + n] = a[i];// 假循环

        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < 2 * n && a[j] <= a[j + 1]) j++;// 一直向后找
            for (int k = i; k <= j && k < n; k++) {// 以i为起点，j为终点在中间找符合长度的数求解
                int const len = j - k + 1;
                if (len >= n) {
                    ans = min(ans, (n - k) % n);// 直接把后面的数移到前面
                    // 在5123451234中，i=1，j=5，k=1，需要将后四位数加到前面来，操作数为4
                    // 需要操作k后面的数，一共n-k个
                    ans = min(ans, k + 2);// 先翻转，再移位，然后再翻转回来
                    // 在5123451234中，整体翻转，5加到前面，再翻转回来，操作数为3
                    // 需要操作k前面的数，一共k个
                }
            }
            i = j;// 跳跃，只要看一段连续的数就可以了
        }

        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < 2 * n && a[j] >= a[j + 1]) j++;
            for (int k = i; k <= j && k <= n; k++) {
                int const len = j - k + 1;
                if (len >= n) {
                    ans = min(ans, (n - k) % n + 1);// 直接移位，然后翻转
                    // 需要移动k后面的数
                    ans = min(ans, k + 1);// 先翻转然后移位
                    // 需要移动k前面的数
                }
            }
            i = j;
        }

        if (ans != INF) cout << ans << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}


// https://codeforces.com/contest/1907/problem/F