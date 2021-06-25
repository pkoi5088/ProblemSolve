#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

long dp[100][21] = { 0 };
int M[100] = { 0 };
int N;

long dpMin(int num, int index) {
	if (num < 0 || num>20) {
		return 0;
	}
	else if (index == N - 2) {
		return num == M[N - 1];
	}
	else if (dp[index][num] != -1) {
		return dp[index][num];
	}
	else {
		dp[index][num] = 0;
		return dp[index][num] += dpMin(num + M[index + 1], index + 1) + dpMin(num - M[index + 1], index + 1);
	}
}

long solve() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 21; j++) {
			dp[i][j] = -1;
		}
	}
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> M[i];
	}
	return dpMin(M[0], 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}