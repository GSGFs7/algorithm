#include <bits/stdc++.h>


class Solution {
public:
    int countTexts(std::string pressedKeys) {
        const int MOD = 1'000'000'007;
        const int n = pressedKeys.size();
        std::vector<long long> dp3 = {1, 1, 2, 4};
        std::vector<long long> dp4 = {1, 1, 2, 4};
        for (int i = 4; i <= n; i++) {
            dp3.push_back((dp3[i - 1] + dp3[i - 2] + dp3[i - 3]) % MOD);
            dp4.push_back((dp4[i - 1] + dp4[i - 2] + dp4[i - 3] + dp4[i - 4]) % MOD);
        }

        long long ans = 1;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (pressedKeys[i] == pressedKeys[i - 1]) {
                cnt++;
            } else {
                if (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') {
                    ans *= dp4[cnt];
                } else {
                    ans *= dp3[cnt];
                }
                ans %= MOD;
                cnt = 1;
            }
        }

        if (pressedKeys[n - 1] == '7' || pressedKeys[n - 1] == '9') {
            ans *= dp4[cnt];
        } else {
            ans *= dp3[cnt];
        }
        ans %= MOD;
        return ans;
    }
};

void solve() {
    Solution s;
    std::cout << s.countTexts("22233") << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
