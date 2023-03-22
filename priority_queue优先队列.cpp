// priority_queue 优先队列 默认是最大堆
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    priority_queue<int> q;
    q.push(1);
    q.top();
    q.pop();// 弹出堆顶
    // q.clear()

    // 变成小根堆，插入-x
    int x = 2;
    q.push(-x);

    // 定义小根堆，方法2
    priority_queue<int, vector<int>, greater<int>> heap;
    return 0;
}