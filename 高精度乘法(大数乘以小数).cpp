#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(vector<int> &A, int b) // ����vector����
{
    vector<int> C;

    int t = 0;// ��λ
    for (int i = 0; i < A.size() || t; i++)// ������ѭ�����ϵ�һ��
    {
        if (i < A.size()) t += A[i] * b;// ������˲���
        // ����ʣ�µĽ�λ
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();// ������0ʱ��ȥ��ǰ����㣬C.pop_back()�Ƴ�ջ��
    return C;
}

int main()
{
    // ��������С��
    string a;
    int b;
    cin >> a >> b;

    vector<int> A;// ת��Ϊvector����
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    auto c = mul(A, b);// ����˵õ�����

    for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
    return 0;
}

