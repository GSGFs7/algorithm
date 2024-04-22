//#include "bits/stdc++.h" // 万能头本地编译时间较长
#include <iostream>

using namespace std;
#define int long long

/*
 * 题目描述:
 *  有A和B两个棋子,A棋子可以向左下,正下,右下移动,B棋子可以向左上,正上,右上移动.A先手,求谁会吃掉另一方
 * 输入:
 *  一行四个整数h,w,x1,y1,x2,y2代表棋盘大小,A,B的初始位置.
 * 输出:
 *  一行一个字符串,表示谁会吃掉另一方.
 *
 * 思路:
 *  因为要胜出,各自会选择最优方案,这样在未抵达边界的时候A和B相当于相对静止,
 *  所以必须双方必须都能抵达边界,这样才会有人胜出
 *  原本的追逐问题即可转化为路径长短的比较问题,如果追逐方能够抵达边界,那么必胜
 *  可以简单的写为 step*2<=dis   ,其中step为到边界所需的步数,dis为纵向距离
 * 注意:
 *  but,还有一种情况,按照步数的方法,A和B的步数相等,如果dis为奇数,那么他们在面对面的时候会停下来
 *  下一步应该由A走出,即为A获胜,可以在dis那一边加上1来解决,即 step*2<=dis+1
 * */

void solve() {
    int h, w, x1, y1, x2, y2;
    cin >> h >> w >> x1 >> y1 >> x2 >> y2;

    // 特判
    if (x1 >= x2) return cout << "Draw" << '\n', void();

    int dis = x2 - x1;
    if (dis & 1) { // 如果是A追B
        if (abs(y1 - y2) <= 1) {// 特判
            return cout << "Alice" << '\n', void();
        }

        if (y1 > y2) { // b向左逃
            int step = y1 - 1;// a可以向左走的次数
            if (step * 2 - 1 <= dis) return cout << "Alice" << '\n', void();// 如果可以把b逼进边界,并且自己可以抵达边界
            // 也就是说明了a可以吃掉b,反之他们一直相对静止,不能相遇
        } else { // b向右逃
            int step = w - y1;// 是横向边界,别搞反了
            if (step * 2 - 1 <= dis) return cout << "Alice" << '\n', void();// a先手,某些时候可以多走一步
        }
    } else { // 如果是B追A
        if (y1 == y2) {
            return cout << "Bob" << '\n', void();
        }

        if (y1 > y2) { // 如果a向右逃
            int step = w - y2;
            if (step * 2 <= dis) return cout << "Bob" << '\n', void();
        } else {
            int step = y2 - 1;
            if (step * 2 <= dis) return cout << "Bob" << '\n', void();
        }
    }

    cout << "Draw" << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1921/problem/E