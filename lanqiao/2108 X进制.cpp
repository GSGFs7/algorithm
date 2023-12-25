#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

/*
 * 给出两个数，两个数的各个数位间可能有不同的进制，但两个数进制保持一致
 * 进制最大不超过N，最小不超过2，求这两个数相减的最小结果
 *
 * 给两个数组倒过来，后面添上0，就可以优雅地计算了
 * 当前这个数的1表示的值用base存储，base可以用前缀积得到
 * */

const int MOD = 1000000007;

signed main()
{
    int N;
    cin >> N;
    int n1, n2;
    cin >> n1;
    vector<int> a(n1);
    for (auto& i : a) cin >> i;// 读入
    cin >> n2;
    vector<int> b(n2);
    for (auto& i : b) cin >> i;

    /// 优雅
    int len = max(n1, n2);// 最大长度
    reverse(a.begin(), a.end());// 倒转数组
    reverse(b.begin(), b.end());
    a.resize(len, 0);// 对齐，给短的后面添上0，全是0的部分不影响计算结果
    b.resize(len, 0);

    // cout << "a:"; for (int i : a) cout << i << ' '; cout << '\n';
    // cout << "b:"; for (int i : b) cout << i << ' '; cout << '\n';

    int ans = 0;// 最后结果
    int base = 1;// 当前这一位代表十进制中的多少
    for (int i = 0; i < len; i++)
    {
        ans += base * a[i] - base * b[i];
        ans %= MOD;// 记得取模
        base *= min(max(max(a[i], b[i]) + 1LL, 2LL), N);// 限制在2和N之间
        base %= MOD;// 这个也是

        // cout << "ans:" << ans << '\n';
        // cout << "base:" << base << '\n';
    }
    cout << ans << '\n';
    return 0;
}


// https://www.lanqiao.cn/problems/2108/learning/