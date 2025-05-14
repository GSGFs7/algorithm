#!/usr/bin/env python
# -*- coding: utf-8 -*-


# import psutil

# if __name__ == "__main__":
#     # cpu
#     print(psutil.cpu_count(logical=False))
#     print(psutil.cpu_stats())
#     print(psutil.cpu_times())
#     for i in range(10):
#         print(psutil.cpu_percent(interval=1, percpu=True))

#     # 内存和交换分区
#     print(psutil.virtual_memory())
#     print(psutil.swap_memory())

#     # 硬盘
#     print(psutil.disk_partitions())
#     print(psutil.disk_usage('/'))
#     print(psutil.disk_io_counters())

#     # 网络
#     print(psutil.net_io_counters())


class Solution:
    def checkPartitioning(self, s: str) -> bool:
        def manacher(s):
            t = "#".join("^" + s + "$")
            halfLen = [0] * (len(t) - 2)
            halfLen[1] = 1
            m, r = 0, 0
            for i in range(2, len(halfLen)):
                hl = 1
                if i < r - 1:
                    hl = min(halfLen[m * 2 - i], r - i)
                while t[i - hl] == t[i + hl]:
                    hl += 1
                    m, r = i, i + hl
                halfLen[i] = hl
            return halfLen

        def isPalindrome(l, r):
            return halfLen[l + r + 2] >= r - l + 1

        n = len(s)
        halfLen = manacher(s)
        for i in range(1, n - 1):
            if isPalindrome(0, i - 1):
                for j in range(i, n - 1):
                    if isPalindrome(i, j) and isPalindrome(j + 1, n - 1):
                        return True
        return False
