#include <iostream>
#define endl '\n'
#define MAX 200

using namespace std;

/*
	https://www.acmicpc.net/problem/2422
*/

bool check[MAX][MAX] = { false, };
int N, M;

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		check[a - 1][b - 1] = true;
		check[b - 1][a - 1] = true;
	}

	int ret = 0;
	for (int i = 0; i < N - 2; ++i) {
		for (int j = i + 1; j < N - 1; ++j) {
			for (int k = j + 1; k < N; ++k) {
				if (check[i][j] || check[i][k] || check[j][k]) continue;
				ret += 1;
			}
		}
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