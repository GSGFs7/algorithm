#include <bits/stdc++.h>
using namespace std;

int a[1010], b[1010];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) b[i] = abs(a[i] - a[i+1]);// Ԥ�������ֵ
    sort(b, b+n);
    // �˶Ծ���ֵ
    for (int i = 1; i < n; i++) {
        if (b[i] != i) {
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}

// ���ֵ���
// https://www.luogu.com.cn/problem/P1152