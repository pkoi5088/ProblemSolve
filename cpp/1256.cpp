#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 101
#define INF 1000000000
#define endl '\n'

using namespace std;

int dp[MAX][MAX];
int N, M, K;
string result = "";

//a,z 개수내에서 K번째 문자열 찾기
void search(int a, int z) {
	if (a == 0 && z > 0) {
		result.push_back('z');
		search(a, z - 1);
	}
	else if (a > 0 && z == 0) {
		result.push_back('a');
		search(a - 1, z);
	}
	else if (a > 0 && z > 0) {
		if (dp[a - 1][z] >= K) {
			result.push_back('a');
			search(a - 1, z);
		}
		else {
			K -= dp[a - 1][z];
			result.push_back('z');
			search(a, z - 1);
		}
	}
}

void solve() {
	cin >> N >> M >> K;
	for (int i = 0; i < N + 1; ++i) {
		for (int j = 0; j < M + 1; ++j) {
			dp[i][j] = 1;
		}
	}
	for (int i = 1; i < N + 1; ++i) {
		for (int j = 1; j < M + 1; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (dp[i][j] > INF)
				dp[i][j] = INF;
		}
	}

	if (dp[N][M] < K)
		cout << -1;
	else {
		search(N, M);
		cout << result;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
