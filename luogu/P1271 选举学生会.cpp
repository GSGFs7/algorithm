#include <iostream>
using namespace std;

const int N = 2e6 + 10;
int a[N];

int main()
{
    int n, m;
    cin >> n >> m;
    int x;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        a[x]++;
    }

    for (int i = 1; i <= n; i++)
    {
        while (a[i] != 0)
        {
            cout << i << " ";
            a[i]--;
        }
    }
    return 0;
}

// 排序转变为计数
// https://www.luogu.com.cn/problem/P1271