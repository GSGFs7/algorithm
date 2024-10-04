"""
    给出n件武器，第i件武器锻造需要花费a[i]的金属锭，熔化这件武器会返还b[i]的金属锭
    锻造和熔化一件武器都可以获得1点经验，每件武器都可以使用任意种类的金属锭锻造
    问最大能获得的经验是多少
    
    首先，贪心着来想
    锻造一件武器后会消耗a[i]的锭，必须要熔化才会返还b[i]的锭
    所以每次都需要重新熔化武器才能最大化收益
    因为金属锭会发生损耗，那么就尽量减少花费，在许可的情况下每次都选择最小的损耗
    反正一次发生损耗也只会给2点经验
    那么现在的目标就变成了如何寻找最小的方式损耗金属锭
    因为c的范围在1e9，枚举所有的情况肯定是不行的
    因为a的范围只有1e6，转过来枚举a的情况
    找出在1e6的范围内所有的容量下的最小损耗(best)
    通过记忆化的方式在最小损耗的基础上计算可行的最大结果(calc)
    再使用每一个c去计算有多少经验
"""


def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    mx = max(a) + 1
    best = [int(1e9)] * mx
    calc = [0] * mx

    # best 表示在这么多锭下能选择的最小花费
    for i in range(len(a)):
        best[a[i]] = min(best[a[i]], a[i] - b[i])

    # 重新整理一下，后面更多的锭肯定都能使用前面的花费
    for v in range(1, mx):
        best[v] = min(best[v], best[v - 1])

    # DP计算结果，当前的结果就是更小的结果的再加上最小花费
    for v in range(1, mx):
        if v >= best[v]:
            calc[v] = 2 + calc[v - best[v]]

    # 使用给出的c计算结果
    ans = 0
    for v in c:
        cur = v
        if cur >= mx:  # 如果超过了最大的，那么就可以用最大的calc重复着来算
            k = (cur - mx + 1 + best[mx - 1]) // best[mx - 1]
            ans += 2 * k
            cur -= k * best[mx - 1]
        ans += calc[cur]  # 计算没超过的那部分

    print(ans)


if __name__ == "__main__":
    import sys, os

    if os.getenv("SHELL"):
        infile = open("1.in", "r")
        sys.stdin = infile

    你好 = 1
    # 你好 = int(input())
    for _ in range(你好):
        solve()


# https://codeforces.com/contest/1989/problem/D
# 2024-09-22