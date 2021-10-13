#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	vector<int> length;
	string text;
	int N, M, t = 0, p = 0, result = 0;
	cin >> N >> M >> text;
	while (t <= M - (2 * N + 1)) {
		int cnt = 0;
		while (t < M && text[t] != 'I')
			t += 1;

		if (t > M - (2 * N + 1))
			break;

		while (text[t + 1] == 'O' && text[t + 2] == 'I') {
			cnt += 1;
			t += 2;
		}

		if (cnt != 0)
			length.push_back(cnt);
		t += 1;
	}

	for (int i = 0; i < length.size(); i++) {
		if (N <= length[i]) {
			result += length[i] - N + 1;
		}
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
