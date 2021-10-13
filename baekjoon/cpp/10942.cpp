#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<int> B;

int dpPalindrome(int start, int end) {
	if (dp[start][end] != -1)
		return dp[start][end];
	if (start + 1 == end)
		return dp[start][end] = (B[start] == B[end]);
	if (B[start] == B[end])
		return dp[start][end] = dpPalindrome(start + 1, end - 1);
	return dp[start][end] = 0;
}

void solve() {
	int N, M, S, E;
	cin >> N;
	B.resize(N);
	dp.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		dp[i].resize(N, -1);
	}
	for (int i = 0; i < N; i++)
		dp[i][i] = 1;
	cin >> M;
	while (M--) {
		cin >> S >> E;
		cout << dpPalindrome(S-1, E-1) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}