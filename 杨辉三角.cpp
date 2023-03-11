#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	int a[20][20];//假设为最大20*20的二维数组
	scanf("%d", &n);
	//赋初始值，数组最左和最右都为1
	for (int i = 0; i < n; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	//相加运算
	for (int i = 2; i < n; i++)//定义i表示行
	{
		for (int j = 1; j < i; j++)//定义j表示i行中的第j+1个
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];//每个数都等于上面一行(i-1行)的左边一个(j-1)加正上方的那个(j)
		}
	}
	//输出每个要求的数
	for (int i = 0; i < n; i++)//输出n行
		{
			for(int j=0;j<=i;j++)//输出n个
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");//换行
		}
	return 0;
}