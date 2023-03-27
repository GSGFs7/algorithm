/* DFS 深度优先搜索
 * BFS 宽度优先搜索
 *
 * 相同点：都像一棵树
 * 不同点：DFS会尽量深搜（走到尽头）
 *        BFS会逐层搜索
 * 数据结构：
 *     DFS:stack
 *     BFS:queue
 * 空间：
 *     DFS:O(h)
 *     BFS:O(2^h)
 * BFS:最短路
 * DFS:不具最短性
 * DFS:回溯，剪枝
 *
 * */
#include <iostream>
using namespace std;

const int N = 10;
int path[N];// 记录路径
bool st[N];// 判断是否重复
int n;

void dfs(int u)
{
    // u=0时为第一层，等于n-1时为最后一层
    if (u == n)// 如果搜索达到尽头，输出结果
    {
        for (int i = 0; i < n; i++) printf("%d ", path[i]);// 输出路径
        puts("");// 换行
        return;
    }

    for (int i = 1; i <= n; i++)// 从1开始，排到n
    {
        if (!st[i])// 找到一个没有被用过的数
        {
            path[u] = i;
            st[i] = true;// 使用标记，使用过的数标记为true
            dfs(u+1);// 搜索下一个
            // 回复
            // path[u] = 0;// 会被不断覆盖，不用回复
            st[i] = false;// 回复
            // 进出递归时修改状态
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}

// https://www.acwing.com/problem/content/844/
// DFS暴搜