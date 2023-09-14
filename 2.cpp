#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, int> USI; // 为了后面方便定义
typedef queue<string> QS;

const int N = 6;

string a[N], b[N];
string A, B;
int n;

int expand(QS& q, USI& da, USI& db, string a[N], string b[N])
{
    string t = q.front(); // 取出队头元素
    q.pop();
    
    for (int i = 0; i < t.size(); i ++ ) // 在长度内
        for (int j = 0; j < n; j ++ )
            if (t.substr(i, a[j].size()) == a[j]) // 如果两部分相等
            {
                string st = t.substr(0, i) + b[j] + t.substr(i + a[j].size()); // 前面到从0开始，长度是i，加上规则中的，再加上后半部分
                if (da.count(st))   continue; // 如果做过，就跳过，算是一个剪枝优化吧
                if (db.count(st))   return da[t] + 1 + db[st]; // 值是从起点到当前的t点，加上到当前点的1，然后加上从终点走到当前点的距离
                da[st] = da[t] + 1; // 更新答案
                q.push(st);
            }
    return 11; // 如果无解就返回一个比10大的数就行
}

int bfs()
{
    QS qa, qb; // 定义两个队列，一个从起点开始，一个从终点开始
    USI da, db; // 用来判重，这是第一种写法
    
    qa.push(A), da[A] = 0; // 初始化起点，到起点的距离是0
    qb.push(B), db[B] = 0; // 初始化终点，到终点的距离是0
    
    while (qa.size() && qb.size()) // 两个队列中都有元素才会继续
    {
        int t;
        // 每次先扩展元素较少的
        if (qa.size() < qb.size())  t = expand(qa, da, db, a, b); // 运用规则
        else    t = expand(qb, db, da, b, a); // 如果是相反的，规则要反过来用
        
        if (t <= 10)    return t; // 在规定范围内就返回
    }
    
    return 11; // 如果无解返回一个比10大的数就好
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    cin >> A >> B;
    
    while (cin >> a[n] >> b[n])   n ++; // 由于输入个数不确定所以用这种方法输入
    
    if (A == B) // 在AcWing上需要特判
    {
        puts("0");
        return 0;
    }
    
    int step = bfs();
    
    if (step > 10)  puts("NO ANSWER!"); // 题目中说了，只要多于10步即视为无解
    else    printf("%d\n", step);
    
    return 0;
}
