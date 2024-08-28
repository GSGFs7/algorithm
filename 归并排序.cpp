/*
 * 归并排序：
 * 1.确定分界点
 * 2.递归排序左右两端
 * 3.归并--合二为一  *
 * 
 * 稳定排序，顺序不变（没什么用）
 *
 * 时间复杂度：
 * 每一层需要遍历 O(n)
 * 每次都一分为二，共有log n层
 * 时间复杂度为n log n
 *
 * 主要思想：分解处理
 * */

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], temp[N];

void merge_sort(int a[], int l, int r)
{
    if (l >= r) return;// 递归终止

    // 分解
    int mid = (l + r) >> 1;// 向下取整

    // 分解成尽可能小的两部分
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    // 合并子问题
    int k = 0, i = l, j = mid + 1;// 初始化，分割成两部分
    while(i <= mid && j <= r)// 如果一边排完，另一边直接全部放到数组末尾
        if(a[i] <= a[j]) temp[k++] = a[i++];// 将两个区域内较小的依次数放入数组
        else temp[k++] = a[j++];// 同上
    while(i <= mid) temp[k++] = a[i++];// 将剩余的所有数补到数组最后
    while(j <= r) temp[k++] = a[j++];// 同上

    for (i = l, j = 0; i <= r; i++, j++) a[i] = temp[j];// 取出已经排序完成的数组，不取回可能会被新的临时数据覆盖
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    merge_sort(a, 0,  n - 1);

    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

// 快排可过，sort可过
// 787. 归并排序
// https://www.acwing.com/problem/content/789/