#include <iostream>
using namespace std;

const int N = 100010;
bool a[N];
int cnt = 0;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i += 2)// 标记是否需要翻转
        if (s[i] != s[i + 1])
        {
            if (s[i] == 'G')
                a[cnt ++] = true;
            else
                a[cnt ++] = false;
        }

    int ans = 0;
    for (int i = 0; i <= cnt; i++)// 统计需要翻转多少次
        if (a[i] != a[i + 1])
            ans ++;

    cout << ans << endl;

    //for (int i = 0; i <= 100; i++) cout << a[i];
    return 0;
}


// https://www.acwing.com/problem/content/description/4443/