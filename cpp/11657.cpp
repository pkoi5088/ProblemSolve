#include <iostream>
#include <vector>
#define MAX 500
#define INF 1000000007
#define endl '\n'

using namespace std;

vector<pair<int, int>> graph[MAX];
int N, M, dist[MAX];

void solve() {
	for (int i = 0; i < MAX; ++i) dist[i] = INF;
	dist[0] = 0;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int A, B, C;
		cin >> A >> B >> C;
		graph[A - 1].push_back({ B - 1,C });
	}

	bool flag;
	for (int k = 0; k < N; ++k) {
		flag = false;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < graph[i].size(); ++j) {
				int next = graph[i][j].first, cost = graph[i][j].second;
				if (dist[i] != INF && dist[next] > dist[i] + cost) {
					dist[next] = dist[i] + cost;
					flag = true;
				}
			}
		}
	}

	if (flag) cout << -1;
	else {
		for (int i = 1; i < N; ++i) cout << (dist[i] == INF ? -1 : dist[i]) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
