"""
    给两个正整数a,b输出他们的最大公约数 gcd(a,b)。
    a的十进制位数不超过1e6
    
    数据太大, 直接计算会TLE, 需要先一位一位取模 (直接取模也会TLE)
"""

from math import gcd


def solve():
    a = str(input())
    b = int(input())
    m = 0
    for i in a:
        m = m * 10 + int(i)
        m %= b
    print(gcd(m, b))
    pass


if __name__ == "__main__":
    你好 = 1
    # 你好 = int(input())
    for _ in range(你好):
        solve()


# https://ac.nowcoder.com/acm/contest/86034/D
# 2024年7月15日
