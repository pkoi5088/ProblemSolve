#include <iostream>
#define endl '\n'
#define MAX 500

using namespace std;

bool able[MAX][MAX];
int N, M;

void solve() {
	cin >> N >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		able[a - 1][b - 1] = true;
	}

	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (able[i][k] == false || able[k][j] == false) continue;
				able[i][j] = true;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; ++i) {
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			if (able[i][j] || able[j][i]) cnt += 1;
		}
		if (cnt == N - 1) answer += 1;
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}