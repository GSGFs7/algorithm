#!/usr/bin/env python
# -*- coding: utf-8 -*-


"""
给出一个大数 问所有自区间对应的数的和是多少

首先，很容易想到把这个大数的每一位拆开来从个位开始计算
那么这样的计算就是，第 i 个位置需要计算 n-i 次
但是，这种方法复杂度依旧爆炸 O(n^2) 级
需要进一步的优化
对于前面的数（高位的数），因为是从 10^(n-i) 位一直加到个位
写成式子就是 s[i]*(10^(n-i)+...+10^0)
但是这个式子是不对的，因为没有考虑这个数需要被使用几次
首先对于最高位这个数而言 s[0]*10^n 只会被使用一次
而 s[1]*10(n-1) 却会被使用两次
也就是说第 i 个数会被重复使用 i+1 次
那么式子也就是 i*s[i]*10^(n-i)
最后需要如何计算这个式子呢，总不可能预处理出10的次方然后计算吧（好像还真行）
因为高位的影响是最广泛的，优先计算高位
因为是按位计算，那么计算每次计算对当前位置的影响即可
i位置对后面的所有的位置都有影响，这点前面已经说过了
那么具体的影响是多少呢
是i
比如说3790
7在百位上的贡献是790和3790，正好是2
7在十位上的贡献是79和379，正好也是2
7在个位上的贡献是7和37，正好也是2
直接用累加压缩计算即可
喵啊，喵不出来，到底怎么想到的
"""


def solve():
    n = int(input())
    s = " " + input()
    a = [0 for i in range(n + 1)]

    # 累加
    for i in range(1, n + 1):
        a[i] = a[i - 1] + int(s[i]) * i
    # print(a)

    # 进位
    for i in range(n, 0, -1):
        a[i - 1] += a[i] // 10
        a[i] %= 10

    if a[0]:
        print(a[0], end="")
    for i in range(1, n + 1):
        print(a[i], end="")
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


# https://atcoder.jp/contests/abc379/tasks/abc379_e
# 2024-11-23
