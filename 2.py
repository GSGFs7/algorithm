from heapq import heappush, heappop, heapify, heappushpop
from bisect import bisect_left


# 优先队列
def heap():
    q = [1, 0, 0, 8, 6, ]
    heapify(q)  # 列表转化为小根堆, 本质还是一个列表
    heappush(q, 2)
    heappush(q, 1)
    heappush(q, 0)
    heappop(q)
    heappushpop(q, 9)
    print(q)
    pass


def dictionary():
    d = {"ksk": 1, "MC": 3, "PorT": 10}

    print(d.get("Air"))  # 如果不确定存不存在需要用get, 不然会报错, get到空会返回None
    d["ll"] = 10086  # 添加元素
    d.pop("ksk")
    print(d)

    for i in d.items():  # 返回键值对, 元组
        print(i)

    # 遍历值, 尽量避免, 会创建一个新的列表, 用d.items()
    for i in d.values():
        print(i)
    for i in d:  # for默认取first
        print(i, d[i])

    # 字典列表化找key
    print(list(d.keys())[list(d.values()).index(3)])
    # 使用next()函数
    print(next(key for key, value in d.items() if value == 3))
    # 使用列表推导式
    print([key for key, value in d.items() if value == 3][0])
    pass


def solve():
    # heap()
    dictionary()
    pass


if __name__ == "__main__":
    你好 = 1
    # 你好 = int(input())
    for _ in range(你好):
        solve()
