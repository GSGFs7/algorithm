#include <iostream>
using namespace std;

// 输出质因数和他的指数

// 时间复杂度O(sqrt(n)) 最好是logn 最坏是sqrt(n)
void divide(int n)
{
    for (int i = 2; i <= n / i; i ++)
        if (n % i == 0)// 找出指数
        {
            int s = 0;
            while (n % i == 0)// 看这个数能被质数除几次，能除几次就是几次方
            {
                n /= i;
                s ++;
            }
            cout << i << ' ' << s << endl;
        }
    if (n > 1) cout << n << ' ' << 1 << endl;
    cout << endl;// 输出完后空一行
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        divide(a);
    }
    return 0;
}


// https://www.acwing.com/problem/content/869/