#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出n对字母，使每对字母都连成一串（两个字母可以倒序）
 * 欧拉图
 * 先判断是否符合欧拉图形成的条件
 * 在找到起点和终点，开始DFS（欧拉图不需要回溯）
 * 最后记得倒序输出
 * */

const int N = 128;
int g[N][N];
int d[N];
int n;
vector<int> path;
int start = 0;// 起点
int cnt = 0;// 奇数点的个数

void dfs(int x, int cur)
{
    for (int i = 0; i < N; i++)
        if (g[x][i])
        {
            g[x][i] --;
            g[i][x] --;
            dfs(i, cur + 1);
        }
    path.push_back(x);// 欧拉图记得倒序!!!
    // 因为DFS可能会走进死路然后倒回
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        d[s[0]] ++;
        d[s[1]] ++;
        g[s[0]][s[1]] ++;
        g[s[1]][s[0]] ++;
    }

    // 寻找单数点作为起点
    for (int i = 0; i < N; i++)
    {
        if (d[i] & 1) {
            cnt++;
            if (cnt == 1) start = i;// 字典序最小的点作为起点
        }
    }

    // 如果不符合条件
    if (cnt && cnt != 2)
    {
        cout << "No Solution";
        exit(0);
    }

    // 如果没有奇点
    if (!cnt)
    {
        for (int i = 0; i < N; i++)
            if (d[i])
            {
                start = i;
                break;
            }
    }

    path.push_back(start);// 最后的点
    dfs(start, 0);

    int const len = path.size();
    for (int i = len - 1; i; i--)
        cout << char(path[i]);
    return 0;
}


// https://www.luogu.com.cn/problem/P1341