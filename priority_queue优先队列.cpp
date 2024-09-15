// priority_queue 优先队列，本质是一个堆，默认是最大堆
// 让优先级高的排在前面，优先出队
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    priority_queue<int> q;
    q.push(1);// 插入到队尾并排序
    q.top();// 返回堆顶
    q.pop();// 弹出堆顶
    // q.clear()

    // 变成小根堆，插入-x
    int x = 2;
    q.push(-x);
    q.emplace();// 原地构造一个函数并插入队列

    // 定义小根堆，方法2
    priority_queue<int, vector<int>, greater<int>> heap;
    return 0;
}