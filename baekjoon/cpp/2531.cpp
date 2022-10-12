#include <iostream>
#include <algorithm>
#define endl '\n'
#define MAX_N 30000
#define MAX_D 3001

using namespace std;

/*
	https://www.acmicpc.net/problem/2531

*/

int N, d, k, c;
int arr[MAX_N], countArr[MAX_D] = { 0, };

int getCount() {
	int ret = 0;
	for (int i = 0; i < MAX_D; ++i) {
		if (countArr[i]) ret += 1;
	}
	if (countArr[c]) return ret;
	else return ret + 1;
}

int correction(int a) {
	return a %= N;
}

void solve() {
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < k; ++i) {
		countArr[arr[i]] += 1;
	}

	int ret = -1;
	for (int i = 0; i < N; ++i) {
		ret = max(ret, getCount());
		countArr[arr[i]] -= 1;
		countArr[arr[correction(i + k)]] += 1;
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