#!/usr/bin/env python
# -*- coding: utf-8 -*-


"""
操作1：种花
操作2：花全部长高x
操作3：删掉所有比x高的花

本来想的是线段树
但是因为花是有单调性的
前面的花会比后面的花先删除（可能一起）
直接使用队列维护时间即可
如果超出时间直接删掉
"""


def solve():
    import heapq

    n = int(input())
    q = list()
    heapq.heapify(q)
    now = 0
    while n:
        n -= 1
        op = list(map(int, input().split()))
        if op[0] == 1:
            heapq.heappush(q, now)
        elif op[0] == 2:
            now += op[1]
        else:
            cnt = 0
            while len(q) and now - op[1] >= q[0]:
                heapq.heappop(q)
                cnt += 1
            print(cnt)
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


# https://atcoder.jp/contests/abc379/tasks/abc379_d
# 2024-11-23
