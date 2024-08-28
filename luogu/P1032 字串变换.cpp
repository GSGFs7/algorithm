#include <bits/stdc++.h>
using namespace std;

/*
 * 一个字符串通过给出的规则变化成另一个字符串
 * 如果从头开始变化的化，时间复杂度可能是指数级的，需要进行双向BFS优化
 *
 * 注意：变化规则是单向的，而且无序在某些地方会被坑（在两个队列中先扩展小的的时候）
 * */

typedef queue<string> QS;
typedef unordered_map<string, int> Hash;
const int N = 6;
string A, B;// 起点和终点
string a[N], b[N];// 待匹配对应表
int cnt = 0;

int extend(QS &q, Hash &start, Hash &target, string in[], string out[])
{
    string const t = q.front();
    q.pop();

    for (int i = 0; i < cnt; i++)// 遍历对应表中所有的值
        for (int j = 0; j <= t.size(); j++)// 在原字符串上匹配
            if (t.substr(j, in[i].size()) == in[i])
            {
                string const s = t.substr(0, j) + out[i] + t.substr(j + in[i].size());// 组成新字符串
/*
                cout << t << '\n';
                cout << start[t] << ' ' << target[t] << '\n';
                cout << s << '\n';
                cout << '\n';
*/
                if (target[s]) return start[t] + target[s] + 1;// 如果两边都找到了这个点，返回答案
                if (start[s]) { start[s] = min(start[s], start[t] + 1); continue; }// 如果已经找过这个点就跳过

                start[s] = start[t] + 1;
                q.push(s);
            }
    return 11;
}

int BFS()
{
    QS qa, qb;
    Hash da, db;

    qa.push(A), qb.push(B);
    da[A] = db[B] = 0;

    int n = 0;
    while (!qa.empty() && !qb.empty())// 如果一边走到尽头就表示前后必定不会相交
    {
        int t;
        // 数据有坑
        // 按照顺序b会变成bb，因为还是只有一个数，再次从bb开始扩展，扩展为bbb，而第一个数据aaaaa直接变成bbb，就直接返回了
        // （最后一个规则有aaaaa变成bb的，最少只需要两步），所以两边同时扩展，终于是过了
        if (n++ % 2) t = extend(qa, da, db, a, b);// 先扩展小的数怎么都过不了，卡了三天
        else t = extend(qb, db, da, b, a);// 因为变换是单向的，所以从后开始的那部分需要反向
        if (t <= 10) return t;
    }
    return -1;
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> A >> B;
    while (cin >> a[cnt] >> b[cnt]) cnt ++;

    if (A == B) { puts("0"); return 0; }// 如果相同就直接输出0

    int const t = BFS();
    if (t == -1) puts("NO ANSWER!");
    else cout << t << '\n';

    return 0;
}


// https://www.acwing.com/problem/content/description/192/
// https://www.acwing.com/problem/content/description/192/