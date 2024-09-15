#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出n个数，求一个k使得这n个数模k只有两个结果
 *
 * 二进制
 * 把每个数边成二进制后，每个数模上2的几次方就是取这个数的最后几位，100010模4就是10
 * 只需要依次检查后面有多少位相同的就可以了，因为2进制在不同处就只有两种变化，正好题目求的就是两种变化，妙啊~
 *
 * 递推的方法证明：
 *  1 2 3 4 5 6 7 8 9 10    对于这组数，k=2   分别是：0 1
 *  2 4 6 8 10              对于这组数，k=4   分别是：0 2
 *  4 8                     对于这组数，k=8   分别是：0 4  奇数同理，只是最后0变成了1，4变成了其他的
 * 也就是说只用计算2的次方级就可以了，如果不是的话在前面就会淘汰掉，每次的时间复杂度是O(log(max(a[i]))
 * */

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    for (int i = 2; i; i <<= 1)// 之前也想到了这样，但是证明不了就放弃了，我真蠢！
    {
        map<int, bool> mp;// 用map实现，效率好像不是很高。
        int cnt = 0;
        for (auto j : a)
        {
            if (!mp[j % i])
            {
                mp[j % i] = true;
                cnt ++;

                if (cnt > 2) break;
            }
        }

        if (cnt == 2) return cout << i << '\n', void();
    }
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int start = clock();

    int t;
    cin >> t;
    while (t--)
        solve();

//    cout << clock() - start << '\n';
    return 0;
}


// https://codeforces.com/contest/1909/problem/B