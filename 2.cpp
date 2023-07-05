#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010;
int a[N],s[N];

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);

        memcpy(s,a,sizeof a);//把a数组复制到s数组，用s数组得到排序后的结果
        sort(s+1,s+1+n);
        
        printf("Case #%d: ",t);
        for(int i=1;i<=n;i++)
        {
            //对每一个a[i]，用二分找到第一个大于2*a[i]的数或者最右侧的等于2*a[i]的数
            int l=1,r=n;
            while(l<r)
            {
                int mid=l+r>>1;
                if(s[mid]>2*a[i])r=mid;
                else l=mid+1;
            }

            if(s[r]>2*a[i])r--;//找到的数可能大于2倍的a[i]而不满足题意，向左移动以取得比二倍a[i]小的数
            if(a[i]==s[r])r--;//去除自身
            if(r!=0)printf("%d ",s[r]);
            else printf("-1 ");//r等于0表示对于a[i]没有数符合题意
        }
        printf("\n");
    }
    return 0;
}