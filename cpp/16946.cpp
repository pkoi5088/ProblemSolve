#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#define MAX 1000
#define endl '\n'

using namespace std;

string map[MAX];
bool visit[MAX][MAX] = { false };
int add[MAX][MAX] = { 0 };
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int N, M;

void solve() {
	int areaCnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> map[i];
	}

	vector<int> v(1, 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == '0' && visit[i][j] == false) {
				queue<pair<int, int>> q;
				areaCnt += 1;
				int cnt = 0;
				q.push({ i,j });
				visit[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					cnt += 1;
					add[x][y] = areaCnt;
					for (int l = 0; l < 4; ++l) {
						int nx = x + dx[l], ny = y + dy[l];
						if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == '0' && visit[nx][ny] == false) {
							q.push({ nx,ny });
							visit[nx][ny] = true;
						}
					}
				}
				v.push_back(cnt);
			}
		}
	}

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			if (map[x][y] == '1') {
				set<int> check;
				int sum = 1;
				for (int l = 0; l < 4; ++l) {
					int nx = x + dx[l], ny = y + dy[l];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
						if (check.find(add[nx][ny]) == check.end()) {
							sum += v[add[nx][ny]];
							check.insert(add[nx][ny]);
						}
					}
				}
				cout << sum % 10;
			}
			else cout << '0';
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
