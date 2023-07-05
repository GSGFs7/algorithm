#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 110;
vector<int> a[N];
int n;
int d[N];

vector<int> topoSort()
{
    queue<int> s;
    vector<int> l;
    for (int i = 1; i <= n; i++)
        if (!d[i]) s.push(i);

    while (!s.empty())
    {
        int const x = s.front();
        s.pop();
        for (auto i : a[x])
            if (-- d[i] == 0) s.push(i);
        l.push_back(x);
    }
    return l;
}

int main()
{
    cin >> n;
    for (int i = 1, x; i <= n; )
    {
        cin >> x;
        if (x == 0) i ++;
        a[i].push_back(x);
        d[x] ++;// 入度
    }

    vector<int> a = topoSort();
    for (auto i : a) cout << i << ' ';
    return 0;
}

// https://www.luogu.com.cn/problem/B3644