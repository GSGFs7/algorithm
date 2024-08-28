#include <iostream>
using namespace std;

// 暴力出奇迹
int n,k;
int ans =0;

int main()
{
    scanf("%d %d",&n,&k);
    for (int i =0;i<=n;i++)
    {
        int temp = i;
        while(temp)
        {
            ans += (temp%10==k);
            temp /= 10;
        }
    }
    cout<<ans<<endl;
    return 0;
}