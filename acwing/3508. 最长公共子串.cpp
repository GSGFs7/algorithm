#include <iostream>
#include <unordered_set>
#include <cstring>

using namespace std;

typedef unsigned long long ULL;

const int N = 20010, P = 131;

int n, m;
char str[N];
ULL p[N], h[N];

/// 得到子串的hash值
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
    // 用h与p（标准值）的差值进行hash
}

bool check(int mid)
{
    unordered_set<ULL> hash;// hash表
    // 存入所有的长度为mid的子串
    for (int i = 1; i + mid - 1 <= n; i ++ )
        hash.insert(get(i, i + mid - 1));

    // 查找第二个数组中的子串是否出现在hash表中
    for (int i = n + 1; i + mid - 1 <= n + m; i ++ )
        if (hash.count(get(i, i + mid - 1)))
            return true;

    return false;
}

int main()
{
    scanf("%s", str + 1);
    n = strlen(str + 1);
    scanf("%s", str + n + 1);
    m = strlen(str + n + 1);

    p[0] = 1;
    for (int i = 1; i <= n + m; i ++ )
    {
        p[i] = p[i - 1] * P;
        // 预处理p数组用于在hash中作为数的位置（长度？）的标志

        char c = str[i];
        if (isdigit(c))// 差异化标记相当于直接排除数字
        {
            if (i <= n) c = '#';
            else c = '$';
        }
        h[i] = h[i - 1] * P + c;// 记录，类似前缀和？
    }

    /// 二分查找
    int l = 0, r = min(n, m);
    while (l < r)
    {
        int const mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    printf("%d\n", r);

    return 0;
}