#include "bits/stdc++.h"
#define int long long
using namespace std;

/*
 * 给出一个数组，和两个队列，依次将数组中的数放入队列中，求 a[i]<a[i+1] 最小的次数
 * 贪心，两个队尾能尽量减少小的就减少小的，如果小的队列塞不下新的数了再往大的里面塞，都赛不了就更新小的（单次价值最大化）
 * 
 * 为什么这么简单都没有想到！！！
 * */

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int back1 = 1e9;// 较大值
    int back2 = 1e9;// 较小值
    int ans = 0;
    for (auto i : a)
    {
        cin >> i;
        if (back1 < back2) swap(back1, back2);// 固定大小
        if (i <= back2)// 如果小的就可以处理
        {
            back2 = i;
            continue;
        }
        if (i <= back1)// 如果需要大的才可以处理
        {
            back1 = i;
            continue;
        }

        // 如果都处理不了，就尽量拉小的（单次收益最大化）
        back2 = i;
        ans ++;
    }
    cout << ans << '\n';
}

/// multiset的解法
void solve1()
{
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> s;
    int ans = 0;

    for (auto i : a)
    {
        if (s.empty())
        {
            s.insert(i);
            continue;
        }

        auto it = s.lower_bound(i);// 找到一个大于a[i]的最小值
        if (it != s.end()) s.erase(it);// 如果找到了一个大于a[i]的数，这个数就会被a[i]覆盖
        s.insert(i);
        if (s.size() > 2)// 如果有3个数就表明有个大数插进来了，前面没有能替代它的数（set去重，重复的数不会算进来）
        {
            ans ++;
            s.erase(s.begin());// 覆盖掉较小的数
        }
    }
    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1919/problem/C