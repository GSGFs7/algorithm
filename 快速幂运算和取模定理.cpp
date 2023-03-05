#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int n = k % 14;
    long long int x = n*n*n*n*n*n*n % 14;
    cout << x;
    return 0;
}
//n*n*n*n*n*n*n % 14 等于 n%14的7次方对14取模
//题目:https://ac.nowcoder.com/acm/contest/52520/A
//https://juejin.cn/post/6928921415206830088