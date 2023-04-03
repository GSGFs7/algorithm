#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int MAX=2161;
struct bignum
{
    int num[MAX];

    bignum & operator = (const char*);
    bignum & operator = (int);
    bignum();
    bignum(int);

    bool operator > (const bignum &) const;
    bool operator < (const bignum &) const;
    bool operator <= (const bignum &) const;
    bool operator >= (const bignum &) const;
    bool operator != (const bignum &) const;
    bool operator == (const bignum &) const;

    bignum operator + (const bignum &) const;
    bignum operator - (const bignum &) const;
    bignum operator * (const bignum &) const;
    bignum operator / (const bignum &) const;
    bignum operator % (const bignum &) const;

    bignum & operator += (const bignum &);
    bignum & operator -= (const bignum &);
    bignum & operator *= (const bignum &);
    bignum & operator /= (const bignum &);
    bignum & operator %= (const bignum &);
};
bignum & bignum::operator = (const char*c)
{
    memset(num,0,sizeof(num));
    int n=strlen(c),j=1,k=1,i;
    for(i=1;i<=n;i++)
    {
        if(k==10000)
        {
            j++;
            k=1;
        }
        num[j]+=k*(c[n-i]-'0');
        k*=10;
    }
    num[0]=j;
    return *this;
}
bignum & bignum::operator = (int a)
{
    char s[MAX];
    sprintf(s,"%d",a);
    return *this=s;
}
bignum::bignum()
{
    memset(num,0,sizeof(num));
    num[0]=1;
}
bignum::bignum(int n)
{
    *this=n;
}
bool bignum::operator > (const bignum &b) const
{
    int i;
    if(num[0]!=b.num[0])
        return num[0]>b.num[0];
    for(i=num[0];i>=1;i--)
        if(num[i]!=b.num[i])
            return (num[i]>b.num[i]);
    return false;
}
bool bignum::operator < (const bignum & b) const
{
    return b>*this;
}
bool bignum::operator <= (const bignum & b) const
{
    return !(*this>b);
}
bool bignum::operator >= (const bignum & b) const
{
    return !(b>*this);
}
bool bignum::operator != (const bignum & b) const
{
    return (b>*this||*this>b);
}
bool bignum::operator == (const bignum & b) const
{
    return !(b>*this)&&!(*this>b);
}
bignum bignum::operator + (const bignum &b) const
{
    bignum c;
    int i;
    c.num[0]=max(num[0],b.num[0]);
    for(i=1;i<=c.num[0];i++)
    {
        c.num[i]+=num[i]+b.num[i];
        if(c.num[i]>=10000)
        {
            c.num[i]-=10000;
            c.num[i+1]++;
        }
    }
    if(c.num[c.num[0]+1]>0)
        c.num[0]++;
    return c;
}
bignum bignum::operator - (const bignum &b) const
{
    bignum c;
    int i;
    c.num[0]=num[0];
    for(i=1;i<=c.num[0];i++)
    {
        c.num[i]+=num[i]-b.num[i];
        if(c.num[i]<0)
        {
            c.num[i]+=10000;
            c.num[i+1]--;
        }
    }
    while(c.num[c.num[0]]==0&&c.num[0]>1)
        c.num[0]--;
    return c;
}
bignum & bignum::operator += (const bignum &b)
{
    return *this=*this+b;
}
bignum & bignum::operator -= (const bignum &b)
{
    return *this=*this-b;
}
bignum bignum::operator * (const bignum &b) const
{
    bignum c;
    int i,j;
    c.num[0]=num[0]+b.num[0]+1;
    for(i=1;i<=num[0];i++)
    {
        for(j=1;j<=b.num[0];j++)
        {
            c.num[i+j-1]+=num[i]*b.num[j];
            c.num[i+j]+=c.num[i+j-1]/10000;
            c.num[i+j-1]%=10000;
        }
    }
    while(c.num[c.num[0]]==0&&c.num[0]>1)
        c.num[0]--;
    return c;
}
bignum & bignum::operator *= (const bignum &b)
{
    return *this=*this*b;
}
bignum bignum::operator / (const bignum &b) const
{
    bignum c,d;
    int i;
    c.num[0]=num[0]+b.num[0]+1;
    d.num[0]=0;
    for(i=num[0];i>=1;i--)
    {
        memmove(d.num+2,d.num+1,sizeof(d.num)-sizeof(int)*2);
        d.num[0]++;
        d.num[1]=num[i];
        while(d>=b)
        {
            d-=b;
            c.num[i]++;
        }
    }
    while(c.num[c.num[0]]==0&&c.num[0]>1)
        c.num[0]--;
    return c;
}
bignum bignum::operator % (const bignum &b) const
{
    bignum c,d;
    int i;
    c.num[0]=num[0]+b.num[0]+1;
    d.num[0]=0;
    for(i=num[0];i>=1;i--)
    {
        memmove(d.num+2,d.num+1,sizeof(d.num)-sizeof(int)*2);
        d.num[0]++;
        d.num[1]=num[i];
        while(d>=b)
            d-=b;
    }
    return d;
}
bignum & bignum::operator /= (const bignum &b)
{
    return *this=*this/b;
}
bignum & bignum::operator %= (const bignum &b)
{
    return *this=*this%b;
}
ostream & operator << (ostream & o,bignum &n)
{
    int i;
    o<<n.num[n.num[0]];
    for(i=n.num[0]-1;i>=1;i--)
    {
        o.width(4);
        o.fill('0');
        o<<n.num[i];
    }
    return o;
}
istream & operator >> (istream & in,bignum &n)
{
    char s[MAX];
    in>>s;
    n=s;
    return in;
}

signed main()
{
    bignum a,b,c;
    cin>>a>>b;
    c=a/b;
    cout<<c;
    return 0;
}