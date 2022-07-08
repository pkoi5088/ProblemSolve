#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define endl '\n'
#define MAX 10000

using namespace std;

/*
	https://www.acmicpc.net/problem/1967
*/

int N;
vector<pair<int, int>> graph[MAX];
bool visit[MAX] = { false, };

//idx에서 가장 멀리 있는 노드번호와 거리를 반환
pair<int, int> function(int idx) {
	memset(visit, false, sizeof(visit));
	pair<int, int> ret = { idx,0 };
	queue<pair<int, int>> q;
	q.push({ idx,0 });
	visit[idx] = true;
	while (!q.empty()) {
		int now = q.front().first, dist = q.front().second;
		q.pop();

		if (dist > ret.second) {
			ret = { now,dist };
		}

		for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i].first, cost = graph[now][i].second;
			if (visit[next]) continue;
			q.push({ next,dist + cost });
			visit[next] = true;
		}
	}
	return ret;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1].push_back({ b - 1,c });
		graph[b - 1].push_back({ a - 1,c });
	}

	cout << function(function(0).first).second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}