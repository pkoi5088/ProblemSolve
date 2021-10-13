#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#define MAX 1000
#define INF 100000000
#define endl '\n'

using namespace std;

//dp[i][j][k]: 1번집이 i색이고 k+1번집은 j색일 때 최소값.
int dp[3][3][MAX], cost[3][MAX];
int N;

void solve() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < MAX; ++k)
				dp[i][j][k] = INF;
		}
	}
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> cost[0][i] >> cost[1][i] >> cost[2][i];
	for (int i = 0; i < 3; ++i)
		dp[i][i][0] = cost[i][0];

	for (int i = 1; i < N; ++i) {
		//0번으로 칠하기
		for (int first = 0; first < 3; ++first) {
			for (int a = 0; a < 3; ++a) {
				for (int b = 0; b < 3; ++b) {
					if (a != b) {
						dp[first][a][i] = min(dp[first][a][i], dp[first][b][i - 1] + cost[a][i]);
					}
				}
			}
		}
	}

	int result = INF;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i != j)
				result = min(result, dp[i][j][N - 1]);
		}
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
