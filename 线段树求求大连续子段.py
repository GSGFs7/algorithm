class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.tree = [None] * (4 * self.n)
        self.build(data, 0, 0, self.n - 1)

    def build(self, data, node, start, end):
        if start == end:
            self.tree[node] = (data[start], data[start], data[start], data[start])
        else:
            mid = (start + end) // 2
            left_node = 2 * node + 1
            right_node = 2 * node + 2
            self.build(data, left_node, start, mid)
            self.build(data, right_node, mid + 1, end)
            self.tree[node] = self.merge(self.tree[left_node], self.tree[right_node])

    def merge(self, left, right):
        total_sum = left[0] + right[0]
        lmax = max(left[1], left[0] + right[1])
        rmax = max(right[2], right[0] + left[2])
        mmax = max(left[3], right[3], left[2] + right[1])
        return (total_sum, lmax, rmax, mmax)

    def query(self, L, R, node, start, end):
        if L > end or R < start:
            return (-float("inf"), -float("inf"), -float("inf"), -float("inf"))
        if L <= start and end <= R:
            return self.tree[node]

        mid = (start + end) // 2
        left_node = 2 * node + 1
        right_node = 2 * node + 2
        left_result = self.query(L, R, left_node, start, mid)
        right_result = self.query(L, R, right_node, mid + 1, end)
        return self.merge(left_result, right_result)

    def update(self, index, value, node, start, end):
        if start == end:
            self.tree[node] = (value, value, value, value)
        else:
            mid = (start + end) // 2
            left_node = 2 * node + 1
            right_node = 2 * node + 2
            if index <= mid:
                self.update(index, value, left_node, start, mid)
            else:
                self.update(index, value, right_node, mid + 1, end)
            self.tree[node] = self.merge(self.tree[left_node], self.tree[right_node])

    def range_query(self, L, R):
        return self.query(L, R, 0, 0, self.n - 1)[3]

    def point_update(self, index, value):
        self.update(index, value, 0, 0, self.n - 1)


def solve():
    n, m = map(int, input().split())
    data = list(map(int, input().split()))
    tree = SegmentTree(data)

    for i in range(m):
        k, x, y = map(int, input().split())
        if k == 1:
            if x > y:
                x, y = y, x
            # 下标从0开始
            print(tree.range_query(x - 1, y - 1))
        elif k == 2:
            tree.point_update(x - 1, y)
    pass


if __name__ == "__main__":
    你好 = 1
    # 你好 = int(input())
    for _ in range(你好):
        solve()
