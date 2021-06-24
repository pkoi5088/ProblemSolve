#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

vector<int> height;
long long N, M;

bool isAble(int h) {
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (height[i] <= h)
			continue;
		sum += height[i] - h;
		if (sum >= M)
			return true;
	}
	return false;
}

void solve() {
	cin >> N >> M;
	int result = -1, low = 0, high = -1;
	height.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> height[i];
		high = max(high, height[i]);
	}

	while (low <= high) {
		int mid = (low + high) / 2;
		if (isAble(mid)) {
			result = max(result, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
