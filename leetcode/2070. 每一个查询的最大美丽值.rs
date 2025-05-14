struct Solution;

// 简单二分

impl Solution {
    pub fn maximum_beauty(items: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
        let mut items: Vec<Vec<i32>> = items;
        items.sort();

        let mut f: Vec<i32> = Vec::with_capacity(items.len() + 1);
        // with_capacity 虽然会预分配内存, 但是依旧是空向量, 需要 push
        f.push(0);
        for i in 0..(items.len()) {
            f.push(std::cmp::max(f[i], items[i][1]));
        }

        // 对 queries 中的每个数取可以取得在 items 中最右边的数
        queries
            .iter()
            .map(|&query: &i32| {
                // partition_point(|item: &Vec<i32>| item[0] <= query) 类似与 py 中的 bisect_right
                f[items.partition_point(|item: &Vec<i32>| item[0] <= query)]
            })
            .collect()
    }
}

fn main() {
    println!(
        "{:#?}",
        Solution::maximum_beauty(
            [[1, 2], [3, 2], [2, 4], [5, 6], [3, 5]]
                .iter()
                .map(|vec| vec.to_vec())
                .collect::<std::vec::Vec<Vec<i32>>>(),
            vec![1, 2, 3, 4, 5, 6]
        )
    );
}

// https://leetcode.cn/problems/most-beautiful-item-for-each-query/description
