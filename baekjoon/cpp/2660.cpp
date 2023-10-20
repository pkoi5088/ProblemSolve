#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define MAX 50

using namespace std;

int N;
int graph[MAX][MAX];

void solve() {
	cin >> N;
	memset(graph, -1, sizeof(graph));
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == -1) break;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}
	for (int i = 0; i < N; ++i) {
		graph[i][i] = 0;
	}

	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (graph[i][k] == -1 || graph[k][j] == -1) continue;
				if (graph[i][j] == -1) graph[i][j] = graph[i][k] + graph[k][j];
				else graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int grade = 100000;
	vector<int> v;
	for (int i = 0; i < N; ++i) {
		int tmp = -1;
		for (int j = 0; j < N; ++j) {
			tmp = max(tmp, graph[i][j]);
		}

		if (grade > tmp) {
			grade = tmp;
			v.clear();
			v.push_back(i);
		}
		else if (grade == tmp) {
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	cout << grade << ' ' << v.size() << endl;
	for (auto a : v) {
		cout << a + 1 << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}