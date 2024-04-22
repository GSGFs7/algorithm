#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int xn[N], ynn[N];// yn会重定义
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<int> path;
bool vis[N][N];

void dfs(int x, int y, int step) {
	if (x == n && y == n) {
		for (int i = 1; i <= n; i++) {
			if (xn[i] || ynn[i]) {
				return ;
			}
		}
		
		for (auto i : path) cout << i << ' ';
		exit(0);
	}
	
//	cout << x << ' ' << y << '\n';
	
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if (!vis[xx][yy] && xn[xx] && ynn[yy]) {
			vis[xx][yy] = true;
			xn[xx] --;
			ynn[yy] --;
			path.push_back((xx - 1) * n + yy - 1);
			dfs(xx, yy, step + 1);
			path.pop_back();
			ynn[yy] ++;
			xn[xx] ++;
			vis[xx][yy] = false;
		}
	}
}

signed main(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ynn[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> xn[i];
	}
	
	memset(&vis, false, sizeof vis);
	
	xn[1] --;
	ynn[1] --;
	path.push_back(0);
	dfs(1, 1, 1);
	
	return 0;
}


// https://www.luogu.com.cn/problem/P8642
// 2024年4月8日