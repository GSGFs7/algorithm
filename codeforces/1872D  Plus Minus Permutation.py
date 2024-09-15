from math import gcd


def lcm(a, b):
    return a * b // gcd(a, b)


def solve():
    n, x, y = map(int, input().split())
    l = lcm(x, y)
    x = n // x - n // l  # 可加的个数
    y = n // y - n // l  # 需要减去的个数
    # 加的数从n开始, 减去的数从1开始
    print((n + n - x + 1) * x // 2 - (1 + y) * y // 2)
    pass


if __name__ == "__main__":
    你好 = 1
    你好 = int(input())
    for _ in range(你好):
        solve()

# https://codeforces.com/contest/1872/problem/D
