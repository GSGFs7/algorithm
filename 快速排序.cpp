// 快速排序

/*
 * 1.确定分界点：q[l], q[(l+r)/2], q[r] 随机   *
 * 2.调整区间，将小于分界点的数放到左边，大于的放到右边
 * 3.递归处理左，右两端
 * */

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

void quick_sort(int a[], int l, int r)
{
    if (l >= r) return;
    // 判断边界
    int x = a[(l+r)/2], i = l - 1, j = r + 1;
    // x为分界点将i与j设定为初始左右两端的指针，保留原来的l和r用作数据两端的位置
    while (i < j)
    {
        do i++;while (a[i] < x);
        // 查找大于分界点的数
        do j--;while (a[j] > x);
        // 查找小于分界点的数
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        // 交换
    }
    // 将剩下的两部分再排序
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
    // 此处不是以mid为分界线，mid仅用于随机寻找一个点当分界点，排序完成后以i和j为分界点
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    quick_sort(a, 0, n-1);
    // 0是最左边的位置，n-1是最右边的位置
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}

/*
 * 递归实现：
 * 双指针从左右两端向中间靠拢
 * 如果l指针大于分界点，l停止，r指针向中间靠拢，如果r指针小于中间值，l与r对应的值交换
 * */


// 疑问：边界处理？