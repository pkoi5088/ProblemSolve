#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<pair<int, int>> mat;
int N;

int dpMin(int start, int end) {
	if (dp[start][end] != -1)
		return dp[start][end];
	if (start + 1 == end)
		return dp[start][end] = mat[start].first * mat[start].second * mat[end].second;
	int result = -1, t = mat[start].first * mat[end].second;
	for (int i = start; i < end; i++) {
		int tmp = dpMin(start, i) + dpMin(i + 1, end) + t * mat[i].second;
		if (result == -1)
			result = tmp;
		else
			result = min(result, tmp);
	}
	return dp[start][end] = result;
}

int solve() {
	cin >> N;
	mat.resize(N);
	dp.resize(N);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		mat[i] = { x,y };
		dp[i].resize(N, -1);
	}
	for (int i = 0; i < N; i++) {
		dp[i][i] = 0;
	}
	return dpMin(0, N - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << solve();
	return 0;
}