#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

struct rotateSetting {
	int r, c, s;
	rotateSetting(int ir, int ic, int is) {
		r = ir, c = ic, s = is;
	}
};

vector<rotateSetting> v;
vector<bool> check;
int N, M, K, answer = 2000000000;

void Rotate(vector<vector<int>>& board, int idx) {
	int r = v[idx].r - 1, c = v[idx].c - 1, s = v[idx].s;

	while (s) {
		int tmp = board[r - s][c - s];

		// 왼
		for (int x = r - s; x < r + s; ++x) {
			board[x][c - s] = board[x + 1][c - s];
		}

		// 아래
		for (int y = c - s; y < c + s; ++y) {
			board[r + s][y] = board[r + s][y + 1];
		}

		// 오
		for (int x = r + s; x > r - s; --x) {
			board[x][c + s] = board[x - 1][c + s];
		}

		// 위
		for (int y = c + s; y > c - s+1; --y) {
			board[r - s][y] = board[r - s][y - 1];
		}
		board[r - s][c - s + 1] = tmp;
		s -= 1;
	}
}

void RotateCal(vector<vector<int>> A, int rotateCount) {
	if (rotateCount >= K) {
		// answer 갱신
		for (int i = 0; i < N; ++i) {
			int t = 0;
			for (int j = 0; j < M; ++j) {
				t += A[i][j];
			}
			answer = min(answer, t);
		}
		return;
	}

	for (int i = 0; i < K; ++i) {
		if (check[i]) continue;

		vector<vector<int>> next(A);

		Rotate(next, i);
		check[i] = true;
		RotateCal(next, rotateCount + 1);
		check[i] = false;
	}
}

void solve() {
	cin >> N >> M >> K;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < K; ++i) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back(rotateSetting(r, c, s));
	}
	check.resize(K, false);

	RotateCal(A, 0);
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}