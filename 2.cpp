#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0, f = 0;
    for(int i = 0; i < n; i += 2) {
        if(s[i] == 'G' && s[i + 1] == 'H') {
            ans += f == 2;
            f = 1; //GH组合
        }
        if (s[i] == 'H' && s[i + 1] == 'G')
        {
            ans += f == 1;
            f = 2; //HG组合
        }
    }
    //最后一个是GH组合
    // if(f == 1 && ans > 0) ans++; wrong
    if(f == 1) ans++; //right
    cout << ans;

    return 0;
}