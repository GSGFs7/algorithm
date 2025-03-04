/*
  给出一个字符串, 将这个字符串全部切分为回文串后的最小数量
*/

use std::vec;

fn main() {
    solve(String::from("cabababcbc"));
}

///
/// 检查字符串在某个位置上是否是回文的
///
fn check(f: &mut [Vec<bool>], bytes: &[u8], n: usize) {
    for i in (1..(n + 1)).rev() {
        for j in ((i + 1)..(n + 1)).rev() {
            f[i][j] = (bytes[i] == bytes[j]) && f[i + 1][j - 1];
            f[j][i] = f[i][j];
        }
    }
}

///
/// dp计算到某个位置上花费的最小值
///
fn dp(f: &mut [Vec<bool>], g: &mut [i32], n: usize) {
    g[0] = 0;
    for i in 1..(n + 1) {
        for j in 1..(i + 1) {
            if f[i][j] {
                g[i] = std::cmp::min(g[i], g[j - 1] + 1);
            }
        }
    }
}

fn solve(mut s: String) -> i32 {
    let n = s.len();
    s.insert(0, ' ');

    let bytes = s.as_bytes(); // rust的string不支持直接索引
    let mut f = vec![vec![true; n + 1]; n + 1];
    check(&mut f, bytes, n);

    let mut g = vec![1e9 as i32; n + 1];
    dp(&mut f, &mut g, n);

    g[n] - 1
}

// https://leetcode.cn/problems/palindrome-partitioning-ii/description/
