/// 巴什博弈
/*
 * n个石子，两个人去取，一次能取1~m个
 * 使先后手相加为m+1
 * 胜败分析：
 *  如果n%(m+1)=0必胜态，如果不等于为必败态
 * */

#include <iostream>
using namespace std;

/*
 * 假设现在只剩下了三张牌，那么先手只有1和2可选，选完后后手就能拿完所有的牌取得胜利
 * */

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n % 3) puts("Kiki");
        else puts("Cici");
    }
    return 0;
}


// http://acm.hdu.edu.cn/showproblem.php?pid=1847