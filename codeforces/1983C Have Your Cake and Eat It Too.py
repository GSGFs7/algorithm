"""
    给出一个区域, 区域中的每个位置对于三个人来说都有不同的价值
    求是否有一种划分可以使每个人的价值不低于总和的三分之一
    
    贪心
    暴力枚举符合条件的情况O(n)
    因为每个人的优先级都不同, 并且优先级也会影响最后的结果
    三个人只有六种方案, 直接暴力枚举每种方案即可
"""

from itertools import permutations


def solve():
    n = int(input())
    val = [[0], [0], [0]]
    sum = [[0], [0], [0]]
    for i in range(3):
        val[i] += list(map(int, input().split()))
    # print(val)  # ? 为什么是一样的值 地址共享
    for i in range(3):
        for j in range(1, n + 1):
            sum[i].append(sum[i][j - 1] + val[i][j])
    # print(sum)  # ?

    # 全部六种情况每种都试试
    perms = list(permutations([0, 1, 2]))
    target = (sum[0][n] + 2) // 3
    for i in range(6):
        r1 = 1
        perm = perms[i]
        # print(perm, sum[perm[0]])
        while r1 <= n and sum[perm[0]][r1] < target:  # 找到第一段
            r1 += 1
        # print(r1)
        for r2 in range(r1 + 1, n):
            if (
                sum[perm[1]][r2] - sum[perm[1]][r1] >= target
                and sum[perm[2]][n] - sum[perm[2]][r2] >= target
            ):
                ans = [[]] * 3
                ans[perm[0]] = [1, r1]
                ans[perm[1]] = [r1 + 1, r2]
                ans[perm[2]] = [r2 + 1, n]

                for x in ans:
                    print(x[0], x[1], end=" ")
                print()
                return
    print(-1)
    pass


if __name__ == "__main__":
    你好 = 1
    你好 = int(input())
    for _ in range(你好):
        solve()


# https://codeforces.com/contest/1983/problem/C
# 2024年7月13日

