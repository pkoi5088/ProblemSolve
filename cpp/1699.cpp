#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
vector<int> dp;

int main() {
	int N;
	cin >> N;
	dp.resize(N + 1, -1);
	for (int i = 1; i*i <= N; i++)
		num.push_back(i*i);
	for (int i = 0; i < num.size(); i++)
		dp[num[i]] = 1;
	//setting

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < num.size(); j++) {
			if (i - num[j] >= 1 && dp[i - num[j]] != -1) {
				if (dp[i] == -1)
					dp[i] = dp[i - num[j]] + 1;
				else
					dp[i] = min(dp[i], dp[i - num[j]] + 1);
			}
		}
	}

	cout << dp[N];
	return 0;
}