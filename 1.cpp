/*
 * STL
 *
 * vector   边长数组，倍增思想
 * string   字符串：substr(), c_str()
 * queue   队列： push(), front(), pop()
 * priority_queue   优先队列：push(), top(), pop()
 * stack   栈：push(), top(), pop()
 * deque   双端队列支持随机访问
 * set, map, multiset, multimap   基于平衡二叉树，动态维护有序序列
 * unordered_set, unordered_map, unordered_multiset, unordered_multimap   基于哈希表
 * bitset   压位
 * pair
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;// 初始化vector数组a
    vector<int> b(10);// 设定初始长度
    vector<int> c(10, 3);// 定义一个长度为10的vector，里面每个数都为3
    vector<int> d[10];// 定义10个vector，类似二维数组

    // 下面两个函数是所有容器都有的
    b.size();// 返回元素个数
    b.empty();// 返回b是否为空

    b.clear();// 清空
    c.front();// 返回第一个数
    c.back();// 返回最后一个数
    c.push_back(1);// 向最后插入一个数
    c.pop_back();// 删除最后一个数
    c.begin();// 迭代器，返回第一个数
    c.end();// 迭代器，返回最后一个数的下一位

    // 系统为某一个程序分配空间时，所需时间与空间大小无关，与申请次数有关
    // 所以vector会尽量减少申请次数，浪费一定的空间
    // 当空间不够时，vector开辟一个新的空间，大小为之前的两被，再将原来的数组复制到新的数组中

    // 遍历
    for (int i = 0; i < 10; i++) a.push_back(i);
    for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
    cout << endl;
    for (vector<int>::iterator i = a.begin(); i != a.end(); i++) cout << *i << ' ';
    cout << endl;
    for (auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';// 与上面一致
    cout << endl;
    for (auto x : c) cout << x << endl;// auto可以遍历所有容器

    // 比较运算
    vector<int> e(4, 3), f(3, 4);
    if (a < b) puts("a < b");// 字典序

    return 0;
}