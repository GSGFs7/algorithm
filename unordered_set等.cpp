// unordered_set .... 与map和set类似 增删改查O(1)
// 不支持lower_bound()/upper_bound()和迭代器的 ++ --
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> s;
    std::lower_bound(s.begin(), s.end(),1);
}