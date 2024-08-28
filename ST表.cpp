#include <bits/stdc++.h>
using namespace std;

/*
 * ST表
 * ST表是用于高效求一个静态表的区间极值的的数据结构（RMQ）
 * 采用倍增的思想，初始化时间复杂度O(logn)，查询时间复杂度O(1)
 *
 * 大致原理:
 * 第2层：9   第2层的每个数表示从自己到后边第四个数的最大值（0位置上的7表示前两个数的最大值，4上面的9表示后两个数的最大值）
 * 第1层：7   9   第1层的每个数表示从自己到后边第二个数个数的最大值
 * 第0层：0 7 4 9
 * 状态转移方程：f(i,j)=max(f(i,j-1),f(i+2^(j-1),(j-1)))
 * （实际计算时7上边的数也要计算，用于得到结果，不然结果的计算会变得复杂）
 *
 * 对于查询，将完整区间改为求(l,2^k-1)与(r-2^k+1,r)的最大值，k=log₂(r-l+1)
 * 得出的k是一个比较小的数，保证了(l,2^k-1)一定超过了中点，且不大于r，右区间同理
 * */

const int N = 1e5 + 10;
int n, m;
int a[N][21];    // ST表，ST[i][j]，i表示起点，j表示以2^j计算的长度
                 // ST[i][j]为(i,2^j)的范围内的最大值

// 快读,不然会TLE
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

void init() {
    // 倍增枚举每一个可以枚举的点的值, 状态转移方程，合并两个区间并求出最大值
    for (int i = 1; i <= 21; i++)                      // 枚举长度
        for (int j = 1; j + (1 << i) - 1 <= n; j++)    // 枚举起点
            a[j][i] = max(a[j][i - 1], a[j + (1 << (i - 1))][i - 1]);
}

int query(int l, int r) {
    int const k = log2(r - l + 1);    // 还原出最大可用长度
    // 后面有个+1，不然会漏掉最后一个数                                  
    return max(a[l][k], a[r - (1 << k) + 1][k]);
}

int main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i][0] = read();

    init();

    int l, r;
    while (m--) {
        l = read(), r = read();
        printf("%d\n", query(l, r));
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P3865
// 一个ST表的题 https://codeforces.com/contest/1691/problem/D
/* 这题的代码
#define int long long
const int N = 2e5 + 10;
int n;
int a[N];
int L[N], R[N];    // 左右第一个大于的位置
int sum[N];        // 前缀和

// ST表
int mi[N][20], ma[N][20];
int getmin(int l, int r) {                            // 找最小值
    if (l > r) return 0;                              //
    int k = __lg(r - l + 1);                          // 还原长度
    return min(mi[l][k], mi[r - (1 << k) + 1][k]);    // +1
}

int getmax(int l, int r) {    // 找最大值
    if (l > r) return 0;
    int k = __lg(r - l + 1);
    return max(ma[l][k], ma[r - (1 << k) + 1][k]);
}

void init() {
    for (int i = 1; i <= n; i++) ma[i][0] = mi[i][0] = sum[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 <= n; i++) {
            mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
            ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 用前缀和建立ST表
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    init();

    // 两个单调栈
    a[0] = a[n + 1] = 1e9 + 10;    // a[i]可以等于1e9!!!
    stack<int> st;
    for (int i = 0; i <= n; i++) {    // 从大到小的单调栈
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (st.empty()) st.push(i);
        L[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();

    // for (int i = 1; i <= n; i++) cout << L[i] << ' ';
    // cout << '\n';

    for (int i = n + 1; i >= 1; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (st.empty()) st.push(i);
        R[i] = st.top() - 1;
        st.push(i);
    }

    for (int i = 1; i <= n; i++) {
        int minn = getmin(L[i] - 1, i - 1);    // 区间最小值, 因为是前缀和
        int maxn = getmax(i, R[i]);            // 区间最大值
        if (maxn - minn > a[i]) return cout << "NO\n", void();
    }
    cout << "YES\n";
}
*/