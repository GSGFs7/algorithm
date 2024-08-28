"""
    给出一个字符串, 求从前后两端删掉若干个字符后 max(删掉的1的个数,剩下的0的个数)

    尺取法
    一种用两个指针扫描序列的区间的算法
        1.何时推进区间端点?
        2.如何推进区间端点?
        3.何时结束区间枚举?
    时间复杂度O(n)
    
    考虑枚举的方法, 枚举起点和终点, 时间复杂度在O(n^2)级, 不符合数据要求
    但是, 在枚举的时候cnt0和cnt1数量的变化有单调性
    l不动r增加时cnt0单调递增, cnt1单调递减
    因为数量固定, 一但其中一个值确定下来了, 最优的情况也就确定了
    最优的情况就是两个值相等的时候, 这个时候l和r画出的区间最大
    如果r继续向右扩展就会导致超出固定值, 最后的结果变大
"""


def solve():
    s = str(input())
    cnt0 = 0
    cnt1 = s.count("1")
    n = len(s)

    ans = cnt1
    l = r = 0
    while l < n:
        # 向后推到最大的可取值, 删掉和留下的两个值相等时即为区间最大情况下的最佳值
        while r < n and cnt1 != cnt0:
            if s[r] == "0":
                cnt0 += 1
            else:
                cnt1 -= 1
            r += 1
        # 两者的最大值尽可能小
        ans = min(ans, max(cnt0, cnt1))
        # l也向后推直到遍历所有情况
        if s[l] == "1":
            cnt1 += 1
        else:
            cnt0 -= 1
        l += 1
    print(ans)


if __name__ == "__main__":
    你好 = int(input())
    for _ in range(你好):
        solve()


# https://codeforces.com/contest/1680/problem/C
# 2024年6月27日
