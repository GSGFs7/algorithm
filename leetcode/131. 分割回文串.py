#!/usr/bin/env python


"""
给出一个字符串, 求所有的切分字符串为回文子串的所有方法

1 <= s.length <= 16

直接暴力深搜
"""

from typing import List


class Solution:
    def __init__(self):
        self.temp = []
        self.ans = []

    def partition(self, s: str) -> List[List[str]]:
        self.dfs(s, 0)
        return self.ans

    def check(self, s: str, l: int, r: int) -> bool:
        for i in range(0, r - l + 1):
            if s[l + i] != s[r - i]:
                return False
        return True

    def dfs(self, s: str, u: int):
        if len(s) == u:
            #! 必须要切片创建新的列表, 不然append的只是一个引用
            self.ans.append(self.temp[:])

        for i in range(u, len(s)):
            if self.check(s, u, i):
                self.temp.append(s[u : i + 1])
                self.dfs(s, i + 1)
                self.temp.pop()


def solve():
    solution = Solution()
    print(solution.partition("aab"))


if __name__ == "__main__":
    solve()


# https://leetcode.cn/problems/palindrome-partitioning/description/
# 2025-03-03
