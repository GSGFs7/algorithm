#include <iostream>
using namespace std;

struct s
{
    int a, b, c, s, i;
}s[310];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].a;
        cin >> s[i].b;
        cin >> s[i].c;
        s[i].s = s[i].a + s[i].b + s[i].c;
        s[i].i = i+1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i].s > s[j].s)
            {
                swap(s[i], s[j]);
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i].s == s[i+1].s)
        {
            if (s[i].a < s[i + 1].a)
            {
                swap(s[i], s[i + 1]);

            }
            continue;
        }
        if (s[i].s == s[i+1].s)
        {
            if (s[i].b < s[i+1].b)
            {
                swap(s[i], s[i+1]);

            }
            continue;
        }
        if (s[i].s == s[i+1].s)
        {
            if (s[i].c < s[i+1].c)
            {
                swap(s[i], s[i+1]);

            }
            continue;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << s[i].i << " ";
        cout << s[i].s << endl;
    }
    return 0;
}

// 构造体排序
/*
输入：
8
80 89 89
88 98 78
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98
输出：
8
80 89 89
88 98 78
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98
 未通过该案例，但可以ac？
 */