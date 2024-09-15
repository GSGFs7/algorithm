#include <iostream>
using namespace std;

const int N = 210;
int a[N][N];

/*
找规律，以对角线为分割线，填入1~n
1 2 3 4
1 5 6 7
2 5 8 9
3 6 8 10
4 7 9 10
 */

int main()
{
    int n;
    cin >> n;
    int m = 0;// 矩阵边长
    while (m * (m + 1) <= 2 * n) m ++;

    if (n == 2) { cout << 1 << ' ' << 2 << endl << 1 << ' ' << 2 << endl; exit(0); }
    /// 赋值
    // 处理右上角
    int cnt1 = 1;
    for (int i = 1; i <= m - 1; i++)
        for (int j = i; j <= m - 1; j++)
            a[i][j] = cnt1 ++;
    // 处理左下角
    int cnt2 = 1;
    for (int i = 1; i <= m - 1; i++)
        for (int j = i + 1; j <= m; j++)
            a[j][i] = cnt2 ++;

    cout << m << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m - 1; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}

// https://mirror.codeforces.com/problemset/problem/125/C