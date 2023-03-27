#include <iostream>
#include <cstring>
using namespace std;

// 高度为2的n次方级
char a[1024][2048];

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int n;
    cin >> n;
    memset(a, ' ', sizeof a);// 格式化

    // 给出处理模板
    a[0][0] = a[1][1] = '/';
    a[0][1] = a[0][2] = '_';
    a[0][3] = a[1][2] = '\\';

    int length = 4, k = 1;// 初始长的度为4，高度为4/2，k用于计数（层数）
    while (k < n)// 不断复制给出的模板
    {
        for (int i = 0; i < length >> 1; i++)// 高度循环
            for (int j = 0; j < length; j++)// 长度循环
                // 复制到新位置
                // 向右四格，向下两格
                // 另一个额外向右两格/
                a[i+(length>>1)][j+(length>>1)] = a[i][j+length] = a[i][j];
        length = (length << 1), k++;// 下一层
    }
    // 处理完成的数组上大下小

    for (int i = (length >> 1) - 1; i >= 0; i--)// 倒序输出
    {
        for (int j = 0; j < length; j++)
            cout << a[i][j];
        cout << endl;
    }
    return 0;
}

// 模拟
// https://www.luogu.com.cn/problem/P1498