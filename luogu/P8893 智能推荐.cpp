#include <iostream>
#include <queue>
#include <bitset>
using namespace std;

/*
 * 第一天给出k道题目，随后每天给出一道题
 * 做题必须遵循一定先后顺序
 *
 * 画出树状图比较容易理解
 * 后面的题可由前面的题加上1得到
 *
 * 题目描述：
 * 对于第i道题，如果有可能被推荐的话，就会有一个题目集合。当且仅当你把si中每一道题都做出来并且其中有一道题是当天做的，那么下一天就会推荐第i题。
 * 下一题必定为删边后入度为0的点
 * */

const int N = 5e3 + 10;
vector<int> edge[N];
bitset<N> st;
queue<pair<int, int>> q;
int n, k, p, d[N];

void topoSort()
{
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        if (!st[x.first]) continue;// 可能会插入已经做过的题
        if (x.first == k) cout << x.second << endl, exit(0);

        for (auto i : edge[x.first])// 同一天可以做任意道题，直接把能做的都做完
        {
            if (!-- d[i])
            {
                st[i] = true;
                q.emplace(i, x.second + 1);// 记录天数
            }
        }
    }
}

int main()
{
    cin >> n >> k >> p;
    // 第一天
    for (int i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        st[x] = true;// 标记该题已做
        q.emplace(x, 0);// 标记上天数
    }

    // 后面几天
    cin >> p;
    for(int i = 0; i < p; i++)
    {
        int x, v;
        cin >> x >> v;
        for (int j = 0; j < v; j++)
        {
            int y;
            cin >> y;
            edge[y].push_back(x);
            d[x] ++;// 入度
        }
    }

    topoSort();

    cout << -1 << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P8893