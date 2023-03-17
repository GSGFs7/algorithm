#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], c[N];

int main()
{
	//读入
	string n1, n2;
	cin >> n1 >> n2;

	//倒转
	int l1 = n1.size(), l2 = n2.size();
	int cnt1 = 0, cnt2 = 0;
	for (int i = l1 - 1; i >= 0; i--) a[cnt1++] = n1[i] - '0';
	for (int i = l2 - 1; i >= 0; i--) b[cnt2++] = n2[i] - '0';
    // 字符型数字转换为数字需要减’0‘  ASCII码

	//相加
	int temp = 0;
	int x = max(l1, l2);
	for (int i = 0; i < x; i++)
	{
		temp += a[i] + b[i];
		c[i] = temp % 10;
		temp /= 10;
	}
	if (temp) c[x] = 1, x++;

	//输出
	for (int i = x - 1; i >= 0; i--) cout << c[i];
}