struct Solution;

/*
滑动窗口
*/

use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn count_of_substrings(word: String, k: i32) -> i64 {
        let vowels = HashSet::from(['a', 'e', 'i', 'o', 'u']);

        fn count(word: &str, k: i32, vowels: &HashSet<char>) -> i64 {
            let n = word.len();
            let mut res = 0;
            let mut consonants = 0;
            let mut occur = HashMap::<char, i32>::new();
            let mut r = 0;
            let word_chars: Vec<char> = word.chars().collect();
            for i in 0..n {
                while r < n && (consonants < k || occur.len() < 5) {
                    if vowels.contains(&word_chars[r]) {
                        *occur.entry(word_chars[r]).or_insert(0) += 1;
                    } else {
                        consonants += 1;
                    }
                    r += 1;
                }

                if consonants >= k && occur.len() == 5 {
                    res += (n - r + 1) as i64;
                }

                let left = word_chars[i];
                if vowels.contains(&left) {
                    if let Some(count) = occur.get_mut(&left) {
                        *count -= 1;
                        if *count == 0 {
                            occur.remove(&left);
                        }
                    }
                } else {
                    consonants -= 1;
                }
            }

            res
        }

        count(&word, k, &vowels) - count(&word, k + 1, &vowels)
    }
}

fn main() {
    println!(
        "{:#?}",
        Solution::count_of_substrings("ieaouqqieaouqq".to_string(), 1)
    );
}
