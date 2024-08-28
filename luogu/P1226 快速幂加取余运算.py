def quick_power(x, y):
    """
    快速幂运算，处理x的y次幂
    :param x: 底数
    :param y: 指数
    :return: 运算结果
    """
    ans = 1
    base = x
    while y:
        if y & 1:
            ans *= base
            ans = ans % p

        base *= base
        base = base % p
        y >>= 1
    return ans


a, b, p = map(int, input().split())
res = quick_power(a, b)
print("{}^{} mod {}={}".format(a, b, p, res))

