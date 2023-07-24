#include <iostream>
#include <queue>

using namespace std;

void BFS(int n, int k)
{
    queue<pair<int, int> > q;
    q.push({n, 0});

    while (!q.empty())
    {
        int now = q.front().first;
        int step = q.front().second;
        q.pop();

        if (now == k) { cout << step << endl; return ; }
        if (now > k) q.push({now - 1, step + 1});// 如果想要减小就只能now-1
        if (now < k) q.push({now + 1, step + 1}), q.push({now * 2, step + 1}), q.push({now - 1, step + 1});
        // 当now小于k时，答案也可能经过 （now-1）* 2得到，所以即使小于也要加上now-1

        // debug
        // cout << "___________________" << endl;
        // cout << now << ' ' << step << endl;
    } 
}

int main()
{
    int n, k;
    cin >> n >> k;

    BFS(n, k);
    return 0;
}


// http://poj.org/problem?id=3278