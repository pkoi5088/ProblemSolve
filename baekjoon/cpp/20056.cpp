#include <iostream>
#include <vector>
#define endl '\n'
#define MAX 50

using namespace std;

/*
	https://www.acmicpc.net/problem/20056
*/

struct Meteor {
	int m, d, s;
	Meteor(int im, int id, int is) {
		m = im, d = id, s = is;
	}
};

int N, M, K;
vector<Meteor> arr[MAX][MAX];
int dx[8] = { -1,-1,0,1,1,1,0,-1 }, dy[8] = { 0,1,1,1,0,-1,-1,-1 };

void correction(int& a) {
	while (a < 0)
		a += N;
	a %= N;
}

void moving() {
	vector<Meteor> tmp[MAX][MAX];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < arr[i][j].size(); ++k) {
				int nx = i + dx[arr[i][j][k].d] * arr[i][j][k].s;
				int ny = j + dy[arr[i][j][k].d] * arr[i][j][k].s;
				correction(nx); correction(ny);
				tmp[nx][ny].push_back(arr[i][j][k]);
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			arr[i][j] = tmp[i][j];
		}
	}
}

bool check(int x, int y) {
	for (int i = 1; i < arr[x][y].size(); ++i) {
		if (arr[x][y][0].d % 2 != arr[x][y][i].d % 2) {
			return false;
		}
	}
	return true;
}

void meteorSplit() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j].size() >= 2) {
				int massSum = 0, speedSum = 0, meteorSize = arr[i][j].size();
				for (int k = 0; k < meteorSize; ++k) {
					massSum += arr[i][j][k].m;
					speedSum += arr[i][j][k].s;
				}
				if (check(i, j)) {
					arr[i][j].clear();
					if (massSum / 5 != 0) {
						arr[i][j].push_back(Meteor(massSum / 5, 0, speedSum / meteorSize));
						arr[i][j].push_back(Meteor(massSum / 5, 2, speedSum / meteorSize));
						arr[i][j].push_back(Meteor(massSum / 5, 4, speedSum / meteorSize));
						arr[i][j].push_back(Meteor(massSum / 5, 6, speedSum / meteorSize));
					}
				}
				else {
					arr[i][j].clear();
					if (massSum / 5 != 0) {
						arr[i][j].push_back(Meteor(massSum / 5, 1, speedSum / meteorSize));
						arr[i][j].push_back(Meteor(massSum / 5, 3, speedSum / meteorSize));
						arr[i][j].push_back(Meteor(massSum / 5, 5, speedSum / meteorSize));
						arr[i][j].push_back(Meteor(massSum / 5, 7, speedSum / meteorSize));
					}
				}
			}
		}
	}
}

void solve() {
	cin >> N >> M >> K;
	while (M--) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		arr[a - 1][b - 1].push_back(Meteor(c, e, d));
	}

	while (K--) {
		//이동
		moving();

		//분열
		meteorSplit();

	}

	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < arr[i][j].size(); ++k) {
				ret += arr[i][j][k].m;
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