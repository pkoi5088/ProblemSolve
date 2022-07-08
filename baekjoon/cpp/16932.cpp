#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define MAX 1000

using namespace std;

/*
	https://www.acmicpc.net/problem/16932
*/

int N, M;
int arr[MAX][MAX], number[MAX][MAX];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
vector<int> group;

void init() {
	memset(number, -1, sizeof(number));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == 0 || number[i][j] != -1) continue;
			int cnt = 0;
			queue<pair<int, int>> q;
			q.push({ i,j });
			number[i][j] = group.size();
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				cnt += 1;

				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 0 || number[nx][ny] != -1)
						continue;
					q.push({ nx,ny });
					number[nx][ny] = group.size();
				}
			}
			group.push_back(cnt);
		}
	}
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}
	init();

	int ret = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == 1) continue;
			vector<int> v;
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 0)
					continue;
				v.push_back(number[nx][ny]);
			}

			sort(v.begin(), v.end());
			//주변에 그룹이 없을 때
			if (v.empty()) {
				ret = max(ret, 1);
			}
			//한종류만 있을 때
			else if (v.size() == 1||v[0]==v.back()) {
				ret = max(ret, group[v[0]] + 1);
			}
			else {
				int tmp = 0;
				for (int i = 1; i < v.size(); ++i) {
					if (v[i - 1] != v[i]) {
						tmp += group[v[i - 1]];
					}
				}
				tmp += group[v.back()];
				ret = max(ret, tmp + 1);
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