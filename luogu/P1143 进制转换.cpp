#include <iostream>
using namespace std;

int main()
{
    int n, m;
    string k;
    cin >> n >> k >> m;

    // 先转换为10进制
    unsigned long long t = 0;
    int j = 1;
    for (string::iterator i = k.end() - 1; i != k.begin() - 1; i--)
    {
        if (*i >= 'A')
        {
            t += (*i - 'A' + 10) * j, j *= n;
        }
        else
        {
            t += (*i - '0') * j, j *= n;
        }
    }
    // cout << t << endl;

    // 再转换为其他进制
    string s;
    int temp;
    while (t)
    {
        temp = t % m;
        if (temp > 9) s += (char)(temp - 10 + 'A');
        else s += (char)(temp + '0');
        t = t / m;
    }
    for (int i = s.size()-1; i >= 0; i--) cout << s[i];
    return 0;
}


// https://www.luogu.com.cn/problem/P1143