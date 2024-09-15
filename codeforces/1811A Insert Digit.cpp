#include <iostream>
using namespace std;

// 在一个大数中插入一个单独的数
// 使产生的数最大

void solve()
{
    int n;
    char c;
    string s;
    cin >> n >> c >> s;

    int i = 0;
    while ( i < n && s[i] >= c) i++;// 找到一个小于c的数，不能等于
    s.insert(i, 1, c);// 插到那个数的前面
    cout << s << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1811/problem/A