#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/18511
*/

int N, K, ret = 0;
int arr[3];

void dfs(int num, int len) {
	if (num>N) return;
	ret = max(ret, num);
	for (int i = 0; i < K; ++i) {
		dfs(num * 10 + arr[i], len + 1);
	}
}

void solve() {
	cin >> N >> K;
	for (int i = 0; i < K; ++i)
		cin >> arr[i];
	for (int i = 0; i < K; ++i) {
		dfs(arr[i], 1);
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