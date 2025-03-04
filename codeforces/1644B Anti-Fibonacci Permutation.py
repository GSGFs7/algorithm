def solve():
    import random

    n = int(input())
    a = [i for i in range(1, n + 1)]
    cnt = 0
    d = {}
    while True:
        random.shuffle(a)
        flag = False
        for i in range(2, n):
            if a[i - 2] + a[i - 1] == a[i]:
                flag = True
                break
        if flag:
            continue
        if d.get(tuple(a)):
            continue
        else:
            d[tuple(a)] = 1

        if cnt == n:
            return
        cnt += 1
        for i in a:
            print(i, end=" ")
        print()
    pass


if __name__ == "__main__":
    import sys
    import os

    if os.getenv("SHELL"):
        infile = open("1.in", "r")
        sys.stdin = infile

    你好 = 1
    你好 = int(input())
    for _ in range(你好):
        solve()


# https://codeforces.com/contest/1644/problem/B
# 2024-10-07 