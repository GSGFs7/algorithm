#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);//读入数组

    while (q--)
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1;//右边少一个
        while (l < r) //求得左边界
        {
            int mid = l + r >> 1;  //mid = l + r >> 1
            if (a[mid] >= x) r = mid;  //闭区间
            else l = mid + 1;  //加
        }

        if (a[l] != x) printf("-1 -1\n");
        else
        {
            printf("%d ", l);
            l = 0, r = n - 1;
            while (l < r)     //求右边界
            {
                int mid = l + r + 1 >> 1;   //mid = l + r + 1 >> 1
                if (a[mid] <= x) l = mid;
                else r = mid - 1;    //减
            }
            printf("%d\n", l);
        }
    }
    return 0;
}

/*
 * 二分
 * 当l=mid时mid=l+r+1>>1   [mid,r] (true)
 * 当r=mid时mid=l+r>>1   [1,mid] (true)
 * */