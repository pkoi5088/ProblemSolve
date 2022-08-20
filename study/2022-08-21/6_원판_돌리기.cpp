#include <iostream>
#include <vector>
#define endl '\n'
#define INF -2000000000

using namespace std;

/*
	https://www.acmicpc.net/problem/17822
*/

vector<vector<int>> disk;
int N, M, T;

void correct(int& a) {
	while (a < 0)
		a += M;
	a %= M;
}

//0이 시계방향
void rotate(int idx, int dir, int k) {
	vector<int> ret(M);
	for (int i = 0; i < M; ++i) {
		int next = i;
		if (dir == 0) 
			next -= k;
		else
			next += k;
		correct(next);
		ret[i] = disk[idx][next];
	}
	disk[idx] = ret;
}

//idx원판을 중복체크한다
void check() {
	//중복체크 벡터
	vector<vector<bool>> v(N, vector<bool>(M, false));
	
	//1. 모든 중복관계를 체크한다
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (disk[i][j] == INF) continue;
			//위
			if (i != 0) {
				if (disk[i - 1][j] == disk[i][j]) {
					v[i - 1][j] = v[i][j] = true;
				}
			}

			//아래
			if (i != N - 1) {
				if (disk[i + 1][j] == disk[i][j]) {
					v[i + 1][j] = v[i][j] = true;
				}
			}

			int next;
			//왼
			next = j - 1;
			correct(next);
			if (disk[i][next] == disk[i][j]) {
				v[i][next] = v[i][j] = true;
			}

			//오
			next = j + 1;
			correct(next);
			if (disk[i][next] == disk[i][j]) {
				v[i][next] = v[i][j] = true;
			}
		}
	}

	//2. 각 원판에 대한 처리
		//인접한 수가 있는가
	bool flag = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (v[i][j]) {
				flag = true;
				disk[i][j] = INF;
			}
		}
	}

	//인접한 수가 없다
	if (flag == false) {
		double avg = 0.0;
		int total = 0, cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (disk[i][j] != INF) {
					total += disk[i][j];
					cnt += 1;
				}
			}
		}

		//평균을 구하고
		if (cnt != 0) {
			avg = (double)total / (double)cnt;
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (disk[i][j] == INF) continue;
					if (avg < (double)disk[i][j]) {
						disk[i][j] -= 1;
					}
					else if (avg > (double)disk[i][j]) {
						disk[i][j] += 1;
					}
				}
			}
		}
	}
}

void solve() {
	cin >> N >> M >> T;
	disk.resize(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> disk[i][j];
		}
	}

	while (T--) {
		int x, d, k;
		cin >> x >> d >> k;

		for (int i = 0; i < N; ++i) {
			if ((i + 1) % x == 0) {
				rotate(i, d, k);
			}
		}
		check();
	}

	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (disk[i][j] != INF) {
				ret += disk[i][j];
			}
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