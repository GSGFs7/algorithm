#include <bits/stdc++.h>
#define LOCAL
using namespace std;

/*
 * 给出年月日并要求填空，求质数解
 *
 * 思路：实际用到的数据范围不大，先预处理出所有的符合条件的值，再暴力匹配
 * 处理起来是真的麻烦，调了一个下午
 * */

const int N = 1e6;
int m_d[N];// 月加上日构成的数
int cnt1 = 0;
int ans[N];// 预处理得到的答案
int cnt2 = 0;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31};
const int p[] = {0,3,5,7,11,13,17,19,23,29,31,37};

bool check(int x)
{
    for (int i = 2; i <= x / i; i++)
        if (!(x % i)) return false;
    return true;
}

void solve()
{
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < cnt2; i++)
    {
        int now = ans[i];
        int flag = 1;
        for (int j = 8; j; j--, now /= 10)
            if (s[j - 1] != '-' && s[j - 1] - '0' != now % 10)
            {
                flag = 0;
                break;
            }
        res += flag;
    }
    cout << res << endl;
}

void debug()
{
    //for (int i = 0; i < cnt2; i++)
    //  cout << ans[i] << ' ';
//    int cnt = 1;
//    while (ans[cnt]) cnt ++;
//    cout << cnt << endl;

    for (int i = 0; i < cnt2; i++) cout << ans[i] << ' ';
    cout << endl;
}

int main()
{
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    // 一起处理月和日
    for (int i = 1; i <= 12; i++)// 枚举月
        for (int j = 1; p[j] <= day[i]; j++)// 枚举日
            if (check(i * 100 + p[j]))
                m_d[cnt1 ++] = i * 100 + p[j];

    // 处理闰年
    for (int i = 4; i <= 9999; i += 4)
        if ((i % 100 || !(i % 400)) && check(i * 10000 + 229))
            ans[cnt2 ++] = i * 10000 + 229;

//    debug();

    for (int i = 1; i <= 9999; i++)
        for (int j = 0; j <= cnt1; j++)
            if (check(i * 10000 + m_d[j]))
                ans[cnt2 ++] = i * 10000 + m_d[j];

    int t;
    cin >> t;
    while (t--)
        solve();

    // debug
    //debug();

    return 0;
}


// https://www.luogu.com.cn/problem/P5440