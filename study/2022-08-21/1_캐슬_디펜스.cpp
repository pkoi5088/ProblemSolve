#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/17135
*/

int N, M, D;
vector<int> archer;

bool finish(vector<vector<int>>& arr) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == 1) return false;
		}
	}
	return true;
}

void down(vector<vector<int>>& arr) {
	for (int i = N - 1; i > 0; --i) {
		for (int j = 0; j < M; ++j) {
			arr[i][j] = arr[i - 1][j];
		}
	}

	for (int j = 0; j < M; ++j) {
		arr[0][j] = 0;
	}
}

//arr상태에서 죽일수있는 적의 수
int getRet(vector<vector<int>> arr) {
	int ret = 0;
	while (!finish(arr)) {
		//활쏘기
		for (int i = 0; i < M; ++i) {
			if (archer[i] == 0) continue;
			int x = -1, y = -1;
			for (int nx = 0; nx < N; ++nx) {
				for (int ny = 0; ny < M; ++ny) {
					if (arr[nx][ny] == 0) continue;
					if (x == -1 || (abs(x - N) + abs(y - i) > abs(nx - N) + abs(ny - i))) {
						if (abs(nx - N) + abs(ny - i) <= D) {
							x = nx, y = ny;
						}
					}
					else if (abs(x - N) + abs(y - i) == abs(nx - N) + abs(ny - i)) {
						if (y > ny && abs(nx - N) + abs(ny - i) <= D) {
							x = nx, y = ny;
						}
					}
				}
			}

			if (x != -1) {
				arr[x][y] += 1;
			}
		}

		//활에 맞은 적 제거
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (arr[i][j] >= 2) {
					arr[i][j] = 0;
					ret += 1;
				}
			}
		}

		//적 이동
		down(arr);
	}
	return ret;
}

void solve() {
	cin >> N >> M >> D;
	vector<vector<int>> arr(N, vector<int>(M, 0));
	archer.resize(M, 0);
	for (int i = 0; i < 3; ++i)
		archer[i] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	int ret = 0;
	do {
		ret = max(ret, getRet(arr));
	} while (prev_permutation(archer.begin(), archer.end()));
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}