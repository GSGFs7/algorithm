#include <iostream>
using namespace std;

int main(void)
{
	int n = 10;
	int a[10] = { 5,8,1,3,0,9,2,4,6,7 };
	int temp = 0;//中转
	for (int i = 0; i < n - 1; i++)//有十个元素只需要进行九次排序即可
	{
		for (int j = 0; j < n-1-i; j++)//此处为n-1，避免下方a[j + 1]超出范围
		{//以及，n-1-i表示后方已经确定了i个数，这i个数不需要再次参与到循环比较中
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			//向右推较大的数
		}
		//经历一次循环后最右边出现了一个最大的数
	}
	//进行对应次数的循环即可完成排序
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
//同理可求出由大到小的排列