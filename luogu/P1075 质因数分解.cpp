#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // ��������� ���� ��С������ ���� n
    for (int i = 2; i < n/2; i++)
    {
        if (n % i == 0)
        {
            cout << n/i;
            break;
        }
    }
    return 0;
}

// https://www.luogu.com.cn/problem/P1075