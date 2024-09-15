// map
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> m;
    m.insert(pair<string, int>("cba", 100));// 插入的数是一个pair
    m.find("abc");
    auto iter = m.find("cba");
    m.erase(iter);// 输入的参数是pair或者迭代器
    m["abc"] = 1;// 像使用数组一样使用map O[logn]
    m.lower_bound("abc");
    m.upper_bound("cba");
    m.begin();
    m.end();// O(logn)
}