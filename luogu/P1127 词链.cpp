#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 欧拉图
 * 判断欧拉图所需要的条件（有向图）
 *  全图连通，可以使用并查集来判断
 *  除了起点和终点可以差一的度外，其他点必须相等
 * 
 * 给出几个字符串，将他们按照字典序首尾相接，如果不行就输出***
 *  把字符串看成边，首字母和尾字母看成点
 *  因为每个点只能经过一次，最后的结果是个欧拉图
 *  先判断是否符合欧拉图的条件，找出起点
 *  用DFS按照字典序暴搜，最后搜到的顺序就是结果
 * */

const int N = 1010, M = 26;
int f[N];           // 祖宗节点
bool st[N];         // 搜索是否经过这个点
bool used[M];       // 这个点是否出现过
int in[M], out[M];  // 入度和出度
vector<string> str; // 存边
vector<string> path;// 欧拉图的路径
int n;

int find(int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void dfs(int x, int cur)// x表示的是字母的编号
{
    if (cur == n)// 如果找到了一个完整的通路
    {
        for (int i = 0; i < n; i++)
        {
            cout << path[i];
            if (i != n - 1) cout << '.';
        }
        exit(0);
    }

    // 寻找下一个点
    for (int i = 0; i < n; i++)
        if (!st[i] && str[i].front() -'a' == x)
        {
            path.push_back(str[i]);
            st[i] = true;
            dfs(str[i].back() - 'a', cur + 1);
            st[i] = false;
            path.pop_back();
        }
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
        str.push_back(s);
    }

    // 字典序排序
    sort(str.begin(), str.end());

    // 判断图是否连通，判断图的连通性只能从点入手，WA4
    for (int i = 0; i < M; i++) f[i] = i;// 初始化点
    for (int i = 0; i < n; i++)
    {
        // 两个端点
        int const a = str[i].front() - 'a';
        int const b = str[i].back() - 'a';

        if (find(a) != find(b))
            f[find(a)] = find(b);// 合并两个点

        // 统计入度和出度
        in[b] ++;
        out[a] ++;

        used[a] = used[b] = true;// 这两个点标记为已使用
    }
    int cnt = 0;// 统计有多少个根节点（也就是不连通的图）
    for (int i = 0; i < M; i++)
        if (i == f[i] && used[i]) cnt ++;// 这个点必须被使用过才参与判断
    if (cnt > 1)
    {
        cout << "***\n";
        return 0;
    }

    // 判断是入度和出度是否相等
    int start = str[0].front() - 'a';// 起点，万一成环，start=0就会没有输出，这个初始值必须是出现过的 WA2
    cnt = 0;// 统计是否只有一个起点和一个终点
    for (int i = 0; i < M; i++)
    {
        int const k = abs(out[i] - in[i]);// 这个点的出入度差值

        if (k > 1)//欧拉图通过每条边一次，这个点不可能同时是两个点的起点或终点
        {
            cout << "***\n";
            return 0;
        }

        // debug
//        cout << k << '\n';

        if (k == 1)
        {
            cnt ++;
            // 如果出度比入度大1，那么这个点就是起点，另一个点就是终点
            if (out[i] - in[i] == 1)
                start = i;
        }
    }
    if (cnt != 0 && cnt != 2)// 如果既不是欧拉回路（环）又不是欧拉通路（链）
    {
        cout << "***\n";
        return 0;
    }

    dfs(start, 0);

//    cout << "***\n";// WA4 图可能不连通，导致DFS部分没有输出
    return 0;
}


// https://www.luogu.com.cn/problem/P1127