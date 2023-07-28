#include <cstdio>
#include <cstring>
#include <algorithm>
#define getb(i, j) i / 3 * 3 + j / 3

using namespace std;

const int wei[9][9] = {
{6,6,6,6,6,6,6,6,6,},
{6,7,7,7,7,7,7,7,6,},
{6,7,8,8,8,8,8,7,6,},
{6,7,8,9,9,9,8,7,6,},
{6,7,8,9,10,9,8,7,6},
{6,7,8,9,9,9,8,7,6,},
{6,7,8,8,8,8,8,7,6,},
{6,7,7,7,7,7,7,7,6,},
{6,6,6,6,6,6,6,6,6,},
};

int a[10][10], hapi[10][10], hapj[10][10], hapb[10][10], num[10], rnk[10], ans;

bool comp1(int a, int b) {
	return num[a] < num[b];
}

void dfs(int cur, int sum, int la) {
	if(cur == 81) {
		ans = max(ans, sum);
		return;
	}
	if(sum +  9 + la * 9 <= ans) return; 

	int i = rnk[cur/9], j = cur % 9, b = getb(i, j);
	if(a[i][j]) dfs(cur+1, sum+a[i][j]*wei[i][j], la-a[i][j]);
	else for(int k = 1; k <= 9; k++) {
		if(!hapi[i][k] && !hapj[j][k] && !hapb[b][k]) {
			hapi[i][k] = hapj[j][k] = hapb[b][k] = 1;
			dfs(cur+1, sum+k*wei[i][j], la-k);
			hapi[i][k] = hapj[j][k] = hapb[b][k] = 0;
		}
	}
}

int main() {
	ans = -1;
	memset(hapi, 0, sizeof(hapi));
	memset(hapj, 0, sizeof(hapj));
	memset(hapb, 0, sizeof(hapb));
	memset(num, 0, sizeof(num));

	for(int i = 0; i < 9; i++) {
		rnk[i] = i;
		for(int j = 0; j < 9; j++) {
			scanf("%d", &a[i][j]);
			if(a[i][j])
				hapi[i][a[i][j]] = hapj[j][a[i][j]] = hapb[getb(i, j)][a[i][j]] = 1;
			else
				num[i]++;
		}
	}
    
	sort(rnk, rnk+9, comp1);
	dfs(0, 0, 405);
	printf("%d\n", ans);
	return 0;
}