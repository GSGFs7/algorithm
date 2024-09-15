def solve():
    out = open("1.out", "w")
    sys.stdout = out
    print(1000)
    for i in range(1000):
        print(1, end=" ")
    pass


if __name__ == "__main__":
    import sys, os

    if os.getenv("LOCAL_VSCode") or os.getenv("SHELL"):
        infile = open("1.in", "r")
        sys.stdin = infile

    你好 = 1
    # 你好 = int(input())
    for _ in range(你好):
        solve()
