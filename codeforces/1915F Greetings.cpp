#include <bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_cxx;

/*
 * 给出一个数轴和数轴上每个人的起点和终点，所有人速度一致，所有人会相遇多少次
 *
 * 因为所有人是速度相同的运动时保持相对静止，只有大区间完全包含小区间的时候才会相遇
 * 因为每个人的状态是动态变化的，单纯的记录终点会导致并非完全包含的区间被计入，需要进行特殊的处理
 * 因为题目的数据达到了 10^5，O(n^2)的复杂度过不了
 * 可以使用树状数组 O(logn) 的复杂度统计一个区间中的值
 * 树状数组中的值表示当前有多少个区间，如果一个小的区间被除外，它和所有的大区间都会相遇一次，并且给每个区间按先后顺序编号，避免右边界出现问题
 * 说人话就是，反过来，不看包含多少区间，看被多少个区间包含
 * */
// 妙啊！树状数组还能这么用

const int N = 2e5 + 10;
int tr[N], to[N];

void update(int p, int x)
{
    while (p < N)
    {
        tr[p] += x;
        p += p & (-p);
    }
}

int query(int p)
{
    int res = 0;
    while (p > 0)
    {
        res += tr[p];
        p -= p & (-p);
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> arr;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tr[i] = to[i] = 0;
        arr.push_back({a, i, 1});// 1表示起点
        arr.push_back({b, i, 2});// 2表示终点
    }

    sort(arr.begin(), arr.end());// 从小到大排列数轴上的所有点

    int idx = 0, ans = 0;
    for (auto it : arr)// 从小到大遍历数轴上的所有点
    {
        if (it[2] == 1)// 如果是起点
        {
            to[it[1]] = ++ idx;// idx表示当前有多少个起点（因为起点大于终点，也就是说前面有多少个区间）
            update(idx, 1);
        }
        else// 如果是终点
        {
            int id = to[it[1]];
            update(id, -1);// 变成-1去掉这个点，这个区间已经结束了，现存的区间-1
            ans += query(id);// 加上把这个点完全包含的区间个数
        }
    }
    cout << ans << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1915/problem/F