// 堆优化版
// 稀疏图
// 最大值变成mlogn
// 堆不正常修改任意一个元素
// 优先队列mlogm   logm <= logn^2 = 2logn
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> PII;// 需要pair存储序列

const int N = 1000010;
int n, m, idx = 0;
int h[N], w[N], e[N], ne[N];// 邻接表
int dist[N];
bool st[N];

// 添加路径
void add(int a, int b, int c)// 从a到b的距离为c
{
    e[idx] = b;// 指向的边
    w[idx] = c;// 距离
    ne[idx] = h[a];//
    h[a] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // vector表示利用vector实现
    priority_queue<PII, vector<PII>, greater<>> heap;// greater定义小根堆（默认为大根堆），还有less<>与之相反
    heap.emplace(0, 1);

    while (!heap.empty())
    {
        // 取出堆顶
        auto t = heap.top();
        heap.pop();

        // 找到一个没使用过的数，获得编号
        int ver = t.second;
        if (st[ver]) continue;// 跳过冗余备份
        st[ver] = true;

        // 利用该点更新其他的点
        for (int i = h[ver]; i != -1 ; i = ne[i])// 遍历临边
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])// 如果大于从t过来的距离，更新
            {
                dist[j] = dist[ver] + w[i];
                heap.emplace(dist[j], j);// 放入队列
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << dijkstra() << endl;
    return 0;
}