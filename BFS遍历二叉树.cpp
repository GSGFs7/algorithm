#include <iostream>
#include <queue>
using namespace std;

/*
 * BFS遍历二叉树（静态版）
 * 需要遍历每一条边 时间复杂度O(m)       （其实和O(n)差不多，毕竟是二叉树）
 * 共有n个点 空间复杂度O(n)
 * */

const int N = 1e5 + 10;
int index = 1;// 二叉树的下标

struct Node{
    char value;
    int lson, rson;
}tree[N];// 二叉树的0号节点不用，0的下标就表示空节点

int newNode(char val) {// 返回值为下标
    tree[index].value = val;
    tree[index].lson = 0;// 暂时还是空节点
    tree[index].rson = 0;
    return index ++;
}

void Insert(int &father, int child, bool l_r) {// l_r 表示左边或者右边0为左，1为右
    if (l_r) tree[father].rson = child;
    else tree[father].lson = child;
}

int buildTree() {
    int A = newNode('A'), B = newNode('B'), C = newNode('C'), D = newNode('D');
    int E = newNode('E'), F = newNode('F'), G = newNode('G'), H = newNode('H'), I = newNode('I');
    Insert(E, B, false), Insert(E, G, true);
    Insert(B, D, false), Insert(B, A, true);
    Insert(G, F, false), Insert(G, I, true);
    Insert(D, C, false), Insert(I, H, false);
    int const root = E;
    return root;
}

int main() {
    int const root = buildTree();
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int const temp = q.front();
        cout << tree[temp].value << ' ';
        q.pop();
        if (tree[temp].lson) q.emplace(tree[temp].lson);
        if (tree[temp].rson) q.emplace(tree[temp].rson);
    }
    return 0;
}