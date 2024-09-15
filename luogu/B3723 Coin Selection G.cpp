#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 两个人轮流拿硬币，只能拿面额比自己总金额小的，如果没有就拿最小的
 *
 * 1000的数据范围，直接暴力遍历即可
 * 比赛时我竟然还在想四个堆区分出大小进行处理
 * */

const int N = 1010;
int a[N];
int vis[N];

signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int sum1 = 0, sum2 = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++) {// 只会进行n轮
        if (flag) {// 第一个人
            int pos = 0;// 擂台
            for (int j = 1; j <= n; j++) {// 遍历所有硬币
                if (vis[j] == true) continue;// 如果遍历过
                if (a[j] > sum1) continue;// 如果超出总面额

                if (pos == 0 || a[j] > a[pos]) pos = j;
            }
            if (pos == 0) {// 如果没有找到硬币
                for (int j = 1; j <= n; j++) {
                    if (vis[j] == true) continue;

                    if (pos == 0 || a[j] < a[pos]) pos = j;
                }
            }
            vis[pos] = true;
            sum1 += a[pos];
            flag = false;
        } else {// 第二个人，复制一遍即可
            int pos = 0;
            for (int j = 1; j <= n; j++) {
                if (vis[j] == true) continue;
                if (a[j] > sum2) continue;
                if (pos == 0 || a[j] > a[pos])
                    pos = j;
            }
            if (pos == 0) {
                for (int j = 1; j <= n; j++) {
                    if (vis[j] == true) continue;
                    if (pos == 0 || a[j] < a[pos]) pos = j;
                }
            }
            vis[pos] = true;
            sum2 += a[pos];
            flag = true;
        }
    }
    cout << sum1 << ' ' << sum2 << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/B3723