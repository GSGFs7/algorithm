#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(vector<int> A, vector<int> B)// 返回vector数组
{
    vector<int> C(A.size() + B.size());// 设置元素个数

    // 利用二重循环模拟两数各位依次相乘，未处理进位
    for (int i = 0; i < A.size(); i ++ )
        for (int j = 0; j < B.size(); j ++ )
            C[i + j] += A[i] * B[j];

    // 处理进位
    for (int i = 0, t = 0; i < C.size() || t; i ++ )
    {
        t += C[i];
        if (i >= C.size()) C.push_back(t % 10);// 如果大于预设值就向后扩充一位
        else C[i] = t % 10;
        t /= 10;
    }

    while (C.size() > 1 && !C.back()) C.pop_back();// 乘以0时去除多余的0

    return C;
}

int main()
{
    string a, b;
    cin >> a >> b;

    // 转换为vector数组
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

    auto C = mul(A, B);// 自动判断C的类型

    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    cout << endl;

    return 0;
}
