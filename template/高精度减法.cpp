#include <bits/stdc++.h>
#define int long long
using namespace std;

bool flag = false;
bool flag0 = false;

vector<int> sub(vector<int> & A, vector<int> & B)
{
    int len1 = A.size(), len2 = B.size();
    int maxLen = max(len1, len2);
    int minLen = min(len1, len2);
    vector<int> C(minLen);

    for (int i = 0; i < minLen; i++) C[i] = A[i]- B[i];
    if (len1 > len2)
    {
        for (int i = minLen; i < maxLen; i++) C.push_back(A[i]);
        for (int i = 0; i < maxLen; i++)
        {
            if (C[i] < 0) C[i + 1] --, C[i] += 10;
        }
        return C;
    }
    if (len1 < len2)
    {
        for (int i = minLen; i < maxLen; i++) C.push_back(-B[i]);
        for (int i = 0; i < maxLen; i++)
        {
            if (C[i] > 0) C[i + 1] ++, C[i] -= 10;
        }
        for (int i = 0; i < maxLen; i++) C[i] *= -1;
        flag = true;
        return C;
    }

    for (int i = 0; i < maxLen; i++)
    {
        int p = maxLen - 1;
        while (C[p] == 0) p--;
        if (p <= 0) return flag0 = true, C;
        if (C[p] < 0)
        {
            for (int j = 0; j < maxLen; j++)
            {
                if (C[i] > 0) C[i + 1] ++, C[i] -= 10;
            }
            for (int j = 0; j < maxLen; j++) C[i] *= -1;
            flag = true;
            return C;
        }
        else
        {
            for (int j = 0; j < maxLen; j++)
            {
                if (C[i] < 0) C[i + 1] --, C[i] += 10;
            }
            return C;
        }
    }
}

signed main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();

    vector<int> A(len1), B(len2);
    int cnt1 = len1, cnt2 = len2;
    for (int i = 0; i < len1; i++) A[i] = s1[--cnt1] - '0';
    for (int i = 0; i < len2; i++) B[i] = s2[--cnt2] - '0';

    auto ans = sub(A, B);

    if (flag) cout << '-';
    if (flag0) cout << 0 << endl;
    int p = max(len1, len2) - 1;
    while (ans[p] == 0) p--;
    for (int i = p; i >= 0; i--) cout << ans[i];
    return 0;
}