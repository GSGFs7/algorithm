/*
 * 博弈论(game theory)
 * 组合博弈论：研究组合游戏
 *  特点：双人博弈，只有胜或者负，有限（不会无限进行下去）
 *  区分：平等博弈和不平等博弈（可操作的方式是否一样）
 *  很像结论题
 *
 * 必胜态和必败态 （无环，不会回到原来的状态）
 *
 * Nim游戏
 *
 * 先手必胜状态：可以走到某一个必败转态（对于下一步而言）
 * 先手必败状态：走不到任何一个必败状态
 * 异或和
 * a1^a2^...^an=x     如果=0的话先手必败 如果≠0的话先手必胜
 *
 * 如果上述x中最高位1在第k位
 * 那么必然存在一个ai的第k位是1
 * 拿走ai-(ai^x)个石子
 * 如果x不是0，那么一定存在一种方式，拿走ai后x为0
 *
 * 证明：  （异或的数学符号为⊕，程序符号为^，缩写为xor）
 * 操作到最后时，每堆石子数都是0，0⊕0⊕…0=0
 * 在操作过程中，如果 a1⊕a2⊕…⊕an=x≠0。那么玩家必然可以通过拿走某一堆若干个石子将异或结果变为0
 * 证明：不妨设x的二进制表示中最高一位1在第k位，那么在a1,a2,…,an中，必然有一个数ai，它的第k为时1，且
 * ai⊕x<ai ，那么从第i堆石子中拿走(ai−ai⊕x)个石子，第i堆石子还剩ai−(ai−ai⊕x)=ai⊕x，此时
 * a1⊕a2⊕…⊕ai⊕x⊕…⊕an=x⊕x=0
 * */

#include <iostream>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1, a; i < n; i++) {
        cin >> a;
        res ^= a;
    }

    if (res) puts("Yes");
    else puts("No");
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    solve();
    return 0;
}


// https://www.acwing.com/problem/content/893/