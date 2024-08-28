"""
    给出一个数组表示毒蘑菇, 每次选择一个区间, 吃掉区间中所有的蘑菇
    如果过程中某个位置毒性总和超过了m, 就会重新清0
    求有多少中方案选择区间, 使最后的毒性不为0

    递推，二分
    因为需要的是最后的吃掉区间内所有毒蘑菇的方案数
    所以如果枚举左端点，右端点越靠后区间包含的方案数越多
    正着处理太麻烦了，直接从右端点开始找左端点
    存储每一次的值，最后加起来就是最后的结果了
"""


def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    pre = [0]
    for i in range(n):
        pre.append(pre[-1] + a[i])  # 前缀和

    ans = 0
    f = [0 for i in range(n + 4)]
    for i in range(n, 0, -1):  # 从后往前进行递推
        l = i
        r = n
        p = i - 1
        while l <= r:  # 二分查找最大的区间长度
            mid = (l + r) // 2
            if pre[mid] - pre[i - 1] <= m:
                p = mid
                l = mid + 1
            else:
                r = mid - 1
        f[i] = p - i + 1 + f[p + 2]  # 加上这段的区间长度
        ans += f[i]  # 统计可行的结果
    print(ans)
    pass


if __name__ == "__main__":
    import sys, os

    if os.getenv("LOCAL_VSCode") or os.getenv("ZSH"):
        infile = open("1.in", "r")
        sys.stdin = infile

    你好 = 1
    你好 = int(input())
    for _ in range(你好):
        solve()


# https://codeforces.com/contest/1994/problem/C
# 2024年7月20日
