#include <iostream>
#include <algorithm>
using namespace std;

/// DFS+剪枝
/*
 * 靶形数独
 * 9*9的数独，越靠近中间分数越高，求最高得分
 *
 * 类似八数码，先预处理出行，列，块的状态，再根据状态快速搜索填空
 * DFS搜索每个点（cur），并同时维护sum，表示最大值
 * 再通过点的编号求出作坐标，如果该坐标未被填充就根据该点所对应的状态来填空
 * 如果已经存在一个数，就计算sum和last跳向下一个数
 * */

typedef pair<int, int> PII;
const int N = 20;// 要开到20
int g[N][N];
int ans = -1;
int row[N][N], line[N][N], block[N][N];// 看行，列，块中哪些数不能填
PII vacancy[N];

// 得分表
const int score[N][N] = {
        {6, 6, 6, 6, 6, 6, 6, 6, 6},
        {6, 7, 7, 7, 7, 7, 7, 7, 6},
        {6, 7, 8, 8, 8, 8, 8, 7, 6},
        {6, 7, 8, 9, 9, 9, 8, 7, 6},
        {6, 7, 8, 9, 10, 9, 8, 7, 6},
        {6, 7, 8, 9, 9, 9, 8, 7, 6},
        {6, 7, 8, 8, 8, 8, 8, 7, 6},
        {6, 7, 7, 7, 7, 7, 7, 7, 6},
        {6, 6, 6, 6, 6, 6, 6, 6, 6}
};

// 看是哪个小的数独区块
int get_block(int i, int j)
{
    int const x = i - (i % 3), y = j - (j % 3);
    return x * 3 + y;
}

bool cmp(PII A, PII B)
{
    return A.second < B.second;
}

void DFS(int cur, int sum, int last)// cur表示点的编号，sum表示当前状态的得分，last表示剩下数的和（用于最优性剪枝）
{
    if (cur == 81)// 如果搜到底
    {
        ans = max(ans, sum);
        return ;
    }

    // 最优性剪枝
    if (sum + 9 + last * 9 < ans) return ;

    // 根据cur得到当前坐标
    int const x = vacancy[cur / 9].first, y = cur % 9, b = get_block(x, y);
    if (g[x][y]) DFS(cur + 1, sum + g[x][y] * score[x][y], last - g[x][y]);// 如果不是空就搜下一个点
    else {
        for (int k = 1; k <= 9; k++)// 找到应该未被标记的数
            if (!row[x][k] && !line[y][k] && !block[b][k]) {// 如果成功找到
                row[x][k] = line[y][k] = block[b][k] = true;
                DFS(cur + 1, sum + k * score[x][y], last - k);
                row[x][k] = line[y][k] = block[b][k] = false;// 回溯
            }
    }
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> g[i][j];
            if (g[i][j])// 类似八数码问题的解法，给每个点上标记，遇到空时可一快速找到可填的值
                row[i][g[i][j]] = line[j][g[i][j]] = block[get_block(i, j)][g[i][j]] = true;
            else
                vacancy[i].second ++;// 如果遇到空就加一
        }

    for (int i = 0; i < 9; i++) vacancy[i].first = i;
    sort(vacancy, vacancy + 9, cmp);// 优化搜索顺序剪枝，按空缺由小到大排序

    DFS(0, 0, 405);// 405是数独中所有数字的和
    cout << ans << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P1074