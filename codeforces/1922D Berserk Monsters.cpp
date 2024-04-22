#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define int long long

/*
 * 题目描述:
 *  有n个怪物, 如果怪物活着就会向两边还活着的附加a[i]的伤害, 如果怪受到的伤害大于d[i]就会噶, 输出n个回合中每个回合噶掉的怪的数量
 * 输入:
 *  第一行一个整数n, 表示怪物数量
 *  第二行n个整数a[i], 表示每个怪物造成的附加伤害
 *  第三行n个整数d[i], 表示每个怪物受到的伤害阈值
 * 输出:
 *  n个整数, 表示n个回合中每个回合噶掉的怪的数量
 *
 * 思路:
 *  双向链表, 每次遍历双向链表, 判断当前怪物受到的伤害是否大于d[i], 如果是则删掉这个点, 否则向两边继续更新伤害
 *  双向链表判断一轮中是否噶掉的时间复杂度是O(n)
 *  总时间复杂度是O(n^2), n的数据范围在3e5, 会炸
 * 优化:
 *  因为如果两边的怪不噶的话中间这个怪也是不会发生任何变化的
 *  所以, 每次更新时只需要更新发生变化的点的两边即可, 与就是只需要对这个回合噶了的怪为目标进行更新
 *  这样每个怪就只会扫描两次(大概), 瞬间变成了O(n)级
 * */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), d(n);
    for (auto& i : a) cin >> i;
    for (auto& i : d) cin >> i;

    // 初始化双向指针
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        l[i] = i - 1;
        r[i] = i + 1;
    }

    // 计算受到的伤害
    auto dm= [&](int x)->int {
        int res = 0;
        if (l[x] != -1) res += a[l[x]];
        if (r[x] != n) res += a[r[x]];
        return res;
    };

    // 第一轮，每次都全扫会炸，只需要一轮就够了
    vector<int> die;
    for (int j = 0; j < n; j++) {
        int res = dm(j);
        if (res > d[j]) die.push_back(j);
    }

    // 数据范围3e5，一遍一遍扫肯定会炸
    // 因为如果两边的数不发生变化的话这个数也就不会被杀死，只要更新旁边发生变化的数即可
    vector<bool> vis(n, false);// vis表示这个怪已经噶了
    for (int i = 0; i < n; i++) {// 进行n轮
        set<int> s;// set里存放要更新的数
        for (auto j : die) {
            vis[j] = true;// 标记为已经噶了，下次直接跳过

            /// 更新l和r
            // 1 2 3，将3的左边改成原本2的左边，也就是1
            if (r[j] != n) l[r[j]] = l[j];
            // 1 2 3，将1的右边改成原本2的右边，与就是3
            if (l[j] != -1) r[l[j]] = r[j];
            // 一下左一下右，debug最费力的一集（事实上，雀食）

            // 如果没有越界就加入堆中
            if (0 <= l[j] && l[j] < n) s.insert(l[j]);
            if (0 <= r[j] && r[j] < n) s.insert(r[j]);
        }
        cout << die.size() << ' ';
        die.clear();

        // 新噶的怪
        for (auto j : s) {// 直接从需要更新的值里面取
            if (vis[j]) continue;// 如果已经噶了
            if (dm(j) > d[j]) die.push_back(j);
        }
    }
    cout << '\n';
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1922/problem/D
// 249ms 27744KB  越改花的时间越多了