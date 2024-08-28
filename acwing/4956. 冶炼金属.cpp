#include <iostream>
#include <vector>
#include <algorithm>

// 符合所有测试点的话，要从每个测试点的下限找到最大值，从上限找到最小值
// 用二分来快速查找

using namespace std;

const int N = 1e4 + 10;
const int MAX = 1e9;// 二分的时间复杂度(nlog10^9)
int a[N], b[N];

/// 二分查找
int searchMin(int k)
{
    int l = 1, r = MAX;

    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[k] / mid <= b[k]) r = mid;
        else l = mid + 1;// l和r向中间靠拢
    }
    return l;
}

int searchMax(int k)
{
    int l = 1, r = MAX;

    while (l < r)
    {
        int mid = l + r + 1 >> 1;// 注意向上取整，不然死循环
        if (a[k] / mid >= b[k]) l = mid;
        else r = mid - 1;
    }
    return r;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    // v1存储最小值，v2存储最大值
    vector<int> v1, v2;

    for (int i = 0; i < n; i++)
        v1.push_back(searchMin(i)), v2.push_back(searchMax(i));

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    cout << v1.back() << ' ' << v2.front();

    return 0;
}



// https://www.acwing.com/problem/content/4959/


/// 思维解题
// 上限为 a / b
// 下限为 a / (b + 1) + 1   即找到干好小1的那个点然后加一
/*
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ansMIN = 0, ansMAX = PATH_MAX;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        int l = a / (b + 1) + 1;
        int r = a / b;
        ansMIN = max(ansMIN, l);
        ansMAX = min(ansMAX, r);
    }
    cout << ansMIN << ' ' << ansMAX;
    return 0;
}*/
