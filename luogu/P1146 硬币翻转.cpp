#include <iostream>
using namespace std;

// 思维题
// 每次翻n-1相当于翻一个
// 如果对不上就取反

bool a[1000][1000000];

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    int n;
    cin >> n;
    cout << n << endl;

    // 每次翻一个，依次增多
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < i; j++)
            a[i][j] = true;

    // 按照要求输出
    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
        {
            for (int j = 0; j < n; j++) cout << !a[i][j];// 没有空格！！！
            cout << endl;
        }
        else
        {
            for (int j = 0; j < n; j++) cout << a[i][j];
            cout << endl;
        }
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P1146