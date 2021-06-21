#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#define MAX 100
#define MOD 1000000000
#define endl '\n'

using namespace std;

int dp[MAX][1 << 10][10] = { 0 };

void solve() {
	int N, result = 0;
	cin >> N;
	for (int i = 1; i < 10; ++i) {
		dp[0][1 << i][i] = 1;
	}
	for (int i = 0; i < N-1; ++i) {
		//마지막 숫자에 대해서
		for (int j = 0; j < 10; ++j) {
			//0000..00부터1111..11까지
			for (int k = 0; k < (1 << 10); ++k) {
				if (dp[i][k][j] == 0)
					continue;
				else {
					if (j != 0) {
						dp[i + 1][k | (1 << (j - 1))][j - 1] += dp[i][k][j];
						dp[i + 1][k | (1 << (j - 1))][j - 1] %= MOD;
					}
					if (j != 9) {
						dp[i + 1][k | (1 << (j + 1))][j + 1] += dp[i][k][j];
						dp[i + 1][k | (1 << (j + 1))][j + 1] %= MOD;
					}
				}
			}
		}
	}
	for (int i = 0; i < 10; ++i) {
		result = (result + dp[N - 1][(1 << 10) - 1][i]) % MOD;
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
