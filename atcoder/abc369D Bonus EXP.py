#! /usr/bin/env python
# -*- coding: utf-8 -*-


"""
给出一个数组，可以选择其中一个数，也可以不选，当选到偶数个时可以获得两倍的价值
问最大能获取的价值

DP
因为都是正整数，所以能多选就需要多选
对于整个DP而言，比较好的方式就是看这个点是不是第偶数个点
如果这个点是偶数个的话前面的一个点就需要取奇数情况的最大值
直接从前开始向后取值即可，同时维护这个点是奇数和偶数的情况
有一个特殊情况，第一个点是永远不能获得偶数位置的两倍加成的
把前面那个位置上的偶数值设为负无穷大即可
"""


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    dp = [0, int(-1e20)]
    for i in range(n):
        tmp = [0, 0]
        tmp[0] = max(dp[0], dp[1] + a[i] * 2)
        tmp[1] = max(dp[1], dp[0] + a[i])
        # print(dp)
        dp, tmp = tmp, dp
    print(max(dp))
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


# 2024-11-19
# https://atcoder.jp/contests/abc369/tasks/abc369_d
