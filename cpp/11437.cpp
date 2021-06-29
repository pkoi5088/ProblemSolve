#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#define MAX 50001
#define MAX_LOG2 16
#define endl '\n'

using namespace std;

vector<int> graph[MAX];
int depth[MAX] = { 0 }, parent[MAX][MAX_LOG2];
int N, M;

void setDepth() {
	queue<int> q;
	q.push(0);
	depth[0] = 0;
	parent[0][0] = -1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i];
			if (depth[next] == -1) {
				q.push(next);
				depth[next] = depth[now] + 1;
				parent[next][0] = now;
			}
		}
	}
}

void solve() {
	memset(depth, -1, sizeof(depth));
	memset(parent, -1, sizeof(parent));
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}
	setDepth();
	for (int i = 1; i < MAX_LOG2; ++i) {
		for (int j = 1; j < N; ++j) {
			if (parent[j][i - 1] == -1)
				parent[j][i] = -1;
			else
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		a -= 1; b -= 1;
		//깊이는 a<=b유지
		if (depth[a] > depth[b])
			swap(a, b);
		while (depth[a] != depth[b]) {
			int k = 0;
			while (!(parent[b][k] == -1 || depth[parent[b][k]] < depth[a])) {
				k += 1;
			}
			b = parent[b][k - 1];
		}

		if (a == b) {
			cout << b + 1 << endl;
		}
		else {
			while (a != b) {
				int k = 0;
				while (!(parent[a][k] == parent[b][k])) {
					k += 1;
				}
				if (k == 0) {
					a = parent[a][k];
					b = parent[b][k];
				}
				else {
					a = parent[a][k - 1];
					b = parent[b][k - 1];
				}
			}
			cout << b + 1 << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
