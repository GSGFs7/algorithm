#include <iostream>
#include <string>
using namespace std;

int main()
{
    int ans = 0, w = -1;
    string a, b;
    // 读入行
    getline(cin, a);
    getline(cin, b);

    // 转小写
    for (auto & i : a) if (i >= 'A' && i <= 'Z') i += 'a' - 'A';
    for (auto & i : b) if (i >= 'A' && i <= 'Z') i += 'a' - 'A';

/*    cout << a << endl;
    cout << b << endl;*/

    // 匹配
    for (int i = 0; i < b.size(); i++)
    {
        // 先检查第一个字母
        if (b[0] == a[0])// 当第一个单词就匹配时
        {
            int j;
            for (j = 0; j < a.size(); j++)
                if (b[i + j] != a[j]) break;
            if (j == a.size() && b[i + j] == ' ')
            {
                ans++;
                if (w == -1) w = i;
            }
        }
        else// 中间的单词，需要检查前后是否有空格
        {
            if (b[i] == ' ' && b[i+1] == a[0])
            {
                i++;// 向后推一位！！！不然是从空格开始的，后面的全部错位
                // 进一步检查是否完全匹配
                int j;
                for (j = 0; j < a.size(); j++)
                    if (b[i + j] != a[j]) break;
                if (j == a.size() && b[i + j] == ' ')// 检查后空格，单词长度是否对应
                {
                    ans++;
                    if (w == -1) w = i;// 第一个位置
                }
            }
        }
    }

    if (ans == 0) cout << -1;
    else cout << ans << ' ' << w;
    return 0;
}