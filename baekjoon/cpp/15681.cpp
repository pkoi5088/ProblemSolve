#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100000
#define endl '\n'

using namespace std;

vector<int> graph[MAX];
int dp[MAX];
int N, R, Q;

int getDP(int V, int parent) {
	int& ret = dp[V];
	if (ret != -1) return ret;

	if (graph[V].size() == 1 && graph[V][0] == parent) return ret = 1;

	ret = 1;
	for (int i = 0; i < graph[V].size(); ++i) {
		int next = graph[V][i];
		if (next != parent) ret += getDP(next, V);
	}
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}
	getDP(R - 1, -1);
	while (Q--) {
		int U;
		cin >> U;
		cout << dp[U - 1] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
