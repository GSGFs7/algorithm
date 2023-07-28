#include <iostream>
#include <queue>
<<<<<<< HEAD

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
=======
#include <cstring>
using namespace std;

/*
 * 到达指定的位置所需的最小时间
 * 走：前后移动一格，传送：当前位置乘以二
 * 直接在范围内自己跑BFS，求出到每个点的最小值
 * */

const int N = 100010;
int a[2 * N];
int n, k;

void bfs()
{
    queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        int const now = q.front();
        q.pop();

        // 走路
        for (int i = -1; i < 2; i += 2)
        {
            int const xx = now + i;

            if (xx < 0 || xx > 2 * N - 1) continue;// 这个范围要开的特别大，不然会WA

            if (a[xx] > a[now] + 1)
            {
                a[xx] = a[now] + 1;
                q.push(xx);
            }
        }

        // 传送
        int const xx = now * 2;

        if (xx > 2 * k) continue;

        if (a[xx] > a[now] + 1)
        {
            a[xx] = a[now] + 1;
            q.push(xx);
        }
    }
>>>>>>> main
}

int main()
{
<<<<<<< HEAD
    int n, k;
    cin >> n >> k;

    BFS(n, k);
=======
    cin >> n >> k;

    memset(&a, 0x3f, sizeof a);
    a[n] = 0;
    bfs();

    cout << a[k] << endl;

    // debug
    //for (int i = 1; i <= 2 * k; i++) cout << i << ':' <<  a[i] << ' ';
>>>>>>> main
    return 0;
}


// http://poj.org/problem?id=3278