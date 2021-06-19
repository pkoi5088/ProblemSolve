#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int solve() {
	vector<int> priority, sumP;
	queue<int> q;
	int N, cnt = 1, goal;
	cin >> N >> goal;
	priority.resize(N, 0);
	sumP.resize(10, 0);
	for (int i = 0; i < N; i++) {
		cin >> priority[i];
		for (int j = 1; j < priority[i]; j++) {
			sumP[j] += 1;
		}
		q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (sumP[priority[now]] == 0) {
			if (now == goal)
				return cnt;
			for (int i = 1; i < priority[now]; i++)
				sumP[i] -= 1;
			cnt += 1;
		}
		else {
			q.push(now);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		cout << solve() << '\n';
	return 0;
}
