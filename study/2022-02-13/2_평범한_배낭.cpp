#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/12865
*/

vector<vector<int>> v;
vector<pair<int, int>> bags;
int N, K;

void solve() {
	cin >> N >> K;
	v.resize(N + 1);
	bags.resize(N);
	for (int i = 0; i < N + 1; ++i) {
		v[i].resize(K + 1, 0);
	}
	for (int i = 0; i < N; ++i) {
		int W, V;
		cin >> W >> V;
		bags[i] = { W,V };
	}

	for (int i = 1; i < N + 1; ++i) {
		for (int j = 1; j < K + 1; ++j) {
			if (bags[i - 1].first <= j) {
				v[i][j] = max(v[i - 1][j - bags[i - 1].first] + bags[i - 1].second, v[i - 1][j]);
			}
			else {
				v[i][j] = v[i - 1][j];
			}
		}
	}
	cout << v[N][K];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
