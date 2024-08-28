#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];

void quickSort(int a[], int l, int r)
{
    if (l >= r) return;

    int x = a[(l+r)/2], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    quickSort(a, l, j);
    quickSort(a, j+1, r);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    quickSort(a, 0, n-1);

    printf("%d", a[k-1]);
    return 0;
}

// 786. 第k个数
// https://www.acwing.com/problem/content/788/

// 快排的翻版