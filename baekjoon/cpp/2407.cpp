#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

string dp[101][101];

string strSum(string s1, string s2) {
	string result = "";
	int sum = 0;
	while (!s1.empty() || !s2.empty()) {
		if (!s1.empty()) {
			sum += s1.back() - '0';
			s1.pop_back();
		}
		if (!s2.empty()) {
			sum += s2.back() - '0';
			s2.pop_back();
		}
		result += (sum % 10) + '0';
		sum /= 10;
	}
	if (sum != 0) {
		result += (sum % 10) + '0';
	}
	reverse(result.begin(), result.end());
	return result;
}

string combination(int N, int M) {
	if (dp[N][M] != "")
		return dp[N][M];
	else if (N == M || M == 0)
		return dp[N][M] = "1";
	return dp[N][M] = strSum(combination(N - 1, M), combination(N - 1, M - 1));
}

string solve() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dp[i][j] = "";
		}
	}
	int n, m;
	cin >> n >> m;
	return combination(n, m);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}