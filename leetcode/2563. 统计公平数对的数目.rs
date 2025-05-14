struct Solution;

/*
给出一个数组和一个区间, 问从数组中取两个数, 有多少种方法使他们的和落在区间中

从小到大排序后可选区间就有了单调性, 直接从大到小移动区间指针即可
*/

impl Solution {
    pub fn count_fair_pairs(mut nums: Vec<i32>, lower: i32, upper: i32) -> i64 {
        nums.sort_unstable();
        let mut ans = 0;
        let mut l = nums.len();
        let mut r = nums.len();
        for (j, &x) in nums.iter().enumerate() {
            // 向左移到范围内
            while r > 0 && nums[r - 1] > upper - x {
                r -= 1;
            }
            while l > 0 && nums[l - 1] >= lower - x {
                l -= 1;
            }
            ans += r.min(j) - l.min(j);
        }
        ans as _
    }
}

fn main() {
    dbg!(Solution::count_fair_pairs(
        [0, 1, 7, 4, 4, 5].to_vec(),
        3,
        6
    ));
}

// https://leetcode.cn/problems/count-the-number-of-fair-pairs
