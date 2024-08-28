"""
    给出l和r, 求a和b符合l<=a+b<=r, 并且a和b不互素

    直接暴力即可
    枚举从l到r的所有合数
"""


from math import gcd


def check(x):
    for i in range(2, int(x ** 0.5 + 1)):
        if x % i == 0:
            return True
    return False


def solve():
    l, r = map(int, input().split())

    a = 0
    for i in range(l, r + 1):  # 枚举两个数之和
        if i != 2 and check(i):
            a = i
            break

    if a == 0:  # 如果在整个范围内没有任何一个可以划分的数
        print(-1)
        return

    for i in range(2, a + 1):
        if gcd(i, a - i) != 1:
            print(i, a - i)
            return
    pass


if __name__ == "__main__":
    你好 = 1
    你好 = int(input())
    for _ in range(你好):
        solve()

# https://codeforces.com/contest/1872/problem/C
