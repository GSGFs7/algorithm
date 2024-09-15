#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 有n座桥，每天都会涨潮落潮，求大于k次淹没的桥的个数
 * 不看潮的涨落范围，只看桥的范围，所有问题针对桥来处理，题目就会简化
 * */

const int N = 1e5 + 10;
int h[N], vis[N];

/* 为什么STL会RE */
// corrupted size vs. prev_size

int main()
{
    int n, m, k;
    int cases = 0;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
//        vector<int> h(n);// 记录桥的高度
//        vector<int> vis(n);// 以差分形式记录桥的淹没次数，与桥的数组对应
        for (int & i : vis) i = 0;// 初始化为0

        for (int i = 0; i < n; i++) cin >> h[i];

//        sort(h.begin(), h.end());
        sort(h, h + n);

        int last = 1, x, y;// 上一个数和这次输入的数
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            // 头文件algorithm中的函数，利用二分实现
            // 找到第一个可以插入val而不改变原来数组的位置（前面），即小于目标元素的第一个位置 迭代器-头部=下标
//            auto l = lower_bound(h.begin(), h.end(), last + 1) - h.begin();
            // 找到最后一个可以插入val而不改变原来数组的位置（前面），即大于等于目标元素的第一个位置
//            auto r = upper_bound(h.begin(), h.end(), x) - h.begin();
            auto l = lower_bound(h, h + n, last + 1) - h;
            auto r = upper_bound(h, h + n, x) - h;
            vis[l] ++, vis[r] --;// 差分
            last = y;// 记录低潮位
        }

        // 解差分
        // 因为差分数组1 0 0 0 -1就表示1 1 1 1 1，所以累加即可（这么简单为啥当时想不到）
        int cnt = 0, ans = 0;
        for (int const i : vis)
        {
            cnt += i;
            if (cnt >= k) ans ++;
        }
        cout << "Case " << ++ cases << ": " << ans << endl;
    }
    return 0;
}

// https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1152