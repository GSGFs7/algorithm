#include <iostream>
using namespace std;

// 一共走n级台阶，可以一次走k步，问可以有多少种走法
// 斐波那契 数学规律

const int N = 100086;
int a[N];
const int mod = 100003;

int main()
{
    int n, k;
    cin >> n >> k;
    a[0] = 1;
    a[1] = 1;
    if (k == 1) cout << 1 << endl;
    else
    {
        for (int i = 2; i <= n; i++)
            if (i < k) a[i] = a[i - 1] * 2 % mod;// 小于k时为2的i次方
            else a[i] = (2 * a[i - 1] - a[i - k - 1] + mod) % mod;// 大于时为前面那个数乘二 减去 i-k-1
        // 去负数
        //for (int i = 0; i <= n; i++) cout << a[i] << ' ';
        cout << a[n] << endl;
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P1192