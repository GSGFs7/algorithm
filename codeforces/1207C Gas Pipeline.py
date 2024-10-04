"""
    给出一个管道，在0的地方高度可以是1也可以是二，在1的地方高度为2
    问架设管道的最小花费
    
    一眼DP，还是特别简单的那种
    但是这么个简单的DP还WA13了，迟早气死
    设dp[i][0]是i位置高度为1的花费，dp[i][1]是i位置高度为2的花费
    直接大力DP枚举所有的情况
    VP的时候想复杂了，其实只需要看每个格子就可以了
    格子为0，这点结算时可高可低，1则没有低
"""


def solve():
    n, a, b = map(int, input().split())
    s = str(input())

    dp = [[1e30 for i in range(2)] for i in range(n + 1)]
    dp[0][0] = b
    # dp[0][1] = b * 2
    for i in range(n):
        if s[i] == "0":
            dp[i + 1][0] = min(dp[i][0] + a + b, dp[i][1] + a * 2 + b)
            dp[i + 1][1] = min(dp[i][0] + a * 2 + b * 2, dp[i][1] + a + b * 2)
        else:  # !!! 没有从下面来这项
            dp[i + 1][1] = dp[i][1] + a + b * 2
    print(dp[n][0])
    pass


if __name__ == "__main__":
    import sys, os

    if os.getenv("SHELL"):
        infile = open("1.in", "r")
        sys.stdin = infile

    你好 = 1
    你好 = int(input())
    for _ in range(你好):
        solve()


# https://codeforces.com/contest/1207/problem/C
# 2024-09-22