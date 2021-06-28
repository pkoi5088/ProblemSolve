#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

void solve() {
	int N, ret = -1;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	do {
		int tmp = 0;
		for (int i = 0; i < N - 1; ++i) {
			tmp += abs(arr[i] - arr[i + 1]);
		}
		ret = max(ret, tmp);
	} while (next_permutation(arr.begin(), arr.end()));
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
