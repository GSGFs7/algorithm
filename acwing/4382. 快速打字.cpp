#include <iostream>
#define endl '\n'
using namespace std;

/*
 * 看从第二个数组中删掉多少个数可以与第一个数相等
 * 双指针，第一个数组不动，第二个数组进行匹配
 * 如果匹配成功两个指针都向后加一
 * 如果失败第二个指针加一
 * */

int main()
{
    int n;
    cin >> n;
    int m = n;
    while (m--) {
        string a, b;
        cin >> a >> b;
        int l1 = 0, l2 = 0;
        while (l1 < a.size() && l2 < b.size())
        {
            if (a[l1] == b[l2]) l1 ++;// 如果匹配成功继续匹配下一个
            l2 ++;// 如果失败继续向后查找
        }
        if (l1 == a.size()) cout << "Case #" << n - m << ": " << b.size() - a.size() << endl;
        else cout << "Case #" << n - m << ": IMPOSSIBLE" << endl;
    }
    return 0;
}


// https://www.acwing.com/problem/content/description/4385/