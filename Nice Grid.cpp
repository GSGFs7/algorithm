#include <iostream>
using namespace std;

//˼·�����е�ľ��룿

int main() {
    ios_base::sync_with_stdio(false);//�ر���stdio��ͬ�������������������ٶ�
    cin.tie(NULL);//���c++���п��������ݴ���󶨣�����������

    int r, c;
    cin >> r >> c;

    (max(abs(r - 8), abs(c - 8)) % 2 == 0) ? cout << "white" : cout << "black";
    //abs�����ֵ

}


//https://vjudge.net/problem/AtCoder-abc264_b/origin
