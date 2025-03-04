"""
    给出一个字符串 重排这个字符串 使每一位上字符都与原来的不同

    从最简单的情况开始考虑
    aabc -> bcaa  可以通过循环右移的方式实现
    再稍微变化一下
    abac -> baca  可以通过记录原始下标的方式得到中间值 aabc
    靠中间值就又可以还原成上面的那种情况
    只不过需要记录原始下标来判断循环右移后停靠的位置
    为什么这个方法可行呢
    只要相同的部分没有超过一半 就可以通过转换成“有序的”来进行中转
    （有多少位相同的直接右移多少位就可以了）
    瞄啊～
"""


def solve():
    s = input()
    n = len(s)
    ans = [" "] * n
    d = dict()
    for c in s:
        d[c] = d.get(c, 0) + 1  # 如果找不到返回0然后再加一

    m = 0
    for val in d.values():
        m = max(m, val)

    if m * 2 > n:
        print(-1)
        return

    # 拆出字符并加入下标插入列表里
    a = [(s[i], i) for i in range(n)]
    a.sort()
    # print(a)

    for i in range(n):
        ans[a[i][1]] = a[(i + m) % n][0]
    print("".join(ans))
    pass


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


# https://ac.nowcoder.com/acm/contest/92662/E
# 2024-10-21
