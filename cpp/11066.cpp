#include <iostream>
#include <vector>

using namespace std;

vector<int> file;
vector<vector<int>> dp;
int K;

int dpMin(int start, int end) {
	if (dp[start][end] != -1)
		return dp[start][end];
	if (start + 1 == end)
		return dp[start][end] = file[start] + file[end];
	int sum = 0;
	for (int i = start; i <= end; i++)
		sum += file[i];

	int result = -1;
	for (int i = start; i < end; i++) {
		int tmp = dpMin(start, i) + dpMin(i + 1, end) + sum;
		if (result == -1)
			result = tmp;
		else
			result = min(result, tmp);
	}
	return dp[start][end] = result;
}

int solve() {
	cin >> K;
	file.resize(K);
	dp.resize(K);
	for (int i = 0; i < K; i++)
		dp[i].resize(K, -1);
	for (int i = 0; i < K; i++)
		cin >> file[i];
	for (int i = 0; i < K; i++)
		dp[i][i] = 0;
	return dpMin(0, K - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cout << solve() << '\n';
		file.clear();
		dp.clear();
	}
	return 0;
}