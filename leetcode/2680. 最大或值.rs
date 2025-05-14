struct Solution;

/*
给出一个数组, 可以对数组中的一个数乘以2, 操作k次, 问数组最大的或值.

上面的问题可以理解成: 一个数将这个数左移k次, 如何使最后的结果相与最大化?
首先, 需要明确一点, 怎样使最后的结果最大化?
对于 (100)_b 和 (11)_b 这两个数来说, 如果想要最大化他们的结果那么肯定选择 (100)_b 比较划算, 因为可以多出一位
但是最大的数不一定是最优的, 可以中间的数重复, 导致中间的值没有贡献
直接对最高为暴力跑所有的结果, 取最大值即可
*/

impl Solution {
    pub fn maximum_or(nums: Vec<i32>, k: i32) -> i64 {
        let mut ans: i64 = 0;
        let mut nums: Vec<i32> = nums; // 需要所有权, 复制一份
        let mut bits: Vec<i32> = vec![0; 64]; // 记录每一位上有几个1, 只需维护这个数组即可

        // 添加一个数到 bits
        let add_bit = |x: i64, bits: &mut Vec<i32>| {
            let mut tmp = x;
            let mut index = 0;
            loop {
                if tmp & 1 == 1 {
                    bits[index] += 1;
                }

                tmp >>= 1;
                index += 1;

                if tmp == 0 {
                    break;
                }
            }
        };

        // 从 bits 里删除一个数
        let del_bit = |x: i64, bits: &mut Vec<i32>| {
            let mut tmp = x;
            let mut index = 0;
            loop {
                if tmp & 1 == 1 {
                    bits[index] -= 1;
                }

                tmp >>= 1;
                index += 1;

                if tmp == 0 {
                    break;
                }
            }
        };

        // 最高位
        let high_bit = |x: i32| -> i32 {
            let mut base = 1;
            loop {
                if (base << 1) > x {
                    return base;
                }
                base <<= 1
            }
        };

        nums.sort();

        // 预处理, 先把所有数加到 bits 里
        for i in nums.iter() {
            add_bit(*i as i64, &mut bits);
        }

        let maxn = high_bit(*nums.last().unwrap());
        for i in nums.iter().rev() {
            // 如果最高位已经不是1了, 直接退出
            if high_bit(*i) != maxn {
                break;
            }

            // 修改 bits 为扩大后的情况
            del_bit(*i as i64, &mut bits); // 数据范围 1e9, 左移 15 次可能会变负数, 需要 i64
            add_bit((*i as i64) << (k as i64), &mut bits);

            // 看是不是最大值
            ans = std::cmp::max(ans, {
                let mut res = 0;
                let mut base = 1;
                for i in bits.iter() {
                    res += if *i >= 1 { base } else { 0 };
                    base <<= 1;
                }
                res
            });

            // 还原, 准备下次处理
            add_bit(*i as i64, &mut bits);
            del_bit((*i as i64) << (k as i64), &mut bits);
        }

        ans
    }
}

fn main() {
    println!("{}", Solution::maximum_or(vec![8, 1, 2], 2))
}
