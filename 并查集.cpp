#include <iostream>
using namespace std;

// 并查集
// 1.将两个集合合并（近乎O(1)的复杂度）
// 2.询问两个元素是否在一个集合中

// 每个集合用一棵树来表示，树根的编号就是整个集合的编号，每个节点存储它的父节点，用p[x]表示
// 判断树根 if(p[x] == x)
// 求x的集合编号 while (p[x] != x) x = p[x];
// 合并两个集合 将一棵树直接插到另一棵树中 px是x集合的编号，py是y集合的编号。p[x] = y;

// 路径压缩：(求编号的优化)遍历路径之后直接将路径上的节点直接指向根节点(近乎O(1))    (还有按秩合并)

const int N = 1e5 + 10;
int p[N];

int find(int x) // 核心操作 返回x的祖宗节点 + 路径压缩
{
    if (p[x] != x) p[x] = find(p[x]);// 一步步向上查找，将返回值都设置成父节点
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) p[i] = i;// 初始化，将父节点都设置成自己，自己即是根节点

    while (m--)
    {
        char op[2];
        int a, b;
        cin >> op >> a >> b;// scanf("%c", op)会读入一些空格或者回车用scanf("%s", op)会过滤空格和回车

        if (op[0] == 'M') p[find(a)] = find(b);// 让a的根节点成为b根节点的一个子节点
        else
        {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}