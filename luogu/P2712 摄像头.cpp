#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 510;
int d[N];   // 入度
bool st[N]; // 是否是存在的点

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v[N];   // 这个点点监视着哪些点
    vector<int> a;      // 有哪些点，因为不是连续的，用vector方便定位这些的点
    for (int i = 0; i < n; i++)
    {
        int x, m;
        cin >> x >> m;
        a.push_back(x);
        st[x] = true;

        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            d[temp] ++;
            v[x].push_back(temp);
        }
    }

    // 入度为0入队
    queue<int> q;
    for (auto i : a) if (d[i] == 0) q.push(i);

    // 开始拓扑排序
    int cnt = 0;
    while (!q.empty())
    {
        int const now = q.front();
        q.pop();

        for (auto i : v[now])// 遍历监视的点
        {
            d[i] --;
            if (d[i] == 0 && st[i]) q.push(i);
        }
        cnt ++;
    }

    if (cnt == n) cout << "YES" << '\n';
    else cout << n - cnt << '\n';
    return 0;
}



// https://www.luogu.com.cn/problem/P2712