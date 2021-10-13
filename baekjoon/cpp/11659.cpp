#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#define MAX 100001
#define endl '\n'

using namespace std;

int num[MAX] = { 0 };

void solve() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i < N + 1; ++i) {
		cin >> num[i];
		num[i] += num[i - 1];
	}
	while (M--) {
		int i, j;
		cin >> i >> j;
		cout << num[j] - num[i - 1] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
