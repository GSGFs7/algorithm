#include <iostream>
using namespace std;

const int N = 100010;
int a[N], s[N];
// a是原数组，s是数组元素范围

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        s[a[i]] ++;
        // 第一层循环，写入次数到a[i]的值处，让后利用while查看是否重复
        while (s[a[i]] > 1)// 如果大于1，重新设置为1，并跳向下一个数
        {
            s[a[j]]--;
            j++;
            // j是第二遍筛查时用的将前面所有的数的计数消掉
        }
        // i全程大于j
        res = max(res, i - j + 1);
    }

    cout << res << endl;
    return 0;
}

// 799. 最长连续不重复子序列
// https://www.acwing.com/problem/content/801/

/*
 * 暴力：
 *  for (int i = 0; i < n; i++)//终点
 *      for (int j = 0; j < n; j++)//起点
 *          if (check(j, i))
 *          {
 *              res = max(res, i - j + 1);
 *          }
 *
 * 双指针算法:O(n)
 *  for (int i = 0, j = 0; i < n; i++)
 *  {
 *      while (j <= i && check(j, i)) j++;
 *      // 找到j的最右端
 *      res = max(res, i - j + 1);
 *  }
 */