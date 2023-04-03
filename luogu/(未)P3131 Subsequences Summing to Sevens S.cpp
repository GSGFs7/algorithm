#include <iostream>
using namespace std;

const int N = 5e4 + 10;
int a[N];
int first[7], last[7];// 第一次出现和最后一次出现的位置

int main()
{
    int n;
    cin >> n;

    /// 预处理前缀和之余
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] = (a[i-1] + a[i]) % 7;
    a[1] = a[1] % 7;

    /// 记录各余第一次出现的位置
    for (int i = n; i > 0; i--)
        first[a[i]] = i;

    /// 记录最后一次的位置
    for (int i = 1; i <= n; i++)
        last[a[i]] = i;

    /// 相减得出结果
    int ans = 0;
    for (int i = 0; i < 7; i++)
        if (last[i] != 0 && first[i] != 0)
            ans = max(last[i] - first[i], ans);
    // 特判，当模为0时左边界需要左移1位
    if (last[0] != 0 && first[0] != 0)
        ans = max(last[0] - first[0] + 1, ans);

    cout << ans << endl;
    //main();
    return 0;
}