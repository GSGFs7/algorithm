#include <bits/stdc++.h>
//#define __LOCAL
using namespace std;

/*
 * 求将单词首尾相接可的到的最大长度
 * 先求出两两单词间的重合部分
 * 再通过DFS搜索最大的答案
 * */

const int N = 20;
string s[N];
int n;
int overlap[N][N];
int vis[N];
int Length = 0;
int ans = 0;

// 求出i尾部与j头部的重叠部分，未判断是否完全包含或者是自身
int getOverlap(int x, int y)
{
    int len1 = s[x].size(), len2 = s[y].size();
    for (int i = len1 - 1, j = 0; i >= 0 && j  < len2; i --)
        if (s[x][i] == s[y][j] && s[x].substr(i, len1 - i) == s[y].substr(0, len1 - i))
            return len1 - i;

    return 0;
}

void dfs(int u)
{
    ans = max(ans, Length);

    for (int i = 0; i < n; i++)
    {
        if (overlap[u][i] && vis[i] < 2)
        {
            vis[i] ++;
            Length += s[i].size() - overlap[u][i];// 这样处理可以不用判getOverlap上的条件，因为是全排列
            dfs(i);
            Length -= s[i].size() - overlap[u][i];
            vis[i] --;
        }
    }
}

void debug()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << overlap[i][j] << ' ';
        cout << endl;
    }

}

int main()
{
#ifdef __LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    char c;
    cin >> c;

    // 求出重叠的部分
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            overlap[i][j] = getOverlap(i, j);

    for (int i = 0; i < n; i++)
        if (s[i][0] == c)
        {
            vis[i] ++;
            Length = s[i].size();
            dfs(i);
            vis[i] --;
        }

    //debug();

    cout << ans << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1019