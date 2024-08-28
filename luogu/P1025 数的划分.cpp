#include <iostream>
using namespace std;

// 类模板题，直接dfs加剪枝

int n, k;
int ans = 0;

void dfs(int cur, int sum, int last)
{
    // cur层数，sum和，last最后一个数
    if (cur == k)
    {
        if (sum == n) ans++;// 在最后一层中符合条件的
        return;// 全部return，回到上一层继续搜索
    }

    for (int i = last; sum + i * (k - cur) <= n; i++) dfs(cur + 1, sum + i, i);// 剪枝
    // 去重，按从大到小排列，后一个数必定不小于前一个数
    // 如果无法将层数排满直接return
}

int main()
{
    cin >> n >> k;

    dfs(0, 0 ,1);// 不能等于一

    cout << ans;
    return 0;
}


// https://www.luogu.com.cn/problem/P1025