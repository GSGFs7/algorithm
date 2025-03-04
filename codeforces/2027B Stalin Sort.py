def solve():
    n = int(input())
    a = list(map(int, input().split()))

    d = dict()
    for i in range(n):
        if d.get(a[i], -1) == -1:  # 警钟敲碎！！！
            d[a[i]] = i
    # print(d)

    b = sorted(a, reverse=True)

    ans = 1e9
    for i in range(n):
        ans = min(ans, d[b[i]] + i)
        # print(b[i], d[b[i]] + i)
    print(ans)
    pass


if __name__ == "__main__":
    import os
    import sys

    if os.getenv("SHELL"):
        infile = open("1.in", "r")
        sys.stdin = infile

    你好 = 1
    你好 = int(input())
    for _ in range(你好):
        solve()


# https://codeforces.com/contest/2027/problem/B
# 2024-10-26
