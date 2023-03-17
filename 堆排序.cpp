/*
 * ��дһ����
 *
 * ������Ĳ�����
 * 1.����һ����
 *  heap[++size] = x;up(size);
 * 2.�󼯺��е���Сֵ
 *  heap[1]
 * 3.ɾ����Сֵ
 *  heap[1] = heap[size];size--;down(1);
 * 4.ɾ������һ��Ԫ��
 *  heap[k] = heap[size];size--;down(k);up(k);
 * 5.�޸�����һ��Ԫ��
 *  heap[k] = k;down(k);up(k);
 *
 * �ѵı��ʣ���һ����ȫ�������������������ǲ�֮�������㶼�����ģ�
 * С���ѣ�ÿ����С�ڵ��������������ӣ����ڵ�Ϊ��Сֵ��
 * �ѵĴ洢����������һ��һά����洢��i�������Ϊ2i��i���Ҷ���Ϊ2i+1
 * up:���ڵ�����
 * down:���ڵ�����
 */

// ��������Ѷ�

#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int h[N], size1;

void down(int u)
{
    int t = u;
    if (u*2 <= size1 && h[u*2] < h[t]) t = u*2;
    if (u*2+1 <= size1 && h[u*2+1] < h[t]) t = u*2+1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int u)
{
    while (u/2 && h[u/2] > h[u])
    {
        swap(h[u/2], h[u]);
        u /= 2;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> h[i];
    size1 = n;

    for (int i = n / 2; i; i--) down(i);

    while (m--)
    {
        cout << h[1];
        h[1] = h[size1];
        size1--;
        down(1);
    }
    return 0;
}