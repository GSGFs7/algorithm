#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(vector<int> &A, int b) // 返回vector数组
{
    vector<int> C;

    int t = 0;// 进位
    for (int i = 0; i < A.size() || t; i++)// 将两个循环整合到一起
    {
        if (i < A.size()) t += A[i] * b;// 处理相乘操作
        // 处理剩下的进位
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();// 当乘以0时，去除前面的零，C.pop_back()移除栈顶
    return C;
}

int main()
{
    // 大数乘以小数
    string a;
    int b;
    cin >> a >> b;

    vector<int> A;// 转储为vector数组
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    auto c = mul(A, b);// 计算乘得的数组

    for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
    return 0;
}

