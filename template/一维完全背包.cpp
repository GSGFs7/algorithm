#include <iostream>
using namespace std;

const int N = 1010;
int f[N], w[N], v[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    // 因为可以使用多次，即使从左边开始已经使用过一个元素更新最大值，
    // 在右边仍然可以用这个数来更新右边的最大值
    // 而01背包就不能多次取同一个值，所以只能从右边开始
    cout << f[m] << endl;
    return 0;
}