#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int p[N], size1[N];// size表示每一个集合的大小，只有根节点的size有意义

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        size1[i] = 1;
    }

    while (m--)
    {
        char op[2];
        int a, b;
        cin >> op >> a >> b;

        if (op[0] == 'C')
        {
            cin >> a >> b;
            if (find(a) == find(b)) continue;
            size1[find(b)] += size1[find(a)];
            p[find(a)] = find(b);
        }
        else if (op[1] == '1')
        {
            cin >> a >> b;
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else
        {
            cin >> a;
            cout << size1[find(a)] << endl;
        }
    }
    return 0;
}


// 837.连通块中点的数量
// https://www.acwing.com/problem/content/839/

/* 第三场周赛
 * https://ac.nowcoder.com/acm/problem/16030
https://ac.nowcoder.com/acm/problem/14556
https://ac.nowcoder.com/acm/problem/19466
https://ac.nowcoder.com/acm/problem/14619
https://ac.nowcoder.com/acm/problem/22096
https://ac.nowcoder.com/acm/problem/22231
https://ac.nowcoder.com/acm/problem/22216
https://ac.nowcoder.com/acm/problem/21301*/