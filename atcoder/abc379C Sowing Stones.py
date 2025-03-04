#!/usr/bin/env python
# -*- coding: utf-8 -*-


"""
给出几个位置和这个位置上的石子的数量，石子可以向后移动，问需要移动多少次才可以使n个位置上都有一个石子
"""


def solve():
    n, m = map(int, input().split())
    x = list(map(int, input().split()))
    a = list(map(int, input().split()))
    z = [(x, y) for x, y in sorted(zip(x, a))]

    if sum(a) != n:
        print(-1)
        return

    ans = 0
    last = 1
    for i in range(m):
        x = z[i][0]
        y = z[i][1]
        if x <= last:
            # 这个位置上所有的都整体往后移 让前面没结束的先排到0
            ans += y * (last - x) + y * (y - 1) // 2
            last += y
        else:
            print(-1)
            return
    print(ans)
    pass


if __name__ == "__main__":
    import os
    import sys

    if os.getenv("SHELL"):
        infile = open("1.in", "r")
        sys.stdin = infile

    你好 = 1
    # 你好 = int(input())
    for _ in range(你好):
        solve()


# https://atcoder.jp/contests/abc379/submissions/60116670
# 2024-11-23
