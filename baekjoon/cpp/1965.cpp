#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m = 0;
	cin >> n;

	vector<int> arr(n, 0);
	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		m = max(m, dp[i]);
	}
	cout << m;

	return 0;
}