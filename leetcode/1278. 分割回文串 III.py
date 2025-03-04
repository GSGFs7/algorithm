#!/usr/bin/env python


"""
给出一个字符串, 可以任意更改字符串中的字符, 划分为k个回文串的最小花费

数据范围只有100
可以直接爆搜, 使用dfs(i,j)暴力搜索所有的可能情况, 并对所有可能的情况计算花费, 复杂度大概在O(n^3)级
"""


from typing import List
from functools import cache


class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        # 把子串s[l:r+1]改为回文串的花费
        @cache
        def check(l: int, r: int) -> int:
            if l >= r:
                return 0
            # 从外向内进行对比, 如果不一样就需要变成一样的
            return check(l + 1, r - 1) + (s[l] != s[r])

        # 爆搜, 还需要分割i次, 剩下s[j:]的字符串没有被分割
        @cache
        def dfs(i: int, j: int) -> int:
            # 如果不能再分了
            if i == 0:
                return check(j, len(s) - 1)

            res = int(1e9)
            for k in range(j + 1, len(s)):
                res = min(res, dfs(i - 1, k) + check(j, k - 1))
            return res

        return dfs(k - 1, 0)


def solve():
    solution = Solution()
    print(solution.palindromePartition("abc", 2))


if __name__ == "__main__":
    solve()


# https://leetcode.cn/problems/palindrome-partitioning-iii/description/
# 2025-03-03