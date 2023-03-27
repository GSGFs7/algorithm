#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#define endl "\n"    // endl会清空缓冲区，比\n慢十倍
#include <iostream>
#include <vector>
using namespace std;

int n;

void k()
{
    // vector输入提速
    cin >> n;
    vector<int>v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
}

int main()
{
    // 解绑
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);



    return 0;
}