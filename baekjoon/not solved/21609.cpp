#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/21609
*/

struct Group {
	vector<pair<int, int>> v;
	pair<int, int> standard;
	int rainbow = 0;
	Group(vector<pair<int, int>> iv, pair<int, int> is, int ir) {
		v = iv;
		standard = is;
		rainbow = ir;
	}
};

vector<Group> groupVector;
int N, M, arr[20][20];
int ret = 0, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

pair<int, int> max(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second > b.second ? a : b;
	return a.first > b.first ? a : b;
}

//그룹 분류 -2는 빈칸
void classification() {
	groupVector.clear();
	bool visit[20][20] = { false, };

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] >= 1) {
				if (visit[i][j]) continue;
				bool tmp[20][20] = { false, };
				vector<pair<int, int>> v;
				pair<int, int> standard;
				int color = arr[i][j], rainbow = 0;
				
				queue<pair<int, int>> q;
				q.push({ i,j });
				v.push_back({ i,j });
				standard = { i,j };
				tmp[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();

					for (int l = 0; l < 4; ++l) {
						int nx = x + dx[l], ny = y + dy[l];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny] || arr[nx][ny] == -1)
							continue;
						if (arr[nx][ny] == color || arr[nx][ny] == 0) {
							if (tmp[nx][ny]) continue;
							if (arr[nx][ny] == 0) rainbow += 1;
							q.push({ nx,ny });
							v.push_back({ nx,ny });
							if (arr[nx][ny] != 0)
								standard = max(standard, { nx,ny });
							tmp[nx][ny] = true;
						}
					}
				}

				for (int l = 0; l < v.size(); ++l) {
					int x = v[l].first, y = v[l].second;
					if (arr[x][y] > 0)
						visit[x][y] = true;
				}

				if (v.size() > 1) {
					groupVector.push_back(Group(v, standard, rainbow));
				}
			}
		}
	}
}

bool cmp(Group a, Group b) {
	if (a.v.size() == b.v.size()) {
		if (a.rainbow == b.rainbow) {
			if (a.standard.first == b.standard.first) {
				return a.standard.second > b.standard.second;
			}
			return a.standard.first > b.standard.first;
		}
		return a.rainbow > b.rainbow;
	}
	return a.v.size() > b.v.size();
}

void gravity() {
	for (int y = 0; y < N; ++y) {
		for (int x = N - 1; x >= 0; --x) {
			if (arr[x][y] < 0) continue;
			int nx = x + 1;
			while (nx < N && arr[nx][y] < -1) {
				nx += 1;
			}
			int tmp = arr[x][y];
			arr[x][y] = arr[nx-1][y];
			arr[nx-1][y] = tmp;
		}
	}
}

void rotate() {
	int tmp[20][20];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			tmp[N - j - 1][i] = arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			arr[i][j] = tmp[i][j];
		}
	}
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		classification();
		if (groupVector.empty())
			break;
		sort(groupVector.begin(), groupVector.end(), cmp);
		ret += groupVector[0].v.size() * groupVector[0].v.size();
		for (int i = 0; i < groupVector[0].v.size(); ++i) {
			int x = groupVector[0].v.at(i).first, y = groupVector[0].v.at(i).second;
			arr[x][y] = -2;
		}

		gravity();
		rotate();
		gravity();
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}