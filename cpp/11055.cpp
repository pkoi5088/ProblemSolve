#include <iostream>
#include <algorithm>

using namespace std;

int function(int* dp, int* in, int& N) {
	int r = 0;
	for (int i = 0; i < N; i++) {
		int m = 0;
		for (int j = 0; j < i; j++) {
			if (in[j] < in[i])
				m = max(m, dp[j]);
		}
		dp[i] = m + in[i];
		r = max(r, dp[i]);
	}
	return r;
}

int main() {
	int N;
	cin >> N;
	int* dp = new int[N];
	int* in = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> in[i];
		dp[i] = 0;
	}

	cout << function(dp, in, N) << endl;

	return 0;
}