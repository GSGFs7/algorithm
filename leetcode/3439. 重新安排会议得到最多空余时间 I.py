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
可以看成长度为k+1的滑动窗口
"""


class Solution:
    def maxFreeTime(
        self, eventTime: int, k: int, startTime: List[int], endTime: List[int]
    ) -> int:
        n = len(startTime)
        space: List[int] = [startTime[0] - 0]
        for i in range(1, n):
            space.append(startTime[i] - endTime[i - 1])
        space.append(eventTime - endTime[-1])
        
        print(space)

        res = 0
        ans = 0
        for i, s in enumerate(space):
            res += s

            if i < k:
                continue

            ans = max(ans, res)
            res -= space[i - k]
        return ans


def solve():
    s = Solution()
    print(s.maxFreeTime(10, 1, [0, 2, 9], [1, 4, 10]))
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
