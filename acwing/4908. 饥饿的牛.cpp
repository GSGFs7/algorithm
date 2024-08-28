#include <iostream>
#define int long long
using namespace std;

/*
 * 在一个很大的区间内设定几个点
 * 求覆盖面积
 * 暴力枚举每一天必炸
 * 改为枚举每个节点
 * 每次枚举都加上覆盖天数
 * 一定要好好处理边界问题
 * */

signed main()
{
    int n, t;
    cin >> n >> t;
    int last = 0, res = 0, cur = 0;// last上一天，res最终答案，cur剩下的次数
    for (int i = 1; i <= n; i++)
    {
        int d, b;
        cin >> d >> b;
        int const len = d - last - 1;// 区间长度
        int const days = min(len, cur);// 覆盖长度
        res += days;// 加上覆盖长度
        cur = cur - days + b;// 更新剩下的，因为时即使cur小于长度也不会变负数
        last = d - 1;// 更新last
    }

    res += min(cur, t - last);// 处理最后一段
    cout << res << endl;
    return 0;
}


// https://www.acwing.com/problem/content/description/4911/