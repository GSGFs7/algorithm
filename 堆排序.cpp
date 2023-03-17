/*
 * 手写一个堆
 *
 * 最基本的操作：
 * 1.插入一个数
 *  heap[++size] = x;up(size);
 * 2.求集合中的最小值
 *  heap[1]
 * 3.删除最小值
 *  heap[1] = heap[size];size--;down(1);
 * 4.删除任意一个元素
 *  heap[k] = heap[size];size--;down(k);up(k);
 * 5.修改任意一个元素
 *  heap[k] = k;down(k);up(k);
 *
 * 堆的本质：是一棵完全二叉树（除了最下面那层之外其他层都是满的）
 * 小根堆：每个点小于等于左右两个儿子（根节点为最小值）
 * 堆的存储：整棵树由一个一维数组存储，i的左儿子为2i，i的右儿子为2i+1
 * up:将节点上移
 * down:将节点下移
 */

// 依次输出堆顶

#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int h[N], size1;

void down(int u)
{
    int t = u;
    if (u*2 <= size1 && h[u*2] < h[t]) t = u*2;
    if (u*2+1 <= size1 && h[u*2+1] < h[t]) t = u*2+1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int u)
{
    while (u/2 && h[u/2] > h[u])
    {
        swap(h[u/2], h[u]);
        u /= 2;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> h[i];
    size1 = n;

    for (int i = n / 2; i; i--) down(i);

    while (m--)
    {
        cout << h[1];
        h[1] = h[size1];
        size1--;
        down(1);
    }
    return 0;
}