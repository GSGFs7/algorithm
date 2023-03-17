#include <bits/stdc++.h>
using namespace std;

// trie树，快速存储字符串集合的数据结构
// 一个字符串成一个链，如果重复就在重复的部分岔开
// 结尾处的字符做一个标记

const int N = 1e5 + 10;
int son[N][26], cnt[N], idx;// 下标是0的点，既是根节点，又是空节点
char str[N];

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)// c++中字符串末尾是\0
    {
        int u = str[i] - 'a';// 映射到0-25
        if (!son[p][u]) son[p][u] = ++idx;// 如果没有对应的儿子，就直接创建一个
        p = son[p][u];
    }
    cnt[p]++;// 标记这个节点，表示以该节点结尾的个数
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char op[2];
        cin >> op >> str;
        if (op[0] == 'I') insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}

/* 一维是结点总数，而结点和结点之间的关系（谁是谁儿子）存在第二个维度，比如[0][1]=3, [0]表示根节点，[1]表示它
 * 有一个儿子‘b’,这个儿子的下标是3；接着如果有一个[3][2]=8 ; 说明根节点的儿子‘b’也有一个儿子‘c’，这个孙子的下
 * 标就是8；这样传递下去，就是一个字符串。随便给一个结点][x][y], 并不能看出它在第几层，只能知道，它的儿子是谁。*/