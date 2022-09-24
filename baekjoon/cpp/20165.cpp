#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
#define MAX 100

using namespace std;

/*
	https://www.acmicpc.net/problem/20165
*/

int N, M, R;
int arr[MAX][MAX], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
bool down[MAX][MAX] = { false, };

vector<pair<int, int>> offense(int x, int y, int dir) {
	vector<pair<int, int>> ret;
	int deadline = arr[x][y];
	int nx = x, ny = y;
	for (int i = 0; i < deadline; ++i) {
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
		if (down[nx][ny] == false) {
			deadline = max(deadline, i + arr[nx][ny]);
			ret.push_back({ nx,ny });
			down[nx][ny] = true;
		}
		nx += dx[dir];
		ny += dy[dir];
	}
	return ret;
}

void defense(int x, int y, vector<pair<int, int>>& v) {
	vector<pair<int, int>> ret;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].first != x || v[i].second != y)
			ret.push_back(v[i]);
	}
	down[x][y] = false;
	v = ret;
}

void solve() {
	cin >> N >> M >> R;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	int ret = 0;
	while (R--) {
		vector<pair<int, int>> v;
		int X, Y;
		char D;
		cin >> X >> Y >> D;
		X -= 1, Y -= 1;
		if (D == 'E') {
			if (!down[X][Y])
				v = offense(X, Y, 3);
		}
		else if (D == 'W') {
			if (!down[X][Y])
				v = offense(X, Y, 2);
		}
		else if (D == 'S') {
			if (!down[X][Y])
				v = offense(X, Y, 1);
		}
		else if (D == 'N') {
			if (!down[X][Y])
				v = offense(X, Y, 0);
		}
		ret += v.size();
		cin >> X >> Y;
		X -= 1, Y -= 1;
		defense(X, Y, v);
	}
	cout << ret << endl;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (down[i][j]) cout << "F ";
			else cout << "S ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}