#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

/*
s[i] = a[1]+a[2]+...+a[i]			ǰi����֮��
sum[r]-sum[l] = a[l]+a[l+1]...+a[r] = s[r]-s[l]		ǰ׺��=ǰr����-ǰl����
*/

int main()
{
	int sum[100010];
	int n, m, temp;
	int l, r;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		sum[i] = sum[i - 1] + temp;//Ԥ����ǰ׺������
	}
	while (m--)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", (sum[r] - sum[l - 1]));//�����˵�
	}
	return 0;
}