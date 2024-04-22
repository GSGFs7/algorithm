#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
#define int long long

/*
 * 给出一个矩阵, 求有多少个子矩阵的和不超过k
 *
 * 思路:
 *  二维前缀和+双指针优化
 *  前缀和的暴力做法: 枚举两个端点, 每个端点需要O(n^2), 一共O(n^4)的复杂度
 *  n=500, 按照暴力算法会炸, 需要进行优化
 *  在暴力枚举的过程中会发现有时候区间值已经超过k了, 但是区间扩张仍在继续
 *  可以进行以下优化: 如果当前区间的值没有超过k, 就继续扩张, 如果超过了k就反向的收缩区间, 等区间值重新小于k之后再继续扩张
 *  那么就可以设置上下的边界为正常的枚举, 而左右的边界, 让有边界正常扩张, 等到右边界扩张到一个大于k的地方再收缩左边界
 *  这样就可以直接优化掉左区间的枚举, 减少到O(n^3)的复杂度
 *
 *  这样处理后还剩下一个问题, 如何计算有多少个区间呢?
 *  对于高度为1的情况而言,例如 1 2 3 如果加入第四个数, 子矩阵就会从原来的3+2+1个变成4+3+2+1个增加了 原本区间长度再加一 个子矩阵
 *  换个方式理解就是 1 2 3 中加入4之后, 带4的只有 1234 234 34 4, 这四个
 *  写成代码形式就是 r-l+1
 *  对于高度不为1的情况而言, 上下指针会每次进行添加, 略(其实就是证不出来)
 * */

const int N = 510;
int a[N][N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    // vector会TLE, 卡的太极限了, 只能用静态数组
    // vector<vector<int> > a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];// 计算前缀和
        }
    }

    // debug
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = 0;
    for (int i = 1; i <= n; i++) {// 上边界
        for (int j = i; j <= n; j++) {// 下边界
            for (int l = 1, r = 1; r <= m; r++) {// 左右边界
                // 如果区间的和超过了k, 就需要收缩区间
                while (l <= r && a[j][r] - a[j][l - 1] - a[i - 1][r] + a[i - 1][l - 1] > k) l ++;
                if (l <= r) ans += r - l + 1;
            }
        }
    }
    cout << ans << '\n';
}


signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto start = chrono::system_clock::now();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//    cout << duration.count();
    return 0;
}


// https://www.acwing.com/problem/content/4408/
// update 2024年3月16日

/// old
/*
#include <iostream>
using namespace std;

/// 前缀和 && 双指针
*/
/*
 * 正常处理子矩阵需要依次枚举四条边n^4级
 * 题目数据限制，需要优化到n^3级
 * 上下边界可暴力枚举
 * 左右边界可通过两个指针维护优化到n^3级
 * *//*


const int N = 510;
int s[N][N];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> s[i][j], s[i][j] += s[i - 1][j];

    long long ans = 0;
    for (int i = 1; i <= n; i ++)// 上边界
        for (int j = i; j <= n; j ++)// 下边界
            for (int l = 1, r = 1, sum = 0; r <= m; r ++)
            {
                sum += s[j][r] - s[i - 1][r];
                while (sum > k)
                {
                    sum -= s[j][l] - s[i - 1][l];
                    l ++;
                }
                ans += r - l + 1;// 避免因为范围扩大而没加入后面几列的组合，因为l并不是每次增加一的
            }
    cout << ans << endl;
    return 0;
}

// https://www.luogu.com.cn/problem/P8783
// https://www.acwing.com/solution/content/110471/*/
