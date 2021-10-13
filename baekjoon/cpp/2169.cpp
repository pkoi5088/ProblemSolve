#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MIN -100000001
#define endl '\n'

using namespace std;

int max(int a, int b, int c) {
	if (a > b)
		return a > c ? a : c;
	else
		return b > c ? b : c;
}

//0:위->아래, 1:왼->오, 2:오->왼
int graph[1000][1000],dp[1000][1000][3];
int N, M;

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = MIN;
		}
	}
	dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = graph[0][0];
	for (int i = 1; i < M; ++i) {
		dp[0][i][0] = dp[0][i - 1][0] + graph[0][i];
	}

	for (int i = 1; i < N; ++i) {
		//위->아래
		for (int j = 0; j < M; ++j) {
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1], dp[i - 1][j][2]) + graph[i][j];
		}
		//왼->오
		for (int j = 1; j < M; ++j) {
			dp[i][j][1] = max(dp[i][j - 1][0], dp[i][j - 1][1]) + graph[i][j];
		}
		//오->왼
		for (int j = M - 2; j >= 0; --j) {
			dp[i][j][2] = max(dp[i][j + 1][0], dp[i][j + 1][2]) + graph[i][j];
		}
	}

	cout << max(dp[N - 1][M - 1][0], dp[N - 1][M - 1][1], dp[N - 1][M - 1][2]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
