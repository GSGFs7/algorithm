#include <bits/stdc++.h>
using namespace std;

/*
 * DFS+剪枝
 *
 * DFS搜索符合条件的边，拼接起来继续去搜下一个木棍，如果拼不上就回溯
 * 时间限制280ms，必须要非常强效的剪枝
 * 确定优先级：因为木棒没有顺序的区分，所以优先解决较难的那部分，也就是灵活度较低的长木棒，
 *  如果长木棒就放不下了也就代表了其他的方法也放不下了
 * 基于优先级而产生的强效剪枝：
 *  1.如果最长的木棍就无法被拼接就不需要继续下去了
 *  2.如果当前的sum加上i刚好可以得到完整的木棒，但是并没有得到解，就表示拼法错误，需要回溯重拼（长木棒优先策略）
 *
 * 太优雅了！
 * */

const int N = 60;
int a[N];// 桶，存放各个数存在的个数
int maxn = 0, minn = 0x3f3f3f3f;// 限缩搜索范围

void DFS(int cur, int sum, int target, int top) {
    if (cur == 0) {
        cout << target << '\n';
        exit(0);
    }

    // 如果这个木棒已经拼接完成就去拼接下一个
    if (sum == target) {
        DFS(cur - 1, 0, target, maxn);
        return;
    }

    // 优先拼最大的，反正木棍没有先后顺序，先解决灵活性低的，如果最大的也无法解决就也代表了其他的拼法也是错的
    for (int i = top; i >= minn; i--)// 在限定的范围内搜索
        if (a[i] && sum + i <= target) {
            a[i]--;
            DFS(cur, sum + i, target, i);
            a[i]++;

            // 关键性优化，用于判断在该条件下是否成立，果然不成立就没必要进行下去了，不理解
            if (sum == 0 || sum + i == target) break;/// 妙啊
            // 如果第一次拼接就无法完成或者已经完成了一次搜索但是无法得到答案，就一直回溯

            // 1.
            // 如果发现在实现之后最大的那根木棍无法与其他的木棍拼成原木棍，
            // 则直接返回上一级拆了上一根原木棍重新拼，
            // 因为如果不这么做的话最长的那根木棍是永远无法拼成原木棍的
            // 2.
            // 若你在拼一个原木棒时还剩i个单位的长度没拼上时，
            // 恰好有一根长度就是i的木棒，那么优先选这个，
            // 但如果这根木棒拼进去后发现剩余的木棒是不能组合成原木棒的，那么直接返回失败，
            // 因为你要换这根木棒也只能换成长度更小的几段，使剩余木棒的灵活性反而更低，
            // 就更不可能拼成原木棒。所以直接返回去重做上一根原木棒。
        }
}

int main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x > 50) continue;

        a[x]++;
        sum += x;

        // 最大值和最小值
        maxn = max(maxn, x);
        minn = min(minn, x);
    }

    for (int i = 1; i <= sum; i++)
        if (sum % i == 0)// 必须能被整除才可能会有解
            DFS(sum / i, 0, i, maxn);
    return 0;
}


// https://www.luogu.com.cn/problem/P1120