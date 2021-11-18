#include <iostream>
#define MAX 50
#define endl '\n'

using namespace std;

int parent[MAX], indegree[MAX] = { 0, };
int N, node;

bool f(int now) {
	while (now != -1) {
		if (now == node) return false;
		now = parent[now];
	}
	return true;
}

void solve() {
	int ret = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> parent[i];
		if (parent[i] != -1)
			indegree[parent[i]] += 1;
	}
	cin >> node;
	if (parent[node] != -1)
		indegree[parent[node]] -= 1;

	for (int i = 0; i < N; ++i) {
		if (indegree[i] == 0 && f(i)) ret += 1;
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
