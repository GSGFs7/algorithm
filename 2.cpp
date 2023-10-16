#include<bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=1e5+5;
typedef long long ll;
ll sum[maxn<<2];
void PushUP(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
 
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%lld",&sum[rt]);
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUP(rt);
}
void update(int L,int R,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]=sqrt(sum[rt]);
        return ;
    }
    if(L<=l&&R>=r&&sum[rt]==r-l+1)//如果区间内的所有数都是1则不必更新
        return;
    int m=(l+r)>>1;
    if(L<=m)
        update(L,R,lson);
    if(m<R)
        update(L,R,rson);
    PushUP(rt);
}
ll query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        return sum[rt];
    }
    int m=(l+r)>>1;
    ll ret=0;
    if(L<=m)
        ret+=(ret,query(L,R,lson));
    if(R>m)
        ret+=(ret,query(L,R,rson));
    return ret;
}
int main()
{
    int n,m,t=0;
    while(scanf("%d",&n)==1)
    {
        int a,b,c;
        build(1,n,1);
        scanf("%d",&m);
        printf("Case #%d:\n",++t);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(b>c) swap(b,c);
            if(a)
                printf("%lld\n",query(b,c,1,n,1));
            else
                update(b,c,1,n,1);
        }
        printf("\n");
    }
    return 0;
}