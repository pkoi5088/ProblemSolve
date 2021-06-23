#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
	int N, result = 1;
	cin >> N;
	vector<pair<int,int>> connect;
	vector<int> dp;
	dp.resize(N, 0);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		connect.push_back({ x,y });
	}
	sort(connect.begin(), connect.end());
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		int t = 0;
		for (int j = 0; j < i; j++) {
			if (connect[j].second < connect[i].second) {
				t = max(t, dp[j]);
			}
		}
		dp[i] = t + 1;
		result = max(result, dp[i]);
	}
	return N - result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << solve() << endl;
	return 0;
}