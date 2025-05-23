#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {    // 枚举长度
        if (n % i == 0) {             // 只有能被完全划分才有答案
            int satisfy = 2;
            for (int j = 0; j < i; j++) {               // 字符串的匹配
                for (int k = j + i; k < n; k += i) {    //
                    if (s[k] != s[j]) {
                        satisfy--;
                    }
                }
            }

            if (satisfy > 0) {
                cout << i << endl;
                return;
            }

            satisfy = 2;
            for (int j = n - i; j < n; j++) {    // 两次机会
                for (int k = j - i; k >= 0; k -= i) {
                    if (s[k] != s[j]) {
                        satisfy--;
                    }
                }
            }

            if (satisfy > 0) {
                cout << i << endl;
                return;
            }
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}