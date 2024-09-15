#include <iostream>
#define int long long
using namespace std;

/*
 * 01背包变体
 * 将输掉比赛的得分全部加起来存做基础值
 * 在写01背包转移方程的时候用输赢的差值代表价值
 * 这样就能得到最大价值
 * 加上基础值诚意5就是最后答案
 * */

const int N = 1010;
int f[N], w[N], l[N], u[N];

signed main()
{
    int n, x;
    cin >> n >> x;
    long long base = 0;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> w[i] >> u[i], base += l[i];
    // l和w写反了，卡了半个多小时，f[i]怎么都是0

    for (int i = 1; i <= n; i++)
        for (int j = x; j >= u[i]; j--)
            f[j] = max(f[j], f[j - u[i]] + w[i] - l[i]);

    /*
    //dbg
    for (int i = 1; i <= x; i++) {
        cout << f[i] << ' ';
    }
    cout << endl;
     */

    cout << 5LL * (base + f[x]) << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1802