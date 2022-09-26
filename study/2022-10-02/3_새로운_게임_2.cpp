#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 12

using namespace std;

/*
	https://www.acmicpc.net/problem/17837
*/

pair<int, vector<pair<int, int>>> arr[MAX][MAX];
int N, K;
int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };

void findTarget(int t, int& x, int& y, int& idx) {
	for (x = 0; x < N; ++x) {
		for (y = 0; y < N; ++y) {
			for (idx = 0; idx < arr[x][y].second.size(); ++idx) {
				if (t == arr[x][y].second[idx].first)
					return;
			}
		}
	}
}

bool finish() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j].second.size() >= 4) {
				return true;
			}
		}
	}
	return false;
}

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j].first;
		}
	}

	for (int i = 1; i <= K; ++i) {
		int x, y, d;
		cin >> x >> y >> d;
		x -= 1, y -= 1, d -= 1;
		arr[x][y].second.push_back({ i,d });
	}

	int ret = 1;
	while (ret <= 1000) {
		for (int target = 1; target <= K; ++target) {
			int x = 0, y = 0, idx = 0;
			findTarget(target, x, y, idx);

			vector<pair<int, int>> tower;
			for (int i = idx; i < arr[x][y].second.size(); ++i)
				tower.push_back(arr[x][y].second[i]);
			for (int i = 0; i < tower.size(); ++i)
				arr[x][y].second.pop_back();

			//이동
			int count = 0;
			while (true) {
				int& dir = tower[0].second;
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny].first == 2) {
					if (count == 0) {
						count += 1;
						dir ^= 1;
						continue;
					}
					else {
						for (int i = 0; i < tower.size(); ++i) {
							arr[x][y].second.push_back(tower[i]);
						}
						break;
					}
				}
				else if (arr[nx][ny].first == 1) {
					reverse(tower.begin(), tower.end());
				}

				for (int i = 0; i < tower.size(); ++i) {
					arr[nx][ny].second.push_back(tower[i]);
				}
				break;
			}

			if (finish()) {
				cout << ret;
				return;
			}
		}
		ret += 1;
	}
	cout << -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}