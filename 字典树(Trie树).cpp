#include <bits/stdc++.h>

using namespace std;

/*
 * 给出N个字符串 对于第k个字符串 计算将s[k]变为 s[1]~s[k] 中任意一个的最小花费
 * */

const int INF = 1e9 + 7;
const int SZ = 26;

// T: string  K: char
template <typename T, typename K> struct Trie {
    struct Node {    // 树上的节点
        bool is_ending = false;
        int min_deep = INF;
        array<int, SZ> children{};
    };
    vector<Node> tree;

    // 构造函数初始化 向树中插入一个根节点
    Trie(K val) { tree.push_back(Node()); }

    // 返回与字符a的差值
    int cast(K val) {
        int ret = val - 'a';
        assert(ret < SZ and ret >= 0);    // 断言？
        return ret;
    }

    // 插入一个字符串 并返回插入字符串的最小成本
    int insert(const T &sequence) {
        int cur = 0;
        int ans = sequence.size();     // 成本
        int cost = sequence.size();    // 字符串还剩下多少
        for (int i = 0; i < (int)sequence.size(); i++) {
            K value = sequence[i];
            // 如果没有这个点 就新接出一条边
            if (tree[cur].children[cast(value)] == 0) {
                tree[cur].children[cast(value)] = (int)tree.size();
                tree.push_back(Node());
            }

            cur = tree[cur].children[cast(value)];
            cost--;
            ans = min(ans, cost + tree[cur].min_deep);
            tree[cur].min_deep = min(tree[cur].min_deep, cost);    // 到尾节点的距离
        }
        tree[cur].is_ending = true;
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    Trie<string, char> trie('a');
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << trie.insert(s) << '\n';
    }
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


// https://atcoder.jp/contests/abc377/tasks/abc377_g
// 2024-10-29
