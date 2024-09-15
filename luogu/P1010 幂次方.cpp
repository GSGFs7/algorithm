#include <iostream>
using namespace std;

// 幂次方，依次输出一个数的最大2次幂相加的形式

void search(int x)
{
    int m = 1, cnt = 0;
    cout << 2;//每次搜索都是2的次方的结果

    while (x >= m)
        m *= 2, cnt++;
    cnt --;

    if (cnt == 0 || cnt == 2) cout << '(' << cnt << ')';// 1不用输出，0和2可以直接输出
    if (cnt >= 3) cout << '(', search(cnt), cout << ')';// 大于3的继续在括号内求幂次方
    if (x - m / 2) cout << '+', search(x - m / 2);// 如果还有余数
}

int main()
{
    int n;
    cin >> n;
    search(n);
    puts("");
    // main();
    return 0;
}


// https://www.luogu.com.cn/problem/P1010