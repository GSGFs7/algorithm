#include <bits/stdc++.h>
using namespace std;

/// 双向广搜
/*
 * 同时从起点和终点开始进行广度优先搜索
 *
 * 对于网格图而言改善并不明显
 * 对于树状图而言优势巨大
 *
 * 实现方法
 * 1.合用一个队列，正反BFS交替进行
 * 2.分成两个队列，分成两个不平衡的情况，让子状态少的BFS先扩展，多的后扩展
 *
 * 注意，每次扩展一个点的算法可能会出错，要一次扩展一层
 * */

const int N = 1e4;
int vis[N];     // 从前还是从后到达这个点的
int step[N];    // 到达这个点所花费的时间

struct Node{
    int step;   // 花费的时间
    int team;   // 从前还时从后开始
    int val[4]; // 分开的四个数
    int res;    // 合并的四个树
}node[N];

// 拆分为四个数
void getVal(Node *a)
{
    int res = a->res;
    for (int i = 3; i >= 0; i--)
        a->val[i] = res % 10, res /= 10;
}

// 合并四个数
void getRes(Node *a)
{
    int res = 0;
    for (int const i : a->val)
        res = res * 10 + i;
    a->res = res;
}

void debug(Node a)
{
    cout << "步数：" << a.step << ' ' << step[a.res] << '\n';
    cout << "值：" << a.res << '\n';
    cout << "team:" << a.team << '\n';
    for (auto i : a.val) cout << i; cout << '\n';
}

void BFS(int a, int b)
{
    queue<Node> q;
    Node s, t;  // 头和尾

    // 初始化
    s.res = a; s.team = 1; s.step = 0;
    getVal(&s);
    q.push(s);

    t.res = b; t.team = 2; t.step = 0;
    getVal(&t);
    q.push(t);

    while (!q.empty())
    {
        // 取出队头，记得弹出
        Node const front = q.front();
        q.pop();

        // 四个位置加一
        for (int i = 0; i < 4; i++)
        {
            Node now = front;
            now.step ++;
            if (now.val[i] == 9) now.val[i] = 1;// 看是否会超过一位数，1到9！！！！又卡了半个晚上
            else now.val[i] ++;
            getRes(&now);

            if (vis[now.res] == now.team) continue;
            if (!vis[now.res]) vis[now.res] = now.team, step[now.res] = now.step, q.push(now);
            else return cout << step[now.res] + now.step << '\n', void();
        }

        // 四个位置减一
        for (int i = 0; i < 4; i++)
        {
            Node now = front;
            now.step ++;
            if (now.val[i] == 1) now.val[i] = 9;// 看是否会变成负数，范围只有1到9！！！
            else now.val[i] --;
            getRes(&now);

            if (vis[now.res] == now.team) continue;
            if (!vis[now.res]) vis[now.res] = now.team, step[now.res] = now.step, q.push(now);
            else return cout << step[now.res] + now.step << '\n', void();
        }

        // 四个位置交换
        for (int i = 1; i < 4; i++)
        {
            Node now = front;
            now.step ++;// 漏了这个卡了半个晚上
            swap(now.val[i - 1], now.val[i]);
            getRes(&now);

            if (vis[now.res] == now.team) continue;
            if (!vis[now.res]) vis[now.res] = now.team, step[now.res] = now.step, q.push(now);
            else return cout << step[now.res] + now.step << '\n', void();
        }
    }
}

void solve()
{
    int a, b;
    cin >> a >> b;

    // 初始化
    memset(&vis, 0, sizeof vis);
    vis[a] = 1, vis[b] = 2;

    BFS(a, b);
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// 花了两个晚上总算是A了
// https://acm.hdu.edu.cn/showproblem.php?pid=1195