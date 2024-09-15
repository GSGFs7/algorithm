#include <iostream>
#include <cstring>
using namespace std;

const int N = 1300;
bool a[N][N];

void dfs(int x, int y, int n)
{
    if (n > 0)
    {
        for (int i = x; i < n / 2 + x; i++)
            for (int j = y; j < n / 2 + y; j++)
                a[i][j] = false;

        dfs(n / 2 + x, y, n / 2);
        dfs(x, n / 2 + y, n / 2);
        dfs(n / 2 + x, n / 2 + y, n / 2);
    }
}

int main()
{
    int n;
    cin >> n;
    n = 1 << n;
    memset(a, true, sizeof a);

    dfs(0, 0, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}