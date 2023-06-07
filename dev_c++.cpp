#include <iostream>
#include <queue>
#include <cstring>
#define endl '\n'
using namespace std;

const int N = 110;
int a[N][N], b[N][N];
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs() {
	memset(&b, 0x3f, sizeof b);
	queue<pair<int, int>> q;
	q.emplace(1, 1);
	b[1][1] = 0;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int const xx = now.first + dx[i];
			int const yy = now.second + dy[i];

			if (xx < 1 || xx > n || yy < 1 || yy > m || a[xx][yy] == 1)
				continue;

			if (b[xx][yy] > b[now.first][now.second] + 1) {
				q.emplace(xx, yy);
				b[xx][yy] = b[now.first][now.second] + 1;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	bfs();

	return 0;
}