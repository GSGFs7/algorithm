// queue队列
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.front();
    q.back();
    q.pop();
    q.size();
    // q.clear();没有clear函数
    q = queue<int>();// 重新构造
    return 0;
}