#include <iostream>
using namespace std;

const int N = 1e4 + 10, M = 1e5 + 10;

int main()
{
    int n, m;
    char p[N], s[M];
    int ne[N];
    cin >> n >> (p+1) >> m >> (s+1);

    // Çónext
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j+1]) j = ne[j];// ne[i] == ne[i-2]
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }

    // kmpÆ¥Åä
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n)
        {
            cout << i - n << " ";
            j = ne[j];
        }
    }
    return 0;
}