#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

/*
 * 一个ATM一次最多只能取出x的钱
 * 给出排队人的取款金额，求先取完钱的顺序
 * 简单理解为要取几次，最早的人先出去先根据次数，再根据原顺序
 * 记得减1，因为2/2=1但是已经不需要再取了和1/2=0是一个情况
 * */

const int N = 1e5 + 10;
pair<int, int> a[N];
int cnt = 0;

// 匿名函数 Lambda表达式
int _IO = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.first < y.first;
}

void solve()
{
    cnt ++;
    int n, x;
    cin >> n >> x;
    for (int i = 0, b; i < n; i++)
    {
        cin >> b;
        a[i].first = (b - 1) / x;
        a[i].second = i + 1;
    }

    sort(a, a + n);// 自动先排first再排second？

    cout << "Case #" << cnt << ": ";
    for (int i = 0; i < n; i++) cout << a[i].second << ' ';
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// https://www.acwing.com/problem/content/3324/