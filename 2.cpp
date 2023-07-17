#include <iostream>

using namespace std;

const int N = 100010;
pair<int, int> stk[N];// 栈
int ans[N];

int main() {
	int n, m, top = 0;
	cin >> n >> m;
	while (m--) {
		int p, q;
		cin >> p >> q;
		if (p == 0) {
			// 如果栈不空，并且是前缀操作
			while (top && stk[top].first == 0) q = max(q, stk[top--].second);
			// 如果当前操作比上一次相同操作的范围要大，那此次操作的前两次操作都将被无效化 
			// 删掉前缀范围小的操作
			while (top >= 2 && stk[top - 1].second <= q) top -= 2;
			stk[++top] = {0, q};// 将操作加入栈
		} else if (top) {// 后缀升序操作，需要栈非空时才有作用
			// 如果栈顶操作跟现在的一样
			while (top && stk[top].first == 1) q = min(q, stk[top--].second);
			// 如果当前操作比上一次相同操作的范围要大，那此次操作的前两次操作都将被无效化 
			// 删掉后缀范围小的操作
			while (top >= 2 && stk[top - 1].second >= q) top -= 2;
			stk[++top] = {1, q};// 加入操作
		}
	}

	// 每次缩小范围，倒着填入数字
	int left = 1, right = n, k = n;
	for (int i = 1; i < top + 1; i++) {
		// 左右向中间靠拢
		if (stk[i].first == 0) {
			while (right > stk[i].second && left < right + 1) {
				ans[right--] = k--;
			}
		} else {
			while (left < stk[i].second && left < right + 1) {
				ans[left++] = k--;
			}
		}
		// 如果已经填完了所有的数
		if (left > right) {
			break;
		}
	}

	// 如果没有填完
	if (top % 2) {// 如果是奇数，做完了有区间
		while (left < right + 1) {// 降序
			ans[left++] = k--;
		}
	} else {
		while (left < right + 1) {
			ans[right--] = k--;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
