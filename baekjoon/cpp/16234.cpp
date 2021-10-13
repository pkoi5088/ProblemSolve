#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void solve() {
	vector<vector<int>> graph;
	vector<vector<bool>> visit;
	int N, L, R, result = 0;
	cin >> N >> L >> R;
	graph.resize(N);
	visit.resize(N);
	for (int i = 0; i < N; ++i) {
		graph[i].resize(N);
		visit[i].resize(N, false);
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> graph[i][j];

	bool flag = true;
	while (flag) {
		//visit와 인구이동 확인용 flag 초기화
		flag = false;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				visit[i][j] = false;
			}
		}

		//각각 칸 확인
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (visit[i][j] == false) {
					//첫 칸을 큐에 넣고
					vector<pair<int, int>> v;
					queue<pair<int, int>> q;
					int sum = graph[i][j];
					v.push_back({ i,j });
					visit[i][j] = true;
					q.push({ i,j });
					//조건에 만족하는 칸들을 탐색
					while (!q.empty()) {
						int x = q.front().first, y = q.front().second;
						q.pop();
						for (int l = 0; l < 4; ++l) {
							int nx = x + dx[l], ny = y + dy[l];
							if (nx >= 0 && nx < N && ny >= 0 && ny < N && visit[nx][ny] == false) {
								int dist = abs(graph[x][y] - graph[nx][ny]);
								if (dist >= L && dist <= R) {
									//한번이라도 국경이동이 발생했다.
									flag = true;
									sum += graph[nx][ny];
									v.push_back({ nx,ny });
									visit[nx][ny] = true;
									q.push({ nx,ny });
								}
							}
						}
					}

					//벡터에 담아둔 좌표에 대해서 인구이동 처리
					for (int k = 0; k < v.size(); ++k) {
						int x = v[k].first, y = v[k].second;
						graph[x][y] = sum / v.size();
					}
				}
			}
		}
		if (flag)
			result += 1;
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
