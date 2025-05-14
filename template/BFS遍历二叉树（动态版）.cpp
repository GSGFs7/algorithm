#include <bits/stdc++.h>
using namespace std;

/*
 * new的操作很慢，不建议在比赛中使用
 * */

struct Node{
    char value;
    Node *l, *r;

    // 构造函数 用于赋值 这样写很方便
    Node(char value = '#', Node *l = NULL, Node *r = NULL) : value(value), l(l), r(r) {};
};

// 删除一棵树
void removeTree(Node *root) {
    if (root == NULL) return ;
    removeTree(root->l);// 递归删除
    removeTree(root->r);
    delete root;
}

int main() {
    Node *A, *B, *C, *D, *E, *F, *G, *H, *I;
    A = new Node('A'); B = new Node('B'); C = new Node('C');
    D = new Node('D'); E = new Node('E'); F = new Node('F');
    G = new Node('G'); H = new Node('H'); I = new Node('I');
    E->l = B; E->r = G; B->l = A; B->r = D;
    G->l = F; G->r = I; D->l = C; I->l = H;
    queue<Node> q;
    q.push(*E);
    while (!q.empty())
    {
        Node *temp = &q.front();
        cout << temp->value << ' ';
        q.pop();
        if (temp->l) q.push(*(temp->l));
        if (temp->r) q.push(*(temp->r));
    }
    removeTree(E);
    return 0;
}