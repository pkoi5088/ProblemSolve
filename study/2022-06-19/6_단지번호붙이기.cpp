#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 25
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2667
*/

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void solve() {
	int N, map[MAX][MAX];
	vector<int> result;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string S;
		cin >> S;
		for (int j = 0; j < N; ++j) {
			map[i][j] = S[j] - '0';
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j] == 1) {
				int cnt = 0;
				queue<pair<int, int>> q;
				q.push({ i,j });
				map[i][j] = 2;
				while (!q.empty()) {
					cnt += 1;
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int l = 0; l < 4; ++l) {
						int nx = x + dx[l], ny = y + dy[l];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N || map[nx][ny] != 1) continue;
						q.push({ nx,ny });
						map[nx][ny] = 2;
					}
				}
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
