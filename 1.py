#!/usr/bin/env python
# -*- coding: utf-8 -*-

from typing import List
from functools import cache
from collections import Counter
from bisect import bisect_right
from itertools import groupby, permutations
from string import ascii_lowercase
from math import inf, sqrt


class Solution:
    def kthCharacter(self, k: int) -> str:
        return ascii_lowercase[(k - 1).bit_count()]


def solve():
    s = Solution()
    print(s.kthCharacter(1))
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
