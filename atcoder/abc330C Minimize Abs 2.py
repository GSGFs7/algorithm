"""
    给出一个整数N 问|x^2+y^2-N|的最小值 其中x和y可以是任何整数

    因为直接暴力枚举x和y复杂度爆炸
    可以只枚举其中一个数x 另一个数由N减去x^2开方后向两边取整得到 因为是求绝对值
    这样复杂度就变成O(n)了
"""


def solve():
    from math import ceil, floor, sqrt

    n = int(input())
    ans = 1e20
    for i in range(int(2e6)):
        x = i * i
        y1 = ceil(sqrt(abs(n - x)))
        y2 = floor(sqrt(abs(n - x)))
        ans = min(ans, abs(x + y1 * y1 - n), abs(x + y2 * y2 - n))
    print(ans)
    pass


if __name__ == "__main__":
    import sys
    import os

    if os.getenv("SHELL"):
        infile = open("1.in", "r")
        sys.stdin = infile

    你好 = 1
    # 你好 = int(input())
    for _ in range(你好):
        solve()