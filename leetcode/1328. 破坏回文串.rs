/*
给出一个回文串, 改变一个字符后使其不再回文, 求字典序最小的方案

既然要字典序最小, 那么就要把不是a的字符转换为a
而且因为是回文串, 也就是说前后两半都是相等的, 只需要判断前面一半可不可以用a代替就好了
如果不行就在最后改为b
*/

struct Solution {}

impl Solution {
    pub fn break_palindrome(palindrome: String) -> String {
        let n: usize = palindrome.len();
        if n == 1 {
            return "".to_string();
        }

        // .chars() 方法将字符串装换为一个迭代器, 按序返回每个字符
        // .collect() 方法将迭代器中的元素收集到集合中
        let mut data: Vec<char> = palindrome.chars().collect();
        for i in 0..(n / 2) {
            if data[i] != 'a' {
                data[i] = 'a';
                return data.iter().collect::<String>();
            }
        }
        data[n - 1] = 'b';
        data.iter().collect()
    }
}

fn main() {
    println!("{}", Solution::break_palindrome(String::from("bbb")))
}


// https://leetcode.cn/problems/break-a-palindrome/description
// 2025-03-05 21:20