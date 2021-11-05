#include <iostream>
#include <cstring>
#define MAX 401
#define endl '\n'

using namespace std;

int graph[MAX][MAX];
int V, E;

void solve() {
	memset(graph, -1, sizeof(graph));
	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (graph[a][b] == -1)
			graph[a][b] = c;
		else graph[a][b] = min(graph[a][b], c);
	}
	
	for (int k = 1; k <= V; ++k) {
		for (int i = 1; i <= V; ++i) {
			for (int j = 1; j <= V; ++j) {
				if (i == k || k == j || i == j || graph[i][k] == -1 || graph[k][j] == -1) continue;
				if (graph[i][j]==-1||graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	int ret = -1;
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (i == j || graph[i][j] == -1 || graph[j][i] == -1) continue;
			if (graph[i][i] == -1 || graph[i][i] > graph[i][j] + graph[j][i])
				graph[i][i] = graph[i][j] + graph[j][i];
		}
		if (graph[i][i] != -1 && (ret == -1 || ret > graph[i][i]))
			ret = graph[i][i];
	}
	cout << ret << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
