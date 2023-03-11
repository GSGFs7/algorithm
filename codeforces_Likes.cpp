#include <iostream>
using namespace std;

const int N = 1e5 + 19;
int a[N];

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int num;
        cin >> num;
        for (int i = 0; i < num; i++) cin >> a[i];

        int p = 0, n = 0;
        for (int i = 0; i < num; i++)
        {
            if (a[i] > 0)
            {
                p++;// 得到正数的个数
            } else n++;
        }
        // max
        // 正
        int res = 0;
        for (; res < p; res++) cout << res + 1 << ' ';

        // 负
        for (int i = 0; i < n; i++) {
            res--;
            cout << res << ' ';
        }
        cout << endl;

        // min
        // 正负交替
        int res1 = 0;
        for (int i = 0; i < num; i++) {
            if (p != 0) {
                p--;
                res1++;
                cout << res1 << ' ';
            }
            if (n != 0) {
                n--;
                res1--;
                cout << res1 << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}

// https://codeforces.com/contest/1802/problem/A