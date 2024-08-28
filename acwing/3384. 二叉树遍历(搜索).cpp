#include <iostream>
using namespace std;

int k;
string s;

// 输入输出一体化
void dfs()
{
    if (s[k] == '#') { k++; return; }

    char r = s[k++];// 当前这一层的值
    dfs();// 左子树
    cout << r << ' ';
    dfs();// 右子树
}

int main()
{
    cin >> s;
    dfs();
    return 0;
}