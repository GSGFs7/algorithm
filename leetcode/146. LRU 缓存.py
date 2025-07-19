#!/usr/bin/env python
# -*- coding: utf-8 -*-


from typing import Dict, List, Literal, Self, Tuple
from functools import cache
from collections import Counter
from bisect import bisect_right
from itertools import groupby, permutations
from string import ascii_lowercase
from math import inf, sqrt


class LRUCache:
    class DLinkedNode:
        def __init__(self, key: int, value: int) -> None:
            self.key: int = key
            self.value: int = value
            self.prev: Self
            self.next: Self

    def __init__(self, capacity: int) -> None:
        self.capacity: int = capacity
        self.size: int = 0
        self.cache: Dict[int, LRUCache.DLinkedNode] = dict()
        self.FHead: LRUCache.DLinkedNode = self.DLinkedNode(0, 0)
        self.FTail: LRUCache.DLinkedNode = self.DLinkedNode(0, 0)
        self.FHead.next = self.FTail
        self.FTail.prev = self.FHead

    def get(self, key: int) -> int:
        node = self.cache.get(key, None)

        if node is None:
            return -1

        self._move_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return

        node = self.cache.get(key)

        if node is None:
            node = self.DLinkedNode(key, value)
            self.cache[key] = node
            self._add_to_hand(node)
            self.size += 1
            if self.size > self.capacity:
                removed = self._remove_tail()
                self.cache.pop(removed.key)
                self.size -= 1
        else:
            node = self.cache[key]
            node.value = value
            self._move_to_head(node)

    def _add_to_hand(self, node: "LRUCache.DLinkedNode") -> None:
        node.prev = self.FHead
        node.next = self.FHead.next
        self.FHead.next.prev = node
        self.FHead.next = node

    def _remove_node(self, node: "LRUCache.DLinkedNode") -> None:
        node.prev.next = node.next
        node.next.prev = node.prev

    def _move_to_head(self, node: "LRUCache.DLinkedNode") -> None:
        self._remove_node(node)
        self._add_to_hand(node)

    def _remove_tail(self) -> "LRUCache.DLinkedNode":
        node = self.FTail.prev
        self._remove_node(node)
        return node


def solve():
    op: List[Literal["LRUCache", "put", "get"]] = [
        "LRUCache",
        "put",
        "put",
        "get",
        "put",
        "get",
        "put",
        "get",
        "get",
        "get",
    ]
    value: List[List[int]] = [
        [2],
        [1, 1],
        [2, 2],
        [1],
        [3, 3],
        [2],
        [4, 4],
        [1],
        [3],
        [4],
    ]

    cache: LRUCache = LRUCache(0)
    for i in range(len(op)):
        if op[i] == "LRUCache":
            cache = LRUCache(value[i][0])
            print(None)
        elif op[i] == "get":
            print(cache.get(value[i][0]))
        elif op[i] == "put":
            cache.put(value[i][0], value[i][1])
            print(None)


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


# https://leetcode.cn/problems/lru-cache/description/
