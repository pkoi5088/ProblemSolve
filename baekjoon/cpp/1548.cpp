#include <iostream>
#include <algorithm>
#define endl '\n'
#define MAX 50

using namespace std;

/*
	https://www.acmicpc.net/problem/1548
*/

void solve() {
	int arr[MAX], N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int ret = (N < 3 ? N : 2);
	for (int i = 0; i < N; ++i) {
		for (int j = i + 2; j < N; ++j) {
			if (arr[i] + arr[i + 1] > arr[j]) {
				ret = max(ret, j - i + 1);
			}
		}
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