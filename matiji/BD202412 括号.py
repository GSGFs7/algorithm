"""
    给出一个只包含两边括号的字符串, 求改动其中一个括号使这个字符串的括号闭合的方案数
    思路:
        找起点, 见代码注释
"""


def solve():
    s = str(input())

    # 特判前后两个端点
    if s[0] == ")" or s[-1] == "(":
        print(1)
        return

    temp = a = b = 0
    if s.count("(") > s.count(")"):
        a = b = 0
        for i in s:
            if i == "(":
                # 标记可能是符合条件的起点, 因为只有一个是多余的
                # 能找到一个新的起点也就说明前面的起点是不符合条件的
                # 直接覆盖掉前面的点
                if a - b == 1:
                    temp = a
                a += 1
            else:
                b += 1

            # 如果可以组成一个完整的括号, 直接清空
            if a == b:
                a = b = temp = 0
    elif s.count("(") < s.count(")"):  # 对于另一种情况来说同理
        a = b = 0
        for i in reversed(s):
            if i == ")":
                if a - b == 1:
                    temp = a
                a += 1
            else:
                b += 1

            if a == b:
                a = b = temp = 0
    else:
        a = b = temp = 0

    print(a - temp)


if __name__ == "__main__":
    你好 = 1
    # 你好 = int(input())
    for _ in range(你好):
        solve()

# https://www.matiji.net/exam/brushquestion/12/4498/F16DA07A4D99E21DFFEF46BD18FF68AD
# 2024年6月26日
