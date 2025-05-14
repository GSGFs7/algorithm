struct Solution;

/*
好的子数组
*/

impl Solution {
    pub fn count_good(nums: Vec<i32>, k: i32) -> i64 {
        let n = nums.len();
        let mut ans = 0;
        let mut same = 0;
        let mut right = -1;
        let mut cnt = std::collections::HashMap::new();
        // 枚举左端点
        for left in 0..n {
            // 找到这个左端点的最小可用范围
            while same < k && right + 1 < n as i32 {
                right += 1;
                let num = nums[right as usize];
                let count = cnt.entry(num).or_insert(0);
                same += *count;
                *count += 1;
            }
            // 如果有可行方法, 那么这个方法有n-right个不同长度的解
            if same >= k {
                ans += (n as i64) - (right as i64);
            }
            let num = nums[left];
            *cnt.entry(num).or_insert(0) -= 1;
            same -= *cnt.get(&num).unwrap_or(&0);
        }

        ans
    }
}

fn main() {
    dbg!(Solution::count_good([1, 1, 1, 1, 1].to_vec(), 10));
}

// https://leetcode.cn/problems/count-the-number-of-good-subarrays
