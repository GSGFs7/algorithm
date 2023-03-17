#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(vector<int> A, vector<int> B)// ����vector����
{
    vector<int> C(A.size() + B.size());// ����Ԫ�ظ���

    // ���ö���ѭ��ģ��������λ������ˣ�δ�����λ
    for (int i = 0; i < A.size(); i ++ )
        for (int j = 0; j < B.size(); j ++ )
            C[i + j] += A[i] * B[j];

    // �����λ
    for (int i = 0, t = 0; i < C.size() || t; i ++ )
    {
        t += C[i];
        if (i >= C.size()) C.push_back(t % 10);// �������Ԥ��ֵ���������һλ
        else C[i] = t % 10;
        t /= 10;
    }

    while (C.size() > 1 && !C.back()) C.pop_back();// ����0ʱȥ�������0

    return C;
}

int main()
{
    string a, b;
    cin >> a >> b;

    // ת��Ϊvector����
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

    auto C = mul(A, B);// �Զ��ж�C������

    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    cout << endl;

    return 0;
}
