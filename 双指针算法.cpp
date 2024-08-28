// 例：输出abc def ghi 中的每个字母

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[1000];

    gets(str);

    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && str[j] != ' ') j++;
        // 查找最后一个字母的位置

        for (int k = i; k < j; k++) cout << str[k] << ' ';
        cout << endl;

        i = j;
        // 前往下一个被空格划分的字符串
    }
    return 0;
}

/*
 * 双指针算法
 * 核心思想：
 * 将 for(int i = 0; i < n; i++)
 *      for(int j = 0; j < n; j++)
 *          ...
 * 复杂度为O(n^2)
 * 优化到O(n)
 *
 * 模板:
 *  for (int i = 0, j = 0; i < n; i++)
 *      while (j < i && check(i, j) j++;
 *      //依每道题的具体逻辑而定
 */