#include <iostream>
#include <string>
/// 加个string头文件就过了???
using namespace std;

int main()
{
    string a, b;
    while (cin >> a >> b) {

        long long  n1 = 0;
        for (char i : a)
        {
            if (i != '-' && i != ',') n1 = n1*10 + (i - '0'); // 加入新的数时将所有数往左移一位
            else continue;
        }
        if (a[0] == '-') n1 = -1*n1;

        long long n2 = 0;
        for (char i : b)
        {
            if (i != '-' && i != ',') n2 = n2*10 + (i - '0');
            else continue;
        }
        if (b[0] == '-') n2 = -1*n2;

        cout << n1 + n2 << endl;
    }
    return 0;
}

// https://acm.hdu.edu.cn/showproblem.php?pid=3787