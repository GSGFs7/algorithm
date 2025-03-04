"""
    给出一个只包含o和x的图 问存在多少个由o构成的三元组 满足一行和一列都有两个o

    |o |oo| o|oo|
    |oo|o |oo| o|
    根据题目的要求只有上面四种情况 而且允许中间存在间隔
    一个点一个点枚举复杂度爆炸 只需要枚举拐角那个点就可以了
    枚举出拐角的点之后直接计算行列分别计算有多少 减一相乘后就是以这个点为拐角的数量了
"""


def solve():
    n = int(input())
    g = [str(input()) for i in range(n)]
    # for i in g:
    #     print(i)

    # 统计行列
    row = [0] * n
    column = [0] * n
    for i in range(n):
        for j in range(n):
            if g[i][j] == 'o':
                row[i] += 1
                column[j] += 1

    # 枚举拐角 计算可能性
    ans = 0
    for i in range(n):
        for j in range(n):
            if g[i][j] == 'o':
                ans += (row[i] - 1) * (column[j] - 1)
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


# https://atcoder.jp/contests/abc330/tasks/abc330_d
# 2024-10-06