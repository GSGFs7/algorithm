/*
 * 单链表：
 *   邻接表：
 *     主要功能：存储图和数
 *
 * 双链表：
 *   优化某些问题
 *
 * 常用：e[N]表示value(element) ne[N]表示next value指针
 *
 * 链表大概形似：
 *   head -> 0 -> 1 -> 2 -> -1
 *   头节点  a[0] a[1] a[2]   NULL   值
 *   指针  ne[0] ne[1] ne[2](=-1)    下一个位置
 *
 * 用数组模拟链表非常快
 * new操作特别慢
 * */

#include <iostream>
using namespace std;

// head 表示头节点下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 存储已经用到了那个点(index)
const int N = 1e5 + 10;
int head, e[N], ne[N], idx;

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

// 将x插入到头节点之后
void add_to_head(int x)
{
    e[idx] = x;  // 赋予一个新值
    ne[idx] = head;  // 相当于头节点的next指针，指向原来的第二个值
    head = idx;  // 头节点指向该点下标
    idx++;  // 后移一位
}

// 将x插入到k节点之后
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];  // k+1 下标的位置
    ne[k] = idx;
    idx++;
}

// 删除下标是k的指针
void remove(int k)
{
    ne[k] = ne[ne[k]];// 指向下一个节点的下一个，即跳过下一个节点直接指向下下个节点
}

int main()
{
    int m;
    int x, k;
    cin >> m;
    init();
    while (m--)
    {
        char op;
        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            if (!k) head = ne[head];
            else remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    return 0;
}

// https://www.acwing.com/problem/content/828/