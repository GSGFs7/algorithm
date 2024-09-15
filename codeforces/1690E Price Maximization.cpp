#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 给出n个包裹和k求每两个包裹相加除以k的最大值，向下取整
 * 未被k取余的那部分必定为答案，取余的部分找方法求出相加大于k的组合
 * 排序后给出双指针从前后开始查找，此时若结果大于k必定为最优解，如果存在不符合的数直接放弃
 * 这个数加可得到的最大值都无法大于k那么它无论与哪个数相加都无法大于k
 * */

const int N = 2e5 + 10;
int a[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        a[i] = x % k;
        sum += x / k;
    }

    sort(a, a + n);

    int l = 0, r = n - 1;
    while (l < r)// 尽量多的凑处大于k的数
    {
        if (a[l] + a[r] < k) l++;
        else sum ++, l ++, r --;
    }

    cout << sum << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.codeforces.com/problemset/problem/1690/E