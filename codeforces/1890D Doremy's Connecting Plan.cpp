#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 求按照什么顺序排列一个数组，使 ∑ak>=i*j*c 始终成立(c为题目给出的常数)
 * 例如下面这组数据:
 * 5 1
 * 0 1 0 4 199
 * [1,5]:   199>=1*5*1    (然后随便什么顺序都可以完成了)
 * [1,2]:   200>=1*2*1
 * [1,3]:   200>=1*3*1
 * [1,4]:   204>=1*4*1
 *
 * 贪心
 * 使 i*j*c 最小, c 是常数,也就是使 i*j 最小,因为 j 要遍历每个值
 * 所以当所有的数都选择起点为1时 i*j*c 的值最小,
 * 那么上式可化简为 sum+a[i]>=1*j*c
 * 只需要先加入所有 j*c-a[i] 比较小的数,不断更新sum,如果遇到了一个最小的数都不能加入的情况就表明无解
 * */

typedef pair<int, int> PII;
const int N = 2e5 + 10;
int a[N];// 原数组

bool cmp(PII x, PII y)
{
    return x.first < y.first;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<PII> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i != 1) v.emplace_back(m * i - a[i], i);// 加入 1*j*c-a[i] 并排序
    }

    sort(v.begin(), v.end(), cmp);// 从小到大

    int sum = a[1];// 1号点为连接起点,带有初始值a[1]
    for (auto i : v)
    {
        if (sum < i.first)// 如果超过题目要求的限制,直接输出NO
        {
            puts("No");
            return ;
        }
        sum += a[i.second];// 更新,计算后面大的数
    }
    puts("Yes");
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t --)
        solve();
    return 0;
}


// https://codeforces.com/contest/1890/problem/D