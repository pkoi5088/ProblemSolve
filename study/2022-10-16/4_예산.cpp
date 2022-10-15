#include <iostream>
#include <algorithm>
#define endl '\n'
#define MAX 10000

using namespace std;

/*
	https://www.acmicpc.net/problem/2512

*/

int N, M;
int arr[MAX];

//cut상한으로 M원 내에 예산을 나눌수 있는지
bool check(int cut) {
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		ret += min(arr[i], cut);
	}
	return ret <= M;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	cin >> M;
	sort(arr, arr + N);

	int left = 1, right = arr[N - 1];
	int ret = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			ret = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
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