#include <iostream>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
int a[N];

int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[i] = a[i-1] + x;
        // ����ǰ׺��
    }

    if (a[n] % 3) puts("0");
    else
    {
        ll res = 0, cnt = 0;
        for (int j = 2; j < n;j++)
        {
            if (a[j-1] == a[n] / 3) cnt++;// ����ǰ�������֮һ��
            if (a[j] == a[n] / 3 * 2) res += cnt;// ���Һ��������֮һ�㣬���
        }
        cout << ("%lld\n", res);
    }
    return 0;
}

// 3956. �ض�����
// https://www.acwing.com/problem/content/3959/