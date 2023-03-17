/*
 * 开放寻址法
 * 1.添加一个数：从第k位开始依次遍历，直到找到一个空位置
 * 2.查找：从第k位开始查找
 * 3.删除：查找x并标记
 *
 * 数组一般开两到三倍
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;// 0x3f3f3f3f是一个相当大的值 为10的9次方级
int h[N];

int find(int x)
{
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x)
    {
        k++;
        if (k == N) k = 0;
    }
    return k;
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(h, 0x3f, sizeof h);// 将每个字节赋值为0x3f，int占4字节即为0x3f3f3f3f
    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        int k = find(x);
        if (*op == 'I') h[k] = x;
        else
        {
            if (h[k] != null) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}