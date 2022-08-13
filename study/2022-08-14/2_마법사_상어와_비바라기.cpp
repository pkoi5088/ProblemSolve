#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
#define MAX 50

using namespace std;

/*
	https://www.acmicpc.net/problem/21610
*/

struct Cloud {
	int x, y;
	vector<pair<int, int>> delta;
};

Cloud now;
int N, M;
int A[MAX][MAX], tmp[MAX][MAX];
int dx[8] = { 0,-1,-1,-1,0,1,1,1 }, dy[8] = { -1,-1,0,1,1,1,0,-1 };

void correction(int& a) {
	while (a < 0) {
		a += N;
	}
	a %= N;
}

void raining() {
	for (int i = 0; i < now.delta.size(); ++i) {
		int x = now.x + now.delta[i].first, y = now.y + now.delta[i].second;
		correction(x);
		correction(y);
		tmp[x][y] += 1;
	}
}

void waterCopyBug() {
	for (int i = 0; i < now.delta.size(); ++i) {
		int x = now.x + now.delta[i].first, y = now.y + now.delta[i].second;
		correction(x);
		correction(y);
		for (int k = 1; k < 8; k += 2) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (A[nx][ny] + tmp[nx][ny] > 0) {
				tmp[x][y] += 1;
			}
		}
	}
}

void regeneration() {
	now.x = 0, now.y = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] >= 2 && tmp[i][j] == 0) {
				now.delta.push_back({ i,j });
				A[i][j] -= 2;
			}
		}
	}
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}

	now.x = 0, now.y = 0;
	now.delta = { {N - 1,0}, {N - 1,1}, {N - 2,0}, {N - 2,1} };
	while (M--) {
		int d, s;
		cin >> d >> s;
		d -= 1;

		//1. 이동
		now.x += dx[d] * s, now.y += dy[d] * s;
		correction(now.x);
		correction(now.y);

		//2. 비내리기
		raining();

		//4. 물복사버그
		waterCopyBug();

		//3. 구름제거
		now.delta.clear();

		//5. 구름 재생성
		regeneration();

		//6. 물 증가
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				A[i][j] += tmp[i][j];
				tmp[i][j] = 0;
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ret += A[i][j];
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