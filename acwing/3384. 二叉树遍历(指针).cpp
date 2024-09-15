#include <iostream>
using namespace std;

/*
 * 利用结构体和指针建立二叉树
 * */

struct Node// 用结构体表示一个完整的节点
{
    Node *l = nullptr;// 一个指向Node的指针，左孩子
    Node *r = nullptr;// 右孩子
    char val{};// 自身的值
};

// 利用先序建立二叉树
Node * build(Node * root)// 返回Node的指针
{
    char c;
    cin >> c;
    if (c == '#') return nullptr;

    root = new Node;// 新建一个节点
    root -> val = c;
    root -> l = build(root -> l);
    root -> r = build(root -> r);

    return root;
}

void inorder(Node * root)// 中序遍历
{
    if (root == nullptr) return ;

    inorder(root -> l);
    cout << root -> val << ' ';
    inorder(root -> r);
}

int main()
{
    Node * root = new Node;// 得到指针

    root = build(root);

    inorder(root);

    return 0;
}


// https://www.acwing.com/problem/content/3387/