#include <bits/stdc++.h>

/*
    给出一棵二叉树树, 问他最深也子节点的最近公共祖先

    首先, 按照常规思路, 需要找出所有的也子节点, 再根据叶子节点求最近公共祖先,
    但是叶子节点可能有很多个, 直接暴力求有点不现实 按照官方题解的写法, 先搜到底,
    然后带着最大的深度向上回溯, 回溯的过程中只需要每次选择最大的深度向上传递即可.
    (如果途中两个节点的深度一样大, 就表明这个点是lca节点, 返回现在的节点即可)
 */

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<TreeNode *, int> run(TreeNode *u) {
        if (!u) return {u, 0};

        auto left = run(u->left);
        auto right = run(u->right);

        if (left.second > right.second) return {left.first, left.second + 1};
        if (left.second < right.second) return {right.first, right.second + 1};

        return {u, left.second + 1};
    }


    TreeNode *lcaDeepestLeaves(TreeNode *root) { return run(root).first; }
};

int tree[] = {0, 3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
int len = 12;

TreeNode *build(int u) {
    TreeNode *now = new TreeNode(tree[u]);

    int next = u << 1;

    if (next >= len) return now;
    now->left = tree[next] == -1 ? nullptr : build(next);

    if (next + 1 >= len) return now;
    now->right = tree[next + 1] == -1 ? nullptr : build(next + 1);

    return now;
}

void next_node(TreeNode *node) {
    cout << node->val << '\n';
    if (node->left) {
        next_node(node->left);
    } else {
        cout << nullptr << '\n';
    }
    if (node->right) {
        next_node(node->right);
    } else {
        cout << nullptr << '\n';
    }
}

void solve() {
    TreeNode *root = build(1);
    // next_node(root);
    Solution s;
    TreeNode *ans = s.lcaDeepestLeaves(root);
    cout << ans->val << '\n';
    if (ans->right) cout << ans->left->val << ' ' << ans->right->val;
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
