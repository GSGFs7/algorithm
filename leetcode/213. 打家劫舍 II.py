#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
有几户人家围成一圈, 可以去别人家里抢钱, 但是不可以抢连续的两户人家, 问最多可以抢多少

和打家劫舍1是一样的, 只不过多了处理首尾相接那部分
因为抢的钱都是正数, 也就是只要抢了就是赚的, 那么四户人家就至少也要抢两户(贪心)
对于其中的一个位置, 这个位置的钱可以从 dp[i-2] 和 dp[i-3] 得到
那么从第一户累计到最后一户的状态转移方程是 dp[i] = max(dp[i-2],dp[i-3])+num[i]
"""


from typing import List
from functools import cache


class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return max(nums)

        dp1 = [0] * (len(nums) + 1)
        dp1[0] = 0
        dp1[1] = nums[0]
        dp1[2] = max(nums[0], nums[1])
        for i in range(3, len(nums)):
            dp1[i] = max(dp1[i - 2] + nums[i - 1], dp1[i - 3] + nums[i - 1])

        dp2 = [0] * (len(nums) + 1)
        dp2[0] = 0
        dp2[1] = 0
        dp2[2] = nums[1]
        for i in range(3, len(nums) + 1):
            dp2[i] = max(dp2[i - 2] + nums[i - 1], dp2[i - 3] + nums[i - 1])

        return max(max(dp1), max(dp2))


def solve():
    s = Solution()
    print(s.rob([200, 3, 140, 20, 10]))


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


# https://leetcode.cn/problems/house-robber-ii/description/
# 2025-03-04 21:10