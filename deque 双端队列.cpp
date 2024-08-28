// deque 双端队列 强大的数组，几乎有其他所有数组数组有的功能，但速度较慢
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> a;
    a.size();
    a.empty();
    a.front();
    a.back();
    a.push_back(1);// 队尾插入
    a.push_front(1);// 队头插入
    a.begin();
    a.end();
    return 0;
}