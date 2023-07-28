#include <bits/stdc++.h>
using namespace std;

/*
 * BFS+剪枝
 * 判重：利用剪枝避免重复计算，也是BFS中最常用的剪枝
 * 将0到8全排列可得到9!种不同的答案，如果不剪枝将会计算4^20
 * */

int main()
{
    string s1 = "012345678";
    queue<pair<string, int>> q;
    q.push({s1, 0});

    map<string, bool> vis;

    while (!q.empty())
    {
        auto s = q.front().first;
        auto step = q.front().second;
        q.pop();

        // 判断是否得到答案
        if (s == "876543210")
        {
            cout << step << endl;
            exit(0);
        }

        int i = 0;
        for (; i < 10; i++)
            if (s[i] == '0') break;

        for (int j = i - 2; j <= i + 2; j++)
        {
            int k = (j + 9) % 9;// 相当于一个回环，妙啊
            if (k == i) continue;// 当前状态

            // 交换
            string news = s;
            char temp = news[i];
            news[i] = news[k];
            news[k] = temp;

            if (!vis[news])
            {
                vis[news] = true;
                q.push({news, step + 1});
            }
        }
    }
}


// 《算法竞赛》中的解 985ms 30388kb
// https://www.lanqiao.cn/problems/642/learning/