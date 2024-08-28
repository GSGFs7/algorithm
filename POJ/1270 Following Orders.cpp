//#include <bits/stdc++.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

/*
 * 输入一组字母，表示先后顺序，输出符合这个顺序的所有拓扑序（按字典序的先后顺序）
 * */

const int N = 30;
int n;
int a[N], dir[N][N];  // dir[i][j]表示i,j是先后关系
int topo[N], vis[N], inDegree[N];// topo记录拓扑排序，vis标记是否访问，inDegree记录入度

void dfs(int z, int cnt)
{
    topo[cnt] = z;// 记录拓扑序
    if (cnt == n - 1)// 如果所有点都排序完成
    {
        for (int i = 0; i < n; i++) cout << char('a' + topo[i]);
        cout << '\n';
        return ;
    }

    vis[z] = 1;// 标记为已访问

    // 除去入度
    for (int i = 0; i < n; i++)
        if (!vis[a[i]] && dir[z][a[i]])
            inDegree[a[i]] --;

    // 如果入度为0
    for (int i = 0; i < n; i++)
        if (!inDegree[a[i]] && !vis[a[i]])
            dfs(a[i], cnt + 1);

    // 回溯
    for (int i = 0; i < n; i++)
        if (!vis[a[i]] && dir[z][a[i]])
            inDegree[a[i]] ++;

    // 标记为未访问
    vis[z] = 0;
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

//    ios::sync_with_stdio(false);
//    cin.tie(nullptr), cout.tie(nullptr);

    char s[100];
    while (gets(s) != NULL)// gets不安全
    {
        // 初始化
        memset(&dir, 0, sizeof dir);
        memset(&vis, 0, sizeof vis);
        memset(&inDegree, 0, sizeof inDegree);
        int len = strlen(s);
        n = 0;

        // 存字母到a[]
        for (int i = 0; i < len; i++)
            if (s[i] >= 'a' && s[i] <= 'z')
                a[n++] = s[i] - 'a';

        sort(a, a + n);// 对字母排序，输出字典序

        gets(s);
        len = strlen(s);
        bool first = 1;
        for (int i = 0; i < len; i++)// 处理先后关系
        {
            int st, ed;// 起点和终点
            if (first && s[i] >= 'a' && s[i] <= 'z')// 起点
            {
                first = 0;
                st = s[i] - 'a';// 转换为数字
                continue;
            }

            if (!first && s[i] >= 'a' && s[i] <= 'z')// 终点
            {
                first = 1;
                ed = s[i] - 'a';
                dir[st][ed] = 1;// 记录先后关系
                inDegree[ed] ++;// 记录入度
                continue;
            }
        }

        for (int i = 0; i < n; i++)
            if (!inDegree[a[i]])// 找到一个入度为0的点下手
                dfs(a[i], 0);
        cout << '\n';
    }
    return 0;
}


// http://poj.org/problem?id=1270