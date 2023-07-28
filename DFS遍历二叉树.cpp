#include <bits/stdc++.h>
using namespace std;

/*
 * DFS遍历二叉树
 * */

const int N = 1e5 + 10;
int index = 1;
int dfn[N] = {0};// 表示该节点的时间戳
int dfn_timer = 0;
int visit_timer = 0;
int deep[N] = {0};
int deep_timer = 0;
int num[N] = {0};// 该点的子节点数

struct Node {
    char value;
    int lson, rson;
}tree[N];

int newTree(char val) {
    tree[index].value = val;
    tree[index].lson = 0;
    tree[index].rson = 0;
    return index ++;
}

void Insert(int &father, int child, int l_r) {
    if (l_r) tree[father].rson = child;
    else tree[father].lson = child;
}

void dfn_order(int father) {
    if (father == 0) return ;

    dfn[father] = ++ dfn_timer;
    printf("dfn[%c]=%d ", tree[father].value, dfn[father]);// 打印时间戳

    dfn_order(tree[father].lson);// DFS递归
    dfn_order(tree[father].rson);
}

void visit_order(int father) {
    if (!father) return ;

    printf("visit[%c]=%d ", tree[father].value, ++ visit_timer);

    visit_order(tree[father].lson);
    visit_order(tree[father].rson);

    printf("visit[%c]=%d ", tree[father].value, ++ visit_timer);// 再次回到这个节点
}

void deep_node(int father) {
    if (!father) return ;

    deep[father] = ++ deep_timer;
    printf("deep[%c]=%d ", tree[father].value, deep[father]);

    deep_node(tree[father].lson);
    deep_node(tree[father].rson);
    deep_timer --;
}

int num_node(int father) {
    if (!father) return 0;

    num[father] = num_node(tree[father].lson) + num_node(tree[father].rson) + 1;
    printf("num[%c]=%d ", tree[father].value, num[father]);
    return num[father];
}

/// 求先序序列
void preorder(int father) {
    if (!father) return ;

    cout << tree[father].value << ' ';
    preorder(tree[father].lson);
    preorder(tree[father].rson);
}

/// 求中序序列
void inorder(int father) {
    if (!father) return ;

    inorder(tree[father].lson);
    cout << tree[father].value << ' ';
    inorder(tree[father].rson);
}

/// 求后序序列
void postorder(int father) {
    if (!father) return ;

    postorder(tree[father].lson);
    postorder(tree[father].rson);
    cout << tree[father].value << ' ';
}

int buildTree() {
    int A = newTree('A'), B = newTree('B'), C = newTree('C');
    int D = newTree('D'), E = newTree('E'), F = newTree('F');
    int G = newTree('G'), H = newTree('H'), I = newTree('I');
    Insert(E, B, 0), Insert(E, G, 1);
    Insert(B, A, 0), Insert(B, D, 1);
    Insert(G, F, 0), Insert(G, I, 1);
    Insert(D, C, 0), Insert(I, H, 0);
    int const root = E;
    return root;
}

int main() {
    int root = buildTree();

    cout << "dfn order: ";
    dfn_order(root);
    cout << endl;

    cout << "visit order: ";
    visit_order(root);
    cout << endl;

    cout << "deep order: ";
    deep_node(root);
    cout << endl;

    cout << "num of tree: ";
    num_node(root);
    cout << endl;

    cout << "pre order: ";
    preorder(root);
    cout << endl;

    cout << "in order: ";
    inorder(root);
    cout << endl;

    cout << "post order: ";
    postorder(root);
    cout << endl;
    return 0;
}