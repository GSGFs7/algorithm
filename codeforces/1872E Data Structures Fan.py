"""
    前缀异或和
    异或的性质,
"""


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    s = str(input())

    res1 = res2 = 0
    s = " " + s
    a.insert(0, 0)
    for i in range(1, n + 1):
        if s[i] == '1':
            res1 ^= a[i]
        else:
            res2 ^= a[i]

    # 前缀异或和
    for i in range(2, n + 1):
        a[i] ^= a[i - 1]
    # print("a:", a)

    t = int(input())
    for _ in range(t):
        op = list(map(int, input().split()))
        if op[0] == 1:
            res1 ^= a[op[2]] ^ a[op[1] - 1]  # 区间值翻转
            res2 ^= a[op[2]] ^ a[op[1] - 1]
        else:
            if op[1] == 0:
                print(res2, end=" ")
            else:
                print(res1, end=" ")
    print()
    pass


if __name__ == "__main__":
    你好 = 1
    你好 = int(input())
    for _ in range(你好):
        solve()

# https://codeforces.com/contest/1872/problem/E
