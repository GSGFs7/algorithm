#include <iostream>
#include <vector>
using namespace std;

/*
 * 枚举
 * 对于前后的循环来说直接用加或者减代替，也相当于达到的下一个循环
 * */

int cases = 0;

void solve()
{
    string s, f;
    cin >> s >> f;
    vector<int> k(s.size(), 0x3f3f3f3f);// 用于存储每个字符的差值

    int const len1 = f.size();
    for (int i = 0; i < len1; i++)// 数据范围不大直接枚举每个值
    {
        int const len2 = s.size();
        for (int j = 0; j < len2; j++)
        {
            k[j] = min(k[j], abs(s[j] - f[i]));// 当f[j]不用跨过循环
            k[j] = min(k[j], abs(s[j] - f[i] - 26));// 当f[j]向前循环
            k[j] = min(k[j], abs(s[j] - f[i] + 26));// 当f[j]向后循环
        }
    }

    long long ans = 0;
    for (auto i : k) ans += i;
    cout << "Case #" << ++ cases << ": " << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/4125/