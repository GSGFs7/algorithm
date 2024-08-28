#include <iostream>
#include <algorithm>

// 寻找范围内拥有最大差值的一个数

using namespace std;

int mx;// 最大差值
int ans;// 答案

void solve()
{
    int l, r;
    cin >> l >> r;
    mx = 0;// 初始化
    for (int i = l; i <= r; i++)
    {
        string a = to_string(i);// 转换为字符
        sort(a.begin(), a.end());// 排序，获得最大和最小的字符
        int k = (int)a[a.size() - 1] - (int)a[0];// 得到差值
        if (k >= mx)// 更新
        {
            mx = k;
            ans = i;
        }
        if (mx == 9) return;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << ans << endl;
    }
    return 0;
}


// https://codeforces.com/contest/1808/problem/A