#include <iostream>
using namespace  std;

int main() {
    int n = 10;
    for (int i = 3; i >= 0; i--) cout << (n >> i & 1) << " ";
    // & 位与运算 当两个值都为1时结果为1 0&0为0
    return 0;
}
