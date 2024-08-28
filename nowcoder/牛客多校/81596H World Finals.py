"""
    给出两场比赛, 和比赛的预计成绩, 求出在lzr的安排下自己能获得的最好成绩
    每个人只能选择两场中的一场
    
    阅读理解+细节
"""


def solve():
    lzr = "lzr010506"
    d = {}  # 标记出现次数

    n = int(input())
    l1 = [None] * n
    for i in range(n):
        s, p, t = input().split()
        l1[i] = (str(s), int(p), int(t))
        if not d.get(l1[i][0]):
            d[l1[i][0]] = 1
        else:
            d[l1[i][0]] = 2
    l1 = sorted(l1, key=lambda x: (-x[-2], x[-1]))  # 按照p从达到小和t从小到大
    
    m = int(input())
    l2 = [None] * m
    for i in range(m):
        s, p, t = input().split()
        l2[i] = (str(s), int(p), int(t))
        if not d.get(l2[i][0]):
            d[l2[i][0]] = 1
        else:
            d[l2[i][0]] = 2
    l2 = sorted(l2, key=lambda x: (-x[-2], x[-1]))

    # 如果所有队伍两场都参加情况下的成绩
    ans1 = n
    for i in range(len(l1)):
        if l1[i][0] == lzr:
            ans1 = i + 1
            break
    ans2 = m
    for i in range(len(l2)):
        if l2[i][0] == lzr:
            ans2 = i + 1
            break

    # 删掉所有可以删掉的成绩
    for i in range(n):
        if l1[i][0] == lzr:
            break
        if d[l1[i][0]] == 2:
            ans1 -= 1
    for i in range(m):
        if l2[i][0] == lzr:
            break
        if d[l2[i][0]] == 2:
            ans2 -= 1
    print(min(ans1, ans2))
    pass


if __name__ == "__main__":
    # import sys

    # file = open("/home/jh/Downloads/2024牛客多校第一场数据/5.in", "r")
    # sys.stdin = file

    你好 = 1
    # 你好 = int(input())
    for _ in range(你好):
        solve()


# https://ac.nowcoder.com/acm/contest/81596/H
# 2024年7月17日
# 1756ms 80176KB