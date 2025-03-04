#!/usr/bin/env python
# -*- coding: utf-8 -*-


import psutil

if __name__ == "__main__":
    # cpu
    print(psutil.cpu_count(logical=False))
    print(psutil.cpu_stats())
    print(psutil.cpu_times())
    for i in range(10):
        print(psutil.cpu_percent(interval=1, percpu=True))

    # 内存和交换分区
    print(psutil.virtual_memory())
    print(psutil.swap_memory())

    # 硬盘
    print(psutil.disk_partitions())
    print(psutil.disk_usage('/'))
    print(psutil.disk_io_counters())

    # 网络
    print(psutil.net_io_counters())
