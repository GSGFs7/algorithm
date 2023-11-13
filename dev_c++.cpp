#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

string s;
int t,h,su,n,m,a[30][30],f[30],q[30],r[91];

void tp(int x)  //拓扑
{ 
	 for (int i=1;i<=n;i++)
	 	if (a[x][i]==1&&r[i]>0)  //x指向i，且i入度不为0
	 	{
	 	    r[i]--;  //入度减1
	 	    f[i]=max(f[i],f[x]+1);  //更新最长链的长度
	 	    su=max(su,f[i]);   //更新最长链的最大长度
			if (r[i]==0)  //入度为0，入队
			   q[++t]=i;
	 	}
}

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{ 
		int p=1;
	    cin>>s; 
		int x=s[0]-'A'+1;
		int y=s[2]-'A'+1;
		a[x][y]=1;// 邻接矩阵

		// 如果存在矛盾
		if (x==y)
		{
			printf("Inconsistency found after %d relations.",i);
	        return 0;
		}

		memset(r,0,sizeof(r));  //清0
		for (int j=1;j<=n;j++)
		{
		    f[j]=1;  //最长链数组赋初值
		    for (int k=1;k<=n;k++)
		        r[k]+=a[j][k];  //统计入度
		}

		// 找到入度为0的值
		su=0,t=0;
	    for (int j=1;j<=n;j++)
	        if (!r[j])  //入度为0，入队
	        	q[++t]=j;
	    
		// 拓扑排序
		h=0;
	    while (h<t)
	    { 
	    	  h++;
	          tp(q[h]);
	    }

		// 
	    if (su==n)  //得到一个稳定的拓扑序
	    {
	    	printf("Sorted sequence determined after %d relations: ",i);
	    	for (int j=1;j<=n;j++)
	    	    printf("%c",q[j]+64);  //输出队列
	    	cout<<".";
	    	return 0;
	    }

	    for (int j=1;j<=n;j++)  
	        if (r[j]) p=0; //如果有入度不为0，标记
	    
		if (!p)  //第二种情况
	    {
	    	printf("Inconsistency found after %d relations.",i);
	        return 0;
	    }
	}
	printf("Sorted sequence cannot be determined.");  //前两者皆不是
	return 0;
}