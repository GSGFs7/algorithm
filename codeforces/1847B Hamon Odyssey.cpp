#include <iostream>
#include <vector>
using namespace std;

/*
 * 给出一个数组
 * 求最多可以划分出多少次，且每次划分，数组内的位与结果最小
 * 
 * 位与运算
 * 两个数必须都是1，结果才为1
 * 因为位与只会使值减小，所以全部位与起来就是最小的
 * 从前开始枚举，只要结果全变成0就划分一次，如果最后结果不为0就回溯一次
 * */

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cnt = 1;// 本来就是1
    for (int i = 1; i < n; i++)// 全部位与
    {
        if (a[i - 1] == 0) { cnt ++; continue; }// 如果是0就划分一次
        a[i] = a[i] & a[i - 1];
    }
    if (cnt != 1 && a[n - 1] != 0) cnt --;// 最后位与的结果也要最小

    cout << cnt << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/problemset/problem/1847/B