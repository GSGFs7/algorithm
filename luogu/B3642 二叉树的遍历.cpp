#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

struct Node {
    int value;
    int l, r;
}tree[N];

void preorder(int father)
{
    if (!father) return ;

    cout << father << ' ';
    preorder(tree[father].l);
    preorder(tree[father].r);
}

void inorder(int father)
{
    if (!father) return ;

    inorder(tree[father].l);
    cout << father << ' ';
    inorder(tree[father].r);
}

void postorder(int father)
{
    if (!father) return ;

    postorder(tree[father].l);
    postorder(tree[father].r);
    cout << father << ' ';
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1, l, r; i <= n; i++)
    {
        cin >> l >> r;
        tree[i].l = l;
        tree[i].r = r;
    }

    preorder(1);
    cout << endl;
    inorder(1);
    cout << endl;
    postorder(1);
    cout << endl;
    return 0;
}


// https://www.luogu.com.cn/record/116410509