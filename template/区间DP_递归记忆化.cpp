#include <iostream>
#include <cstring>
using namespace std;

/*
 * 因为只需要一半的代价，合并最后两堆石子时存在一个分界线，使结果最小
 * 当结果确定时总代价=(1到x的总代价)+(x+1到n的总代价)
 * 不知道分界线时直接暴力枚举，由此可得递推方程
 * 将一个大问题划分为最基本的小问题（DP的思维方式）
 * 递归时每次都取最小值
 * 递归很慢，一个相同的区间会被计算很多次
 * 时间复杂度：O(n^2)个区间，每次计算枚举分界线m，分界线最多约等于n，所以总复杂度是O(n^3)
 * 记忆化搜索！
 * 在递归的过程中记录每次运算的值，如果已经被计算过就直接使用
 * */

const int N = 1010;
int s[N], f[N][N];

int solve(int l, int r)
{
    if (f[l][r] != -1)
        return f[l][r];

    if (l == r) return 0;

    int ans = 1 << 30;// 初始化
    for (int m = l; m < r; m ++)// 枚举出最小的分界线
        ans = min(ans, solve(l, m) + solve(m + 1, r));// 每一层循环都保证最小
    return f[l][r] = ans + s[r] - s[l - 1];// ？
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    memset(&f, 255, sizeof f);// 设置为-1

    for (int i = 1; i <= n; i++) s[i] += s[i - 1];

    cout << solve(1, n) << endl;
    return 0;
}