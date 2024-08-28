#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 约瑟夫环
 * 由n个人组成一个圆环，每次沙掉报出k的人，沙掉后这个人后面的人重新开始报数
 * 数据范围：n和k=10^6
 *
 * 数据范围过大，暴力O(nm)必炸
 *
 * 1.因为题目说再沙掉一个人后从他后面的那个重新计数，那么就可以看成是将数组前移k个之后得到的
 * 2.初始状态为(n,k)在沙掉一个后为(n-1,k)是(n,k)的一个子问题，借用DP的思维解题
 *  设f[i]为长度为(i,k)的解，那么只要得到状态转移方程就可以轻松解题
 *
 * 结合上面两点，(4,3)就可以由以下的过程得到
 * f[1]=0
 * f[2]=(f[1]+3)%2=1    // 只有两个数，不能超过限制，需要对总数取模
 * f[3]=(f[2]+3)%3=1
 * f[4]=(f[3]+3)%4=0    // (4,3)状态
 * 得出状态转移方程f[i]=(f[i-1]+k)%i
 *
 * 综上所述，没懂。
 * */

const int N = 1e6 + 10;
int f[N];

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
        f[i] = (f[i - 1] + m) % i;// 模拟后移的过程，依次递推
    cout << f[n] + 1;
    return 0;
}


// https://www.luogu.com.cn/problem/P8671