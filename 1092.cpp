#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	vector<int> pear;
	vector<int> crain;
	int N, M, result = 0;
	cin >> N;
	crain.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> crain[i];
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int x;
		cin >> x;
		pear.push_back(x);
	}
	sort(crain.begin(), crain.end());
	sort(pear.begin(), pear.end());
	if (pear[M - 1] > crain[N - 1]) {
		cout << -1;
		return;
	}

	while (!pear.empty()) {
		for (int i = N - 1; i >= 0; --i) {
			int j = M - 1;
			while (j >= 0 && pear[j] > crain[i]) {
				j -= 1;
			}
			if (j != -1) {
				pear.erase(pear.begin() + j);
				M -= 1;
			}
		}
		result += 1;
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
