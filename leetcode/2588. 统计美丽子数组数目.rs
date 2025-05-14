struct Solution {}

impl Solution {
    pub fn beautiful_subarrays(nums: Vec<i32>) -> i64 {
        let mut mp: std::collections::HashMap<i32, i32> = std::collections::HashMap::new();
        let mut ans: i64 = 0;
        let mut xor_sum: i32 = 0; // 前缀异或和

        // 初始化
        mp.insert(0, 1);

        for &num in &nums {
            xor_sum ^= num;

            // 如果出现相同的前缀异或和
            // 好抽象的语法...
            // 因为 mp.get() 返回的是 Option<&i32> 类型
            // 可能有值, 也可能没有, 需要用 let Some(&count) 来接收
            // if let Some(&count) = ... 是 rust 的模式匹配语法
            // &count 将引用解构为具体的值
            // if 只在返回 Some 里的值的时候执行里面的语句
            if let Some(&count) = mp.get(&xor_sum) {
                ans += count as i64;
            }

            // 更新出现次数
            // mp.entry(xor_sum) 访问具体的条目, 返回一个 Entry 对象
            // or_insert(0) 如果值存在, 返回可变引用
            // 如果不存在就插入一个值0, 再返回一个可变引用
            // mp前的 * 表示解引用, 配合后面的 += 1更改这个值
            *mp.entry(xor_sum).or_insert(0) += 1;
        }
        ans
    }
}

fn main() {
    println!("{}", Solution::beautiful_subarrays(vec![4, 3, 1, 2, 4]));
}

//https://leetcode.cn/problems/count-the-number-of-beautiful-subarrays
// 2025-03-07
