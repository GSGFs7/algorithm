"""
    每次给出两个整数t和v, t表示从数组最后删掉t个数, v表示进行t操作后添加v到数组末尾
    求每次操作后低一个位置的后缀和的后缀和
    
    进行一次后缀和操作后低一个位置上的值就是 a[1]+a[2]+...+a[n]
    对这个后缀和数组再进行一次后缀和操作就是 a[1]+2*a[2]+...+n*a[n]
    也就是说第i个位置上的贡献为 i*a[i] 在删除时直接删掉 i*a[i] 即可
    添加值时同理
"""


def solve():
    n = int(input())
    MOD = 1e9 + 7
    res = 0
    l = 0
    a = []
    while n:
        n -= 1
        t, v = map(int, input().split())
        while t:
            res = (res - a[-1] * l + MOD) % MOD  # 减去 a[len]*len
            a.pop()
            l -= 1
            t -= 1
        l += 1
        a.append(v)
        res = (res + v * l + MOD) % MOD  # 加上a[len]*len
        print(int(res))
    pass


if __name__ == "__main__":
    你好 = 1
    # 你好 = int(input())
    for _ in range(你好):
        solve()


# https://ac.nowcoder.com/acm/contest/81596/C
# 2024年7月17日
# 3727ms 39136K py时限4s
