#include <iostream>
#define MAX 101
#define endl '\n'

using namespace std;

int num[MAX];

bool isInCycle(int n) {
	bool visit[MAX] = { false };
	visit[n] = true;
	int now = num[n];
	while (visit[now] == false) {
		visit[now] = true;
		now = num[now];
	}
	return now == n;
}

void solve() {
	int N, ret[MAX], idx = 0;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> num[i];
	}

	for (int i = 1; i <= N; ++i) {
		if (isInCycle(i)) {
			ret[idx++] = i;
		}
	}
	cout << idx << endl;
	for (int i = 0; i < idx; ++i) {
		cout << ret[i] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
