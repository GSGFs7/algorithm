// 欧拉函数φ(n)
// 表示小于等于n的正整数中与n互质的数的个数 如：φ(6)=2   (1和5)
// 容斥原理
//  1~N中与N互质的个数
//      1.从1~N中去掉p[1],p[2]...p[k]的所有倍数
//      2.加上p[i]*p[j]的倍数
//      3.减去p[i]*p[j]*p[k]的倍数
// 以此类推，得到φ(n)=N(1-1/p[1])*(1-1/p[2])...(1-1/p[k])
// /

// 欧拉定理 a^φ(n) ≡ 1 (mod n)
// 费马定理 a^(p-1) ≡ 1 (mod p)
// 取模后的结果相等
// 同余
// a≡b(mod m)
// a和b被m除时有相同的余数/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        int res = x;
        for (int i = 2; i <= x / i; i++) // 分解质因数
            if (x % i == 0)
            {
                res = res / i * (i - 1);// 公式变形，避免浮点误差
                while (x % i == 0) x /= i;// 与次数无关
            }

        if (x > 1) res = res / x * (x - 1);
        cout << res << endl;
    }
    return 0;
}