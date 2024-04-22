#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;
#define int long long

/*
 给出一个数组, 可以进行两种操作, 删除一个数, 在一个数后面加上一个数

 思路:
    原本想的是链表+map辅助定位元素位置(单纯的链表会TLE, 因为查找是O(n)的)
    but, 改掉一个数之后迭代器就会错位, 指向前一个或是后一个值
    所以直接手搓了一个指针链表, debug的时间是写代码的好几倍
    以后再也不想写指针了...
*/ 

struct Node
{
    int val = 0;
    Node *l = nullptr;
    Node *r = nullptr;

    Node(int _val, Node *_l) {
        val = _val;
        l = _l;
    }
    Node(int _val) {
        val = _val;
    }
    Node(){}
};

void solve() {
    int n;
    cin >> n;
    Node *head = new Node;
    map<int, Node*> pos;// 每个元素在链表中的位置
    Node *last = head;    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        last->r = new Node(x, last);
        last = last->r;
        pos[x] = last;
    }// 正确代码

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 2) {// 删除
            int x;
            cin >> x;
            Node *node = pos[x];// 写外面, 不然每次都要O(logn)
            if (node->r != nullptr) {
                node->l->r = node->r;// 左节点的右指针指向右节点, 指针给我指麻了
                node->r->l = node->l;
                delete node;
            } else {
                node->l->r = nullptr;
                delete node;
            }
        } else {// 在x后插入y
            int x, y;
            cin >> x >> y;
            Node *newNode = new Node(y);
            Node *node = pos[x];
            if (node->r != nullptr) {// 右节点可能不存在, 竟然还有这茬事...
                newNode->l = node;
                newNode->r = node->r;
                node->r->l = newNode;
                node->r = newNode;
                pos[y] = newNode;// debug这么久结果才发现没加这个
            } else {
                node->r = newNode;
                newNode->l = node;
                pos[y] = newNode;
            }
        }
    }

    Node *idx = head;
    while (idx->r != nullptr) {
        idx = idx->r;
        cout << idx->val << ' ';
    }
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://atcoder.jp/contests/abc344/tasks/abc344_e
// 312ms 41272KB
// 2024年3月20日