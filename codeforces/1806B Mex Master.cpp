#include <iostream>
using namespace std;

// 排列给出的数组，找到一种方案，使a[i]+a[i+1]不存在一个最小的数

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int n0 = 0, n1 = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp == 0) n0++;
            if (temp == 1) n1++;
        }
        // 当存在大于半数的0时那么无论如何排列都不会出现0
        // {0 1 0} 最小为1，应该向上取整
        if (n0 <= (n + 1) / 2) puts("0");
            // 另一半必须全部为1才能取得2，否则只能为1
        else if (n - n1 - n0 > 0 || n0 == n) puts("1");
        else puts("2");
    }
    return 0;
}


// https://codeforces.com/problemset/problem/1806/B
// https://www.luogu.com.cn/problem/CF1806B