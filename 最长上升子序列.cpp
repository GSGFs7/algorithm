#include <iostream>
using namespace std;

/// 最长上升子序列
/*
 * 模板题
 *
 * 状态表示：
 *  集合：以第i个数结尾的上升子序列的集合
 *  属性：Max
 * 状态计算：
 *  以上一位数取的值为状态
 *  以j结尾的最大值加上1
 *  f[i] = max(f[j]+1),    j=0,1,2,3,4...i-1
 * 
 * 核心思想就是按照从前往后的顺序DP，一直往后面加数
 * 如果这个数正好有方法可以延长其中一个序列就更新为最大的值
 * */

const int N = 1010;
int a[N], f[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        f[i] = 1;// 最少都有1个（这个数自己）
        for (int j = 1; j < i; j++)// 对于每一步，取自己能够取到的最大值，扫一遍前面得到最大的数
            if (a[j] < a[i])// 如果小于就加在这个数后面，取一次最大值   a[i]才是后面那个数！
                f[i] = max(f[i], f[j] + 1);// 每次取值不能小于1
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, f[i]);// 寻找最大值

    cout << res << endl;
    return 0;
}


// 2023.8.13 二刷
//#include <iostream>
//using namespace std;
//
///*
// * 最长上升子序列
// *
// * 从一个序列中按照原序列取出一些元素
// * 求取出元素按递增排列的最大长度
// *
// * 先求出前面每一步的最大值
// * 然后再从后向前扫一遍，取能够得到的最大值
// *
// * 两个状态：
// *  1.当前已经得到了的最大值
// *  2.向前扫到的最大值+1
// * */
//
//const int N = 5010;
//int a[N], f[N];
//
//int main() {
//#ifdef __LOCAL__
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
//#endif
//
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i ++)
//        cin >> a[i];
//
//    for (int i = 1; i <= n; i++) {
//        f[i] = 1;// 初始化
//        for (int j = 1; j < i; j++)// 对于每一步，取自己能够取到的最大值，扫一遍前面得到最大的数
//            if (a[i] > a[j])
//                f[i] = max(f[i], f[j] + 1);
//    }
//
//    int ans = -0x3f3f3f3f;
//    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);// 寻找最大值
//    cout << ans << '\n';
//    return 0;
//}