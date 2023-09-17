#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

void solve() {
	int N;
	cin >> N;
	vector<vector<int>> v(N, vector<int>(5));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> v[i][j];
		}
	}

	int winIdx = 0, winScore = -1;
	for (int idx = 0; idx < N; ++idx) {
		for (int x = 0; x < 5; ++x) {
			for (int y = x + 1; y < 5; ++y) {
				if (x == y) continue;
				for (int z = y + 1; z < 5; ++z) {
					if (x == z || y == z) continue;

					int score = (v[idx][x] + v[idx][y] + v[idx][z]) % 10;
					if (winScore < score) {
						winIdx = idx;
						winScore = score;
					}
					else if (winScore == score) {
						if (winIdx < idx) {
							winIdx = idx;
							winScore = score;
						}
					}
				}
			}
		}
	}
	cout << winIdx + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}