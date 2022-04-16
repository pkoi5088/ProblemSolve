#include <iostream>
#define MAX 100000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/22945
*/

void solve() {
	int N;
	int arr[MAX];
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	int left = 0, right = N - 1;
	int ret = 0;
	while (left <= right) {
		ret = max(ret, (right - left - 1) * min(arr[left], arr[right]));

		if (arr[left] > arr[right]) {
			right -= 1;
		}
		else {
			left += 1;
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