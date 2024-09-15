#include <iostream>
using namespace std;

/*
 * 求最短路的条数
 * 因为只能向右下角前进 所以不用考虑其他情况
 * 小学奥数 标数法
 * f[i][j] = f[i - 1][j] + f[i][j - 1]
 * f中存储的数表示可抵达这个点的路径数
 * 所有路径都会在终点相聚
 * 所以终点的数值就是最后的条数
 * */

const int N = 30;
bool house[N][N];
long long f[N][N];
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int main()
{
    int a, b, c, d;
    cin >> c >> d >> a >> b;
    a ++, b ++, c ++, d ++;

    // 标记马的控制点
    house[a][b] = true;
    for (int i = 0; i < 8; i++)
        house[a + dx[i]][b + dy[i]] = true;

    // 标数法 dp
    f[0][1] = 1;
    for (int i = 1; i <= c; i++)
        for (int j = 1; j <= d; j++)
            if (!house[i][j])
                f[i][j] = f[i - 1][j] + f[i][j - 1];

    cout << f[c][d] << endl;
    /*
    // debug
    for (int i = 1; i <= c; i++)
    {
        for (int j = 1; j <= d; j++)
            cout << f[i][j] << ' ';
        cout << endl;
    }
    */
    return 0;
}