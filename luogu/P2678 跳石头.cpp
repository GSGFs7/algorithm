#include <iostream>
using namespace std;

/*
 * 将去除石头转化为枚举答案检查是否有足够的元素符合
 * 利用二分在答案的范围内枚举
 * check函数检测存在多少个石头需要移除
 * */

const int N = 1e5 + 10;
int a[N];
int l, n, m;

bool check(int dist)// 判断有多少个石头在dist的条件下需要移走
{
    // last是上一个未被删除数
    int last = 0, cnt = 0;
    for (int i = 0; i < n; i ++)
        if (a[i] - last < dist) cnt ++;
        else last = a[i];
    if (l - last < dist) cnt ++;// 别漏了最后的终点
    return cnt <= m;// 如果符合条件
}

int main()
{
    cin >> l >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int i = 0, j = l + 1;
    while (i < j)
    {
        int const mid = (i + j + 1) >> 1;
        if (check(mid)) i = mid;// 如果小于等于继续向后查找
        else j = mid - 1;
    }
    cout << j << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P2678