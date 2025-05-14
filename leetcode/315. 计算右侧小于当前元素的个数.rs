struct Solution;

impl Solution {
    pub fn count_smaller(nums: Vec<i32>) -> Vec<i32> {
        // 树状数组的三个函数
        // 插入一个数x之后, 从0到x都会加上1

        fn low_bit(x: i32) -> i32 {
            x & -x
        }

        fn update(tree: &mut [i32], mut index: i32, value: i32) {
            let n = tree.len();
            while (index as usize) < n {
                tree[index as usize] += value;
                index += low_bit(index);
            }
        }

        fn query(tree: &mut [i32], mut index: i32) -> i32 {
            let mut res = 0;
            while index > 0 {
                res += tree[index as usize];
                index -= low_bit(index);
            }
            res
        }

        let n = nums.len();
        let mut ans = vec![0; n];
        let mut tree = vec![0; n];

        // 离散化
        let mut sorted = nums.clone();
        sorted.sort();
        sorted.dedup();

        // 寻找离散化之后的下标
        let get_index = |x: i32| -> i32 { sorted.binary_search(&x).unwrap() as i32 + 1 };

        // 从后边开始, 每次查询后插入这个数
        for i in (0..n).rev() {
            let index = get_index(nums[i]);
            ans[i] = query(&mut tree, index - 1);
            update(&mut tree, index, 1);
        }

        ans
    }
}

fn main() {
    dbg!(Solution::count_smaller([5, 2, 6, 1].to_vec()));
}
