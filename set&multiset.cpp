// set
#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;// 不可重复，重复会被忽略
    multiset<int> ms;// 可重复

    s.size();
    s.empty();
    s.clear();
    s.insert(1);
    s.find(1);
    s.count(1);
    ms.count(1);
    s.erase(1);// 1.输入一个数x，删除所有x   2.输入一个迭代器，删除这个迭代器  O(k + logn)
    // 相当于上下边界
    s.lower_bound(1);// 返回大于x的最小的数，返回迭代器
    s.upper_bound(1);// 返回小于x的最大的数，返回迭代器
    return 0;
}