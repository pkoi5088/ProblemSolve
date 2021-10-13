#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> M;

void solve() {
	int N, m;
	cin >> N >> m;
	M.resize(N + 1);
	for (int i = 0; i < N + 1; i++) {
		M[i].resize(N + 1, 0);
	}
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			int x;
			cin >> x;
			M[i][j] = M[i][j - 1] + M[i - 1][j] - M[i - 1][j - 1] + x;
		}
	}
	while (m--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << M[x2][y2] - M[x2][y1 - 1] - M[x1 - 1][y2] + M[x1 - 1][y1 - 1] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}