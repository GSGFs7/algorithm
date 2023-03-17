// ��ϣ��
//
// �� -10��9��10��9�η� ӳ�䵽 0��10��5�η� ��
// 1.x mod 10��5�η�(ȡģ���������������������������ݾ�����Զ����ͻ�ĸ��ʸ�С)
// 2.�����ͻ
// ���㷨����һ�㲻��ɾ��Ԫ�أ���ͨ���������
// ������:��ԭ�е�������������������
//
//

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;// ʹk�ض�Ϊ����
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

    memset(h, -1, sizeof h); // �۵ĳ�ʼ��

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