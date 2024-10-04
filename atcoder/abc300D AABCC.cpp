#include <iostream>

using namespace std;

/*
  给出一个N，求有多少个a,b,c符合 a^2*b*c^2<N
  N<=1e12

  最简单的思路直接筛出1e6之内所有的素数，然后三重循环大力跑
  因为在极限情况下，也就是a和b最小，c最大即使最大的c也不会超过1e6
  但是这样肯定是会TLE的，复杂度达到了O(n^2)
  所以思考更加优化的方法
  每次可以只枚举两个点的方法
  其实是可行的，每次枚举a和b两个点，c直接从最后开始向前缩小范围
  如果大于N直接跳过，
  如果找到了一个可能的k，也就是说明所有小的k也都可行，全部加上
  最后能优化掉很多k的枚举
*/

#define int long long

const int N = 1e6 + 10;// 其实3e5就可以了，1e6会到950ms，3e5是121ms
int primes[N];
bool st[N];
int cnt = 0;

void get_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    get_prime(N - 1);

    // 三重循环跑不动，需要优化
    // vector<int> a;
    // for (int i = 0; i < cnt; i++) {
    //     for (int j = i + 1; j < cnt; j++) {
    //         for (int k = j + 1; k < cnt; k++) {
    //             int now = (__int128)1 * primes[i] * primes[i] * primes[j];
    //             if (now > n) continue;
    //             now *= primes[k];
    //             if (now > n) continue;
    //             now *= primes[k];
    //             if (now > n) continue;
    //             a.push_back(now);
    //         }
    //     }
    // }
    // cout << a.size();

    int ans = 0;
    for (int i = 0; i < cnt; i++) {
        int k = cnt - 1;
        for (int j = i + 1; j < k && j < cnt; j++) {
            while (j < k) {
                int now = primes[i] * primes[i] * primes[j];
                if (now > n) {
                    k--;
                    continue;
                }
                now *= primes[k];
                if (now > n) {
                    k--;
                    continue;
                }
                now *= primes[k];
                if (now > n) {
                    k--;
                    continue;
                }
                break;
            }
            ans += k - j;
        }
    }
    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://atcoder.jp/contests/abc300/tasks/abc300_d
// 2024-09-20