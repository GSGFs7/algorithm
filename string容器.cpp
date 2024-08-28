#include <iostream>
using namespace std;

int main()
{
    string a;
    a.clear();
    a = "abc";
    a.size();
    a.length();// 与a.size()一样
    a.empty();
    string b;
    a += b;
    a += 'c';
    cout << a.substr(1, 2) << endl;// 返回从1开始的两个字符，类似python的切片
    printf("%s\n", a.c_str());// 返回起始地址，printf可根据起始地址自动打印出整个字符串
    return 0;
}