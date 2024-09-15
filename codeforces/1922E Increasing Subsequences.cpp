#include <iostream>
#include <vector>

using namespace std;
#define int long long

// NOTICE
// Note that an empty subsequence is also increasing.
// 空序列也算作其中的一个满足条件

/*
 * 题目描述:
 *  给出一个n, 求是否存在一个最短的序列, 使这个序列的子序列递增子序列的个数为n
 * 输入:
 *  一行一个整数, n
 * 输出:
 *  第一行输出序列的长度
 *  第二行输出序列
 *
 * 手动打表:
 *  0           2
 *  0 1         4
 *  0 1 2       8
 *  0 1 2 3     16
 *  明显, 有n个数的话就是2^n个递增子序列(包括空序列)
 * but, 只能处理正好是2^n的数需要进一步缩小范围
 * 对于这样一个很有规律的例子:
 *  1 2 3       有8个递增子序列
 *  0 1 2 3     如果在前面加上一个0, 就会变成16个
 *  1 1 2 3     在前面加一个1就会变成12个, 好像没什么规律
 *  2 1 2 3     如果加的是2就会变成10个,依旧没什么头绪
 *  3 1 2 3     如果是3就会变成9个, 每次加的数增大到与后面的数相等时就会发生变化
 * +8 +4 +2 +1  也就是说每次都增加了2的次方级的子序列
 * 而这个值正好就是后面大于添加的数的个数, 上面的数也就可以看成2^3,2^2,2^1,2^0
 * 人类智慧题...
 * */

void solve() {
    int n;
    cin >> n;

    /// 最大的log2
    auto log2 = [&](int x)->int {
        for (int i = 62; i >= 0; i--) {// 不能i=63, 会变负
            if (x > (1LL << i)) return i;
        }
        return 0;
    };
    // cout << log2(100) << '\n';
    // cout << (1LL << 63) << '\n';

    /// 快速幂
    auto pow = [&](int x, int y) {
        int res = 1;
        int base = x;
        while (y) {
            if (y & 1) res *= base;
            y >>= 1;
            base *= base;
        }
        return res;
    };

    int l = log2(n);
    vector<int> ans(l);
    for (int i = l - 1, cnt = 0; i > 0; i--) {// 最大的log2
        ans[cnt ++] = i;
    }

    // 继续找最大的log2, 这样在加上的同时也不会干扰后面的数(因为是倒序的)
    n -= pow(2, l);
    while (n) {
        int k = log2(n);// 也就是说当前这个数要比后面k个数小
        ans.push_back(l - k - 1);// 注意ans反过来了
        n -= pow(2, k);
    }

    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}


signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1922/problem/E
// 31ms 152KB   位运算, 嘎嘎快