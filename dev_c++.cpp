#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
using LL = long long;
/*
首先分析一下如果从全0开始操作若干次后得到的一定是一个递减的序列,
一个递减的序列中最多一个位置符合要求,所以最优操作一定是加一次然后立刻进行操作2
可以获得1的价值.

所以要考虑的只有清0之前的操作.可以发现两次操作可以获得1的价值,
而最多一次能获得n的价值,所以我们在最初的序列上不会使用超过2n次操作1,
所以暴力枚举在前2n次操作1后进行操作2更新答案即可.
*/
int main(){

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        vector<int> b(m);
        for(int i = 0; i < m; i++) cin >> b[i];

        int ans = 0;
        for(int i = 0; i < 2 * n && i < d; i++){
            int cnt = 0;
            for(int j = 1; j <= n; j++)
                cnt += (a[j] == j);

            ans = max(ans, cnt + (d - i - 1) / 2);
            
            int t = b[i % m];
            for(int j = 1; j <= t; j++)
                a[j] += 1;
        }
        cout << ans << '\n';
    }
    return 0;
}