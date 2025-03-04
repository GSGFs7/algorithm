/*
  给出 n, m 两个数字, 问是否可以获得由 n个1和m个0 组成的字符串
  并且字符串的子串满足 max(x-y, y-x) <= k
*/

use std::{
    cmp::{self, max},
    io,
};

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
    let mut t: u32 = input.trim().parse().expect("");

    while t > 0 {
        t -= 1;
        solve();
    }
}

fn solve() {
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
    let a: Vec<i32> = input
        .split_whitespace() // 以空格拆开
        .map(|x| x.parse().expect("msg")) // 每个都转换为 i32
        .collect(); // 收集为数组
                    // println!("{:?}", a);

    let [mut n, mut m, k] = a.try_into().expect("msg"); // 模式切片
                                                        // println!("{} {} {}", n, m, k);
    if k < (n - m).abs() || k > max(n, m) {
        println!("-1");
        return;
    }

    let mut ans = String::new();
    let mut order = m > n;
    while n > 0 || m > 0 {
        if order & true {
            ans.push_str(&"1".repeat(cmp::min(k, m) as usize));
            m -= cmp::min(k, m);
        } else {
            ans.push_str(&"0".repeat(cmp::min(k, n) as usize));
            n -= cmp::min(k, n);
        }
        order = !order;
    }
    println!("{ans}");
}
