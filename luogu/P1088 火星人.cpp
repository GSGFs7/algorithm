#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int a[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) next_permutation(a, a+n);// 全排列函数，每调用一次将排列出下一大的数
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;
}