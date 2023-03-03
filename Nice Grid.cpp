#include <iostream>
using namespace std;

//思路：到中点的距离？

int main() {
    ios_base::sync_with_stdio(false);//关闭与stdio的同步以提升读入和输出的速度
    cin.tie(NULL);//解除c++运行库层面的数据传输绑定，以提升性能

    int r, c;
    cin >> r >> c;

    (max(abs(r - 8), abs(c - 8)) % 2 == 0) ? cout << "white" : cout << "black";
    //abs求绝对值

}


//https://vjudge.net/problem/AtCoder-abc264_b/origin
