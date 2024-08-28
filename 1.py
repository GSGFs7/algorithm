def solve():
    n = int(input())

    def n2s(n):
        res = ""
        while n:
            if n & 1:
                res += "1"
            else:
                res += "0"
            n >>= 1
        return res[::-1]

    def s2n(s):
        res = 0
        base = 1
        for i in s[::-1]:
            if i == "1":
                res += base
            base >>= 1
        return res

    pass


if __name__ == "__main__":
    你好 = 1
    你好 = int(input())
    for _ in range(你好):
        solve()

