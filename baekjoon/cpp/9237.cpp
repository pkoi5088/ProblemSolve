#include <iostream>
#include <algorithm>
#define MAX 1000000
#define endl '\n'

using namespace std;

void solve() {
	int arr[MAX];
	int N, ret = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N, greater<>());
	for (int i = 0; i < N; ++i) {
		ret = max(ret, arr[i] + i + 2);
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
