// pair容器   可以存储一个二元组
// 支持比较运算 字典序
// 类似python的字典
#include <iostream>
using namespace std;

int main()
{
    pair<int, string> p;
    p.first;// 取得第一个元素
    p.second;// 取得第二个元素
    p = make_pair(10, "abc");
    p = {20, "cba"};
    pair<int, pair<int, string>> p1;// 可以存储三个不同的属性
    p1 = {10, {10, "abc"}};
}