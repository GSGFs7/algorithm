#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N];

int main()
{
    int b[10] = {1, 0, 0, 0,\
    1, 0, 1, 0, 2, 1};
    for (int i = 0; i < N; i++)// 预处理数组
    {
        // 找到其中一个数，将这个数的圈圈数目放入到数组， 如60为2
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
        for (int i = l; i <= r; i++) cnt += a[i];// 取得范围内所有的圈圈数
        cout << cnt << endl;
    }
}