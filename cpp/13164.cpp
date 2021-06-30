#include <iostream>
#include <algorithm>
#define MAX 300000
#define endl "\n"

using namespace std;

void solve() {
	int N, K;
	int height[MAX];
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> height[i];
	sort(height, height + N);
	int ret = height[N - 1] - height[0];
	for (int i = 1; i < N; ++i)
		height[i - 1] = height[i] - height[i - 1];
	sort(height, height + N - 1, greater<>());
	for (int i = 0; i < K - 1; ++i)
		ret -= height[i];
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}