#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], c[N];

int main()
{
	//����
	string n1, n2;
	cin >> n1 >> n2;

	//��ת
	int l1 = n1.size(), l2 = n2.size();
	int cnt1 = 0, cnt2 = 0;
	for (int i = l1 - 1; i >= 0; i--) a[cnt1++] = n1[i] - '0';
	for (int i = l2 - 1; i >= 0; i--) b[cnt2++] = n2[i] - '0';
    // �ַ�������ת��Ϊ������Ҫ����0��  ASCII��

	//���
	int temp = 0;
	int x = max(l1, l2);
	for (int i = 0; i < x; i++)
	{
		temp += a[i] + b[i];
		c[i] = temp % 10;
		temp /= 10;
	}
	if (temp) c[x] = 1, x++;

	//���
	for (int i = x - 1; i >= 0; i--) cout << c[i];
}