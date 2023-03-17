// 哈希表
//
// 将 -10的9到10的9次方 映射到 0到10的5次方 中
// 1.x mod 10的5次方(取模的数最好是质数并且离二的整次幂尽可能远，冲突的概率更小)
// 2.处理冲突
// 在算法题中一般不会删除元素，可通过标记屏蔽
// 拉链法:在原有的数组上拉其他的链表
//
//

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;// 使k必定为正数
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool Find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(h, -1, sizeof h); // 槽的初始化

    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (*op == 'I') insert(x);
        else
        {
            if (Find(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}