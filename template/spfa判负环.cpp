/*
 * 相较于Bellman-Ford算法
 * 用队列存储更新过的点
 * 只需再次循环更新过的点即可
 * 跟dijkstra很像
 * */

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n;    // 总点数
int m;
int h[N], w[N], e[N], ne[N], idx;    // 邻接表存储所有边
int dist[N];                         // 存储每个点到1号点的最短距离
bool st[N];                          // 存储每个点是否在队列中
int cnt[N];

// 添加路径
void add(int a, int b, int c) {    // 从a到b的距离为c
    e[idx] = b;                    // 指向的边
    w[idx] = c;                    // 距离
    ne[idx] = h[a];                //
    h[a] = idx++;
}

// 求1号点到n号点的最短路距离，如果从1号点无法走到n号点则返回-1
bool spfa() {
    queue<int> q;

    // 每个点都要枚举，1可能无法到达负环处
    for (int i = 1; i <= n; i++) {
        st[i] = true;
        q.push(i);
    }

    while (q.size()) {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)
                    return true;    // 有n个点，如果存在大于n+1条边那么就存在负环

                if (!st[j]) {    // 如果队列中已存在j，则不需要将j重复插入
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    if (spfa())
        puts("Yes");
    else
        puts("No");
    return 0;
}