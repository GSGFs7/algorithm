#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define int long long

/*
 * 题目描述:
 *  给出n个信息,每条信息都有a,b两个属性,看完n条信息需要的时间是∑ai+∑|bi-b(i-1)|,求在L的时间内最多能看多少条信息
 * 输入:
 *  第一行两个整数n,L
 *  后n行每行两个整数a,b
 * 输出:
 *  最多能看多少条信息
 *
 * 思路:
 *  贪心
 *  因为可以发现这样一个规律,a是无论如何都无法减小的,而b则始终是最大的b减去最小的b,因此想要节省时间只能对b下手
 *  可以发现,如果b相同,那么花费的时间就只有这些a相加
 *  可以先按照b从小到大排序,如果b相同,按照a从小到大排序
 *  取其中的一个区间,这个区间中所有的信息花费的时间一定是 ∑a+b[r]-b[l]
 *  从上面的式子可以看出来在这个区间中取值时就只与a有关了,成功的省略掉了b这个变量
 *  很明显,大多数情况向都无法取到所有的值,这个时候就需要舍弃一些值,优先舍弃大的值可以让更多较小的值加入
 *  可以使用优先队列来维护这段区间中自己要取的值
 *
 * 小声):
 *  当时也想到了区间取值来固定b这个方法,but一直没想通要怎么取值,其实只需要一个堆就能解决了,我却一直想着排序...O(n^3logn)怎么都写不出来
 * */

typedef pair<int, int> pii;

void solve() {
    int n, L;
    cin >> n >> L;
    vector<pii> a(n);
    for (auto& i : a) cin >> i.second >> i.first;

    sort(a.begin(), a.end());

    int ans = 0;
    for (int l = 0; l < n; l++) { // 区间左端点
        int res = 0;// 总时间
        priority_queue<int> pq;
        for (int r = l; r < n; r++) { // 区间右端点
            pq.push(a[r].second);// 入堆
            res += a[r].second;// 加上这个点的a

            while (!pq.empty() && a[r].first - a[l].first + res > L) { // 如果溢出就减去最大的那个a
                res -= pq.top();
                pq.pop();
            }

            ans = max(ans, (int)pq.size());// 取最大的那个为结果
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
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1935/problem/C