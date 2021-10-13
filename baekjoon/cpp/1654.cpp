#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<long long> v;
int N, K;

bool isAble(int mid) {
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		cnt += v[i] / mid;
	}
	return cnt >= N ? true : false;
}

int solve() {
	long long low = 1, high = -1, result = -1;
	cin >> K >> N;
	v.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> v[i];
		high = max(high, v[i]);
	}

	while (low <= high) {
		long long mid = (low + high) / 2;
		if (isAble(mid)) {
			result = max(result, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}
