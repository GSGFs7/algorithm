#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个空地, 在空地上从x到y连续放一层砖块, 求砖块的中位数

  思路:
    差分板子
*/

const int N = 1e6 + 10;
int a[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x]++;
        a[y + 1]--;
    }

    for (int i = 1; i < n; i++) a[i] = a[i - 1] + a[i];

    sort(a + 1, a + n + 1);

    cout << a[(n + 1) / 2] << '\n';
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


// https://www.matiji.net/exam/brushquestion/10/4498/F16DA07A4D99E21DFFEF46BD18FF68AD
// 2024年6月22日