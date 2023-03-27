#include <iostream>

using namespace std;

int n,k;
int a[25];
long long res;

bool check(int z)// 检测是否为质数
{
    for(int i = 2; i < z; i++)
        if(!(z % i))
            return false;
    return true;
}

void dfs(int m, int sum, int l)
{
    // m为当前的个数
    // sum为元素和
    // l为数组元素下标
    if(m == k)
    {
        if(check(sum))
            res++;
        return ;
    }
    for(int i = l; i < n; i++)// 依次遍历每种可能
        dfs(m + 1, sum + a[i], i + 1);// 依次遍历下一个l，l之前的数都不参与，保证不重不漏
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0, 0, 0);
    cout << res;
    return 0;
}

// https://www.luogu.com.cn/problem/P1036