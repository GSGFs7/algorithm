#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 欧拉图
 *
 * 给出一条边和这条边的两个端点，求所有的边是否能全部连成一条线
 * 明显是个求欧拉图的题目
 * 先找出形成欧拉图必须要的条件是否符合
 *  1.入度和出度为单数的点只能有0或者2
 *  2.所有点相连
 * 题目还有一个难点，就是点的存储，可以用哈希大法，大幅减少代码量
 * */

const int N = 1e6 + 7;
int f[N];// 这个点的祖宗节点
int d[N];// 记录出度和入度
int seed = 10086;// 哈希种子
int mod = N;// 设置成和数组一样大，充分利用空间

// 并查集
int find(int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

// 哈希
int hash1(string s)
{
    int res = 0, len = s.length();
    for (int i = 0; i < len; i++)
        res = (res * seed + s[i]) % mod;// 乘法操作的空间开大点，避免炸掉
    return res;
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    string s1, s2;
    int cnt = 0;// 连通的组数
    int sum = 0;// 奇数度的个数
    while (cin >> s1 >> s2)// 处理两个点
    {
        int num1;
        num1 = hash1(s1);
        if (!d[num1] ++) f[num1] = num1, cnt ++;// 如果是个新点
        if (d[num1] & 1) sum ++;// 如果这个点是奇数点就加一
        else sum --;// 如果不是，就表明之前这个奇数点变成了偶数点

        int num2;// 这条边的另一个点也加入图中
        num2 = hash1(s2);
        if (!d[num2] ++) f[num2] = num2, cnt ++;
        if (d[num2] & 1) sum ++;
        else sum --;

        if (find(num1) != find(num2)) f[find(num1)] = find(num2), cnt --;// 如果原先不在同一个连通块中，合并
    }

    if (cnt < 2 && sum < 3) cout << "Possible\n";// 只有在入度和出度等于0（环）或者等于2（线）的时候才可以形成欧拉图
    else cout << "Impossible\n";
    return 0;
}


// https://www.luogu.com.cn/problem/P1333