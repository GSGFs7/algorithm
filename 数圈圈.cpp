#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N];

int main()
{
    int b[10] = {1, 0, 0, 0,\
    1, 0, 1, 0, 2, 1};
    for (int i = 0; i < N; i++)// Ԥ��������
    {
        // �ҵ�����һ���������������ȦȦ��Ŀ���뵽���飬 ��60Ϊ2
        int k = i, cnt = 0;
        while (k)
        {
            cnt += b[k % 10];
            k /= 10;
        }
        a[i] = cnt;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int  cnt = 0;
        for (int i = l; i <= r; i++) cnt += a[i];// ȡ�÷�Χ�����е�ȦȦ��
        cout << cnt << endl;
    }
}