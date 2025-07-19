#!/usr/bin/env python
# -*- coding: utf-8 -*-


from typing import Dict, List, Literal, Self, Tuple
from functools import cache
from collections import Counter
from bisect import bisect_right
from itertools import groupby, permutations
from string import ascii_lowercase
from math import inf, sqrt


"""
给出一个整数k和两种操作，最初的字符串为 word="a"
1. 复制一份word，并追加到末尾
2. 所有字符向后移一个ascii码，并追加到末尾
每次的操作是operations[i]，问第k个数的值

因为只有向后移动的时候才会改变字符，并且每次计算都会把整个字符串的长度翻倍
那么只需要原路返回，统计移动的次数即可
因为k的取值范围为10^14需要使用二分的方法
如果这次的中间值小于k，抛弃这次操作继续向左
如果大于，统计次数并向左
因为是直接扩大一倍，那么之前的值就是k-mid
"""


class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        if not operations:
            return "a"

        # 当前的操作，因为弹出了，下面不需要减一
        op: int = operations.pop()
        # 当前操作的字符串长度，也就是2^(n-1)
        mid: int = 1 << len(operations)

        # 如果这次落在了左半边
        if mid >= k:
            # 继续向左找有多少个1，因为没够到mid不需要统计
            return self.kthCharacter(k, operations)

        # 如果在右半边, 继续找左边有多少个1, 位置也要映射到这次移动前
        ans: str = self.kthCharacter(k - mid, operations)
        return ascii_lowercase[(ord(ans) - ord("a") + op) % 26]


def solve():
    s = Solution()
    print(s.kthCharacter(10, [0, 1, 0, 1]))
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


# https://leetcode.cn/problems/find-the-k-th-character-in-string-game-ii
