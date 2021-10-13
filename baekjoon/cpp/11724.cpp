#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;
int* visit;
vector<int>* graph;

void dfs(int num) {
	visit[num] = 1;
	for (int i = 0; i < graph[num].size(); i++) {
		if (!visit[graph[num][i]]) {
			dfs(graph[num][i]);
		}
	}
}

int solve() {
	int N, M;
	cin >> N >> M;
	visit = new int[N];
	for (int i = 0; i < N; i++)
		visit[i] = 0;
	graph = new vector<int>[N];
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x - 1].push_back(y-1);
		graph[y - 1].push_back(x-1);
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			cnt++;
			dfs(i);
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << solve();
	return 0;
}