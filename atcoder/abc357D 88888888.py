"""
    给出一个N 求将N拼接N对998244353取模的结果

    假设a[1]表示拼接一次的结果 a[2]表示拼接两次的结果
    那么a[1]=n a[2]=x*n+n  其中的x表示10^k  k表示n的位数
    这样可以推出 a[n]=x*a[n-1]+n  这个前缀也就是上次计算得到的值往后接了个n
    将上式展开得到 n(x^{n-1}+x^{n-2}+...+x+1)
    也就是 n*(x^n-1)/(x-1)  (等比公式)
    根据费马小定理 n*(x^n-1)*(x-1)^(MOD-2)  
    使用快速幂O(logn)计算出结果
"""
def solve():
    MOD = 998244353
    n = int(input())
    l = len(str(n))
    
    def qpow(a, b):
        res = 1
        while (b):
            if (b & 1):
                res = res * a % MOD
            a = a * a % MOD
            b >>= 1
        return res

    print(n % MOD * (qpow(10 ** l, n) - 1 + MOD) % MOD * qpow(10 ** l - 1, MOD - 2) % MOD)
    pass


if __name__ == "__main__":
    import sys, os

    if os.getenv("SHELL"):
        infile = open("1.in", "r")
        sys.stdin = infile

    你好 = 1
    # 你好 = int(input())
    for _ in range(你好):
        solve()
