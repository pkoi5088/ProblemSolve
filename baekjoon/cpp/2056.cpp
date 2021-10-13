#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 10000
#define endl '\n'

using namespace std;

vector<int> graph[MAX];
//time: 작업을 시작하는 시간
int indegree[MAX], cost[MAX], time[MAX];
int N;

void solve() {
	int result = -1;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> cost[i] >> indegree[i];
		for (int j = 0; j < indegree[i]; ++j) {
			int x;
			cin >> x;
			graph[x - 1].push_back(i);
		}
		time[i] = -1;
	}

	queue<int> q;
	for (int i = 0; i < N; ++i) {
		if (indegree[i] == 0) {
			q.push(i);
			time[i] = 0;
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i];
			time[next] = max(time[next], time[now] + cost[now]);
			if (--indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		if (result < time[i] + cost[i])
			result = time[i] + cost[i];
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
