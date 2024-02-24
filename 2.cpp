#include <bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_cxx;

/// 莫队
/*
 * 给出一个数组，求一个区间中有多大的概率取出两个相同数的概率
 *
 *
 * */

const int N = 5e4 + 10;
int n, m;
int maxn;
int c[N];
int ans1[N], ans2[N];
int cnt[N];
int sum = 0;

struct Node
{
    int l, r, id;

    bool operator < (const Node x)// 重载<运算符
    {
        if (l / maxn != x.l / maxn) return l < x.l;// l优先
        return (l / maxn) & 1 ? r < x.r : r > x.r;
    }
} a[N];

void add(int i)
{
    sum += cnt[i];
    cnt[i] ++;
}

void del(int i)
{
    cnt[i] --;
    sum -= cnt[i];
}

void solve()
{
    cin >> n >> m;
    maxn = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 0; i < m; i++) cin >> a[i].l >> a[i].r, a[i].id = i;

    sort(a, a + m);// l优先的排序
//    for (int i = 0; i < m; i++) cout << a[i].l << ' ' << a[i].r << '\n';

    // 预处理，离线算法，不可后续更新
    for (int i = 0, l = 1, r = 0; i < m; i++)
    {
        if (a[i].l == a[i].r)// 如果区间中只有一个数
        {
            ans1[a[i].id] = 0;
            ans2[a[i].id] = 1;
            continue;
        }

        while (l > a[i].l) add(c[-- l]);
        while (r < a[i].r) add(c[++ r]);
        while (l < a[i].l) del(c[l ++]);
        while (r > a[i].r) del(c[r --]);

        ans1[a[i].id] = sum;
        ans2[a[i].id] = (r - l + 1) * (r - l) / 2;
    }

    for (int i = 0; i < m; i++)
    {
        if (ans1[i] != 0)
        {
            int g = gcd(ans1[i], ans2[i]);
            ans1[i] /= g, ans2[i] /= g;
        }
        else ans2[i] = 1;

        cout << ans1[i] << '/' << ans2[i] << '\n';
    }
}

signed main(){
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
        solve();
    return 0;
}