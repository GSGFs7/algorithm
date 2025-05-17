struct Solution;

/*
挺有意思的一道题

给出三个颜色, 用0, 1, 2表示, 对他们进行原地排序, 要求一次遍历解决

如果只看前面的i个数的话, 假设我们在之前就已经得到了正确的序列, 如: [0,0,1,1,2]
那么如果在这个时候由遇到了一个0, 这个时候应该怎么办呢, 明显, 直接插入到队头就好了, 典型的插入排序, 但是, 这样的复杂度是O(n)的, 不可取.
观察插入后的序列, 原序列变成[0,0,0,1,1,2]. 表面上看就是整体往后移了一位, 但是如果只看变化的地方的话, 其实只有不同数的位置交界的地方发生了变化, 那么实际上只需要维护这个交界处的值就可以了
*/

impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut cnt0 = 0; // 0的个数
        let mut cnt1 = 0; // 1的个数
        for i in 0..nums.len() {
            let x = nums[i];
            nums[i] = 2; // 默认队尾就是2
            if x <= 1 {
                nums[cnt1] = 1;
                cnt1 += 1;
            }
            if x == 0 {
                nums[cnt0] = 0;
                cnt0 += 1;
            }
        }
    }
}

fn main() {
    let mut nums = vec![2, 0, 2, 1, 1, 0];
    Solution::sort_colors(&mut nums);
    println!("{:?}", nums);
}
