#include <iostream>
#define MAX 500
#define endl '\n'

using namespace std;

int graph[MAX][MAX];
int N, M;

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> graph[i][j];
		}
	}

	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j || i == k || j == k) continue;
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	while (M--) {
		int A, B, C;
		cin >> A >> B >> C;
		if (graph[A - 1][B - 1] <= C) {
			cout << "Enjoy other party" << endl;
		}
		else {
			cout << "Stay here" << endl;
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