#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int N = 12, M = 6;

bool explosion(vector<string>& board) {
	bool ret = false;
	vector<vector<bool>> check(N, vector<bool>(M, false));

	// 같은 알파벳 영역 탐색
	vector<vector<pair<int, int>>> route;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == '.' || check[i][j]) continue;

			vector<pair<int, int>> r;

			queue<pair<int, int>> q;
			q.push({ i,j });
			check[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();

				r.push_back({ x,y });
				for (int l = 0; l < 4; ++l) {
					int nx = x + dx[l], ny = y + dy[l];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (check[nx][ny] || board[x][y] != board[nx][ny]) continue;
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
			}
			route.push_back(r);
		}
	}

	// 크기가 4 이상인 영역은 연쇄
	for (int i = 0; i < route.size(); ++i) {
		if (route[i].size() < 4) continue;

		// 연쇄가 일어났다
		ret = true;
		for (int j = 0; j < route[i].size(); ++j) {
			int x = route[i][j].first, y = route[i][j].second;
			board[x][y] = '.';
		}
	}
	return ret;
}

void drop(vector<string>& board) {
	for (int j = 0; j < M; ++j) {
		string t = "";
		for (int i = N - 1; i >= 0; --i) {
			if (board[i][j] != '.')
				t.push_back(board[i][j]);
		}

		for (int i = 0; i < N; ++i) {
			if (i < t.size()) {
				board[N - 1 - i][j] = t[i];
			}
			else {
				board[N - 1 - i][j] = '.';
			}
		}
	}
}

void solve() {
	vector<string> board(N);
	for (int i = 0; i < N; ++i) {
		cin >> board[i];
	}

	int answer = 0;
	while (true) {
		if (!explosion(board)) {
			break;
		}
		answer += 1;
		drop(board);
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}