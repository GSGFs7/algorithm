use std::collections::HashSet;

#[allow(unused_imports)]
use proconio::input;

fn main() {
    input! {
        s:String
    }

    let mut mp = HashSet::new();
    for i in s.chars() {
        mp.insert(i);
    }
    for i in 0..26 {
        if !mp.contains(&((b'a' + i as u8) as char)) {
            println!("{}", (b'a' + i as u8) as char);
            return;
        }
    }
}
