#!/usr/bin/env python
# -*- coding: utf-8 -*-

from typing import List
from functools import cache, lru_cache
from collections import Counter
from bisect import bisect_right
from itertools import groupby, permutations
from string import ascii_lowercase
from math import inf, sqrt


class Solution:
    arr: List[int] = []

    def quick_sort(self, l: int, r: int) -> None:
        if l >= r:
            return

        mid: int = (l + r) // 2
        x: int = self.arr[mid]

        i, j = l, r
        while i <= j:
            print(i, j)
            while i <= r and self.arr[i] < x:
                i += 1
            while j >= l and self.arr[j] > x:
                j -= 1
            if i <= j:
                self.arr[i], self.arr[j] = self.arr[j], self.arr[i]
                i += 1
                j -= 1

        if l < j:
            self.quick_sort(l, j)
        if i < r:
            self.quick_sort(i, r)

    def sort(self, arr: List[int]) -> List[int]:
        self.arr = arr
        self.quick_sort(0, len(arr) - 1)
        return self.arr


def solve():
    s = Solution()
    print(s.sort([2, 1, 6, 10, 4, 1, 3, 9, 7]))


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
