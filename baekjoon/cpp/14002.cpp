#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> board;
vector<vector<int>> dp;

void solve() {
	int N;
	cin >> N;
	board.resize(N);
	dp.resize(N);
	for (int i = 0; i < N; i++)
		cin >> board[i];
	dp[0].push_back(board[0]);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (board[j] < board[i] && dp[j].size()>dp[i].size()) {
				dp[i] = dp[j];
			}
		}
		dp[i].push_back(board[i]);
	}

	vector<int> result;
	for (int i = 0; i < N; i++) {
		if (result.size() < dp[i].size()) {
			result = dp[i];
		}
	}
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}