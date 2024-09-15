"""
    给出n个观众, 第i个观众对a电影的评价是a[i], b电影是b[i], 最大化两个电影中的最小值

    贪心
    如果可分配的好评和差评相加都补不齐两者的差值就全加最小的上
    如果可以补齐就直接取平均值
"""


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    ans1 = ans2 = 0
    cnt1 = cnt2 = 0
    for i in range(n):  # 看是否拥有选择权, 使最后的结果最大化
        if a[i] == 1 and b[i] == 1:
            cnt1 += 1  # 可以两个位置任意放
        elif a[i] == 0 and b[i] == 1:
            ans2 += 1
        elif a[i] == 1 and b[i] == 0:
            ans1 += 1
        elif a[i] == 0 and b[i] == 0:
            pass  #! 为什么偏偏就少了这一个if
        elif a[i] == -1 and b[i] != -1:
            ans2 += b[i]
        elif a[i] != -1 and b[i] == -1:
            ans1 += a[i]
        else:
            cnt2 -= 1  # 可以两个位置任意放

    if ans1 + cnt2 > cnt1 + ans2:  # 如果配不齐, a, b都有可能是较大的那个数
        print(ans2 + cnt1)
    elif ans2 + cnt2 > cnt1 + ans1:
        print(ans1 + cnt1)
    else:
        print((ans1 + ans2 + cnt1 + cnt2) // 2)
    pass


if __name__ == "__main__":
    你好 = 1
    你好 = int(input())
    for _ in range(你好):
        solve()


# https://codeforces.com/contest/1989/problem/C
# 2024年6月28日
