#include <iostream>
#define int long long int
using namespace std;

/*
 * 记忆化
 * 将每次的答案存储到数组中
 * 下次要以该点为中间过程时可直接调用
 * 无需再次从头开始计算
 * */

const int N = 22;
int a, b, c;
int p[N][N][N];// 存储每次的结果
bool vis[N][N][N];// 是否计算过

// 题目要求的函数
int w(int x, int y, int z)
{
    if (x <= 0 || y <= 0 || z <= 0) return 1;// 优先处理，避免数组越界
    else if (vis[x][y][z]) return p[x][y][z];
    else if (x > 20 || y > 20 || z > 20) p[x][y][z] = w(20, 20, 20);
    else if (x < y && y < z) p[x][y][z] = w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);// 记忆化
    else p[x][y][z] = w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);// 记忆化
    return vis[x][y][z] = true, p[x][y][z];
}

signed main()
{
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) exit(0);
        printf("w(%lld, %lld, %lld) = ", a, b, c);
        if (a > 20) a = 21;// 因为大于20的值返回20，所以所有大于20的值等价于21，可以缩小数组范围
        if (b > 20) b = 21;
        if (c > 20) c = 21;

        cout << w(a, b, c) << '\n';
    }
}


// https://www.luogu.com.cn/problem/P1464