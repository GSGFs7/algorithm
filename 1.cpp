#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cases = 0;

void solve()
{
    cases ++;

    string s;
    cin >> s;
    int const n = s.size();
    vector<int> start;
    queue<int> end;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'K' && s[i + 1] == 'I' && s[i + 2] == 'C' && s[i + 3] == 'K')
            start.push_back(i);
        if (s[i] == 'S' && s[i + 1] == 'T' && s[i + 2] == 'A' && s[i + 3] == 'R' && s[i + 4] == 'T')
            end.push(i);
    }

    // debug
    // cout << "K:" << start.size() << "E:" << end.size() << endl;

    int ans = 0;
    int const len1 = start.size();
    for (int i = 0; i < len1; i++)// 以i为起点能够匹配到后面所有的终点，只要看一个i后面有几个终点即可
    {
        while (start[i] > end.front())
        {
            if (end.empty()) break;
            end.pop();
        }
        ans += end.size();
        if (end.empty()) break;
    }
    cout << "Case #" << cases << ": " << ans << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n --)
        solve();
    return 0;
}