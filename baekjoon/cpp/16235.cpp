#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 10
#define endl '\n'

using namespace std;

struct Node {
	vector<int> tree;
	int food;
	queue<int> dead, live;
};

Node map[MAX][MAX];
int A[MAX][MAX], dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 };
int N, M, K;

void solve() {
	int ret = 0;
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
			map[i][j].food = 5;
		}
	}
	for (int i = 0; i < M; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		map[x - 1][y - 1].tree.push_back(z);
	}

	while (K--) {
		//봄
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (map[i][j].tree.empty()) continue;
				sort(map[i][j].tree.begin(), map[i][j].tree.end());
				for (int idx = 0; idx < map[i][j].tree.size(); ++idx) {
					if (map[i][j].food >= map[i][j].tree[idx]) {
						map[i][j].food -= map[i][j].tree[idx];
						map[i][j].live.push(map[i][j].tree[idx] + 1);
					}
					else {
						map[i][j].dead.push(map[i][j].tree[idx]);
					}
				}
				map[i][j].tree.clear();
			}
		}

		//여름
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				while (!map[i][j].dead.empty()) {
					map[i][j].food += map[i][j].dead.front() / 2;
					map[i][j].dead.pop();
				}
			}
		}

		//가을
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				while (!map[i][j].live.empty()) {
					int now = map[i][j].live.front();
					map[i][j].live.pop();
					map[i][j].tree.push_back(now);
					if (now % 5 == 0) {
						for (int l = 0; l < 8; ++l) {
							int nx = i + dx[l], ny = j + dy[l];
							if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
							map[nx][ny].tree.push_back(1);
						}
					}
				}
			}
		}

		//겨울
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				map[i][j].food += A[i][j];
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ret += map[i][j].tree.size();
		}
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
