/*
 * 并查集：
 *  1.合并两个集合
 *  2.询问两个元素是否处于同一个集合   复杂度近乎O(1)
 *
 * 用树的形式维护所有集合
 * 每个集合的编号是根节点的编号
 * 每个点都存储其父节点的编号(p[x])，可以快速找到树根
 * 如果是树根的话 p[x]=x，找树根while(p[x]1=x)x=p[x];
 *  （这一步复杂度略高，优化：路径压缩，将所有的点都指向根节点，基本上是O(1)。还有按址合并，一般不用）
 * 合并集合，直接将根节点加入另一棵树的根节点下，加一条边 p[x]=y（y表示另一棵树的根节点）
 * */

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int p[N], cnt[N];// cnt[]表示每个集合的大小，只有根节点的cnt[]有意义

/// 查找树根
int find(int x)// 放回x的祖宗节点（树根）+路径压缩
{
    // 注意不是是p[x]=find(x)，不然会一直递归炸栈 （而且p[x]本来就是x的父节点，不用在赋值为他的父节点）
    if (p[x] != x) p[x] = find(p[x]);// 如果x不是父节点，就让他的父节点等于他的父节点的父节点
    // 路径压缩：因为这一步同时修改了p[x]为最后的根节点的结果，不断调用自身直到返回最终值（递归，函数的性质，主要体现在DFS中）
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;// 父节点初始化成自己
        cnt[i] = 1;// 每个集合的数量，初始只有自己
    }

    string op;
    while (m--)
    {
        int a, b;
        // 如果用scanf的话经量用%s读字符串，%c可能会读回车空格等奇奇怪怪的东西
        cin >> op;
        if (op[0] == 'C')
        {
            cin >> a >> b;
            if (find(a) == find(b)) continue;// 如果已经在同一个集合中不能在加上了，不然cnt偏大
            cnt[find(b)] += cnt[find(a)];// 合并数量
            p[find(a)] = find(b);// 插入a到b的根节点下，改变a的根节点的父节点
        }
        else if (op[1] == '1')
        {
            cin >> a >> b;
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}


// 连通块中点的数量
// https://www.acwing.com/problem/content/839/