#!/usr/bin/env python
# -*- coding: utf-8 -*-


"""
给出一个字符串, 问是否可以划分为三个回文串

跟昨天的思路一样的, 只不过数据范围变大了, 3759ms 669.88MB
直接暴力跑每一段看是不是回文, 如果是就切出来, 继续跑剩下的 
时间复杂度大概在O(N^3)级
"""

from functools import cache


class Solution:
    def checkPartitioning(self, s: str) -> bool:
        @cache
        def check(l: int, r: int) -> bool:
            if l >= r:
                return True
            if s[l] != s[r]:
                return False
            return check(l + 1, r - 1)

        # i表示现在剩下的字符串是s[i:] u表示还剩下u个回文串
        @cache
        def dfs(i: int, u: int) -> bool:
            if u == 1:
                return check(i, len(s) - 1)

            res = False
            for j in range(i, len(s) - 1):
                if check(i, j):
                    res |= dfs(j + 1, u - 1)
            return res

        return dfs(0, 3)


def solve():
    s = Solution()
    print(s.checkPartitioning("abcbdd"))


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


# https://leetcode.cn/problems/palindrome-partitioning-iv/description
# 2025-03-04 21:11