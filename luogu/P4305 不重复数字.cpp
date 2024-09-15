#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> a;// unordered_set，无序set，不会进行排序，处理速度更快
// 堆 O(logn)比数组更快

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        a.clear();// 注意a是全局变量

        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (!(a.count(temp)))// 查找是否重复
            {
                cout << temp << ' ';
                a.insert(temp);// 加入不重复的数
            }
        }
        // puts(""); 不行？？
        // printf("\n"); 也不行？？
        cout << endl;
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P4305