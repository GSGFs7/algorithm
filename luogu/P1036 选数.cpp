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

    for(int i = l; i < n; i++)
        dfs(m + 1, sum + a[i], i + 1);
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    dfs(0, 0, 0);

    cout << res;
    return 0;
}