// 单调队列
#include <iostream>
using namespace std;

/*
 * 如果新入队的元素大于后面的元素
 * 那么后面所有的元素都会被这个新加入的元素压制
 * 队列后面的元素这时都可以被删掉
 * 如果小于那么直接加入
 * 每次运行都保证队尾到队头单调递减
 *
 * 这样很就能很快的求出区间内的极值
 * 时间复杂度O(n)
 *
 * 省流：队尾弹出，队尾加入，保证全队列单调
 * */

const int N = 100010;
int a[N], b[N], c[N][2];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    int tt = 0, hh = 1;// hh为头指针，tt为尾指针
    for (int i = 1; i <= n; i++) {
        for (; tt >= hh && b[i] >= c[tt][0]; tt--);// 把末尾值小的删掉，最少还会有一个
        c[++ tt][0] = b[i];// 队尾添加元素
        c[tt][1] = a[i];// 标记出队时间
        cout << c[hh][0] << endl;// 输出队列中的最大值
        for (; tt >= hh && c[hh][1] == i; ++hh);// 弹出队尾，将到时间的元素全部出队
    }
    return 0;
}