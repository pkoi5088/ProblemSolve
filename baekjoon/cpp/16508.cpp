#include <iostream>
#include <string>
#define endl '\n'
#define MAX 16

using namespace std;

/*
	https://www.acmicpc.net/problem/16508
*/

string T;
int N, cost[MAX];
int cnt[MAX][26] = { 0, };

int min(int a, int b) {
	if (a == -1) return b;
	if (b == -1) return a;
	return a < b ? a : b;
}

//order대로 오렸을 때 T를 만들수 있는가격 못만들면 -1
int getOrder(int order) {
	int ret = 0;
	int target[26] = { 0, };
	for (int i = 0; i < T.size(); ++i) {
		target[T[i] - 'A'] += 1;
	}
	for (int i = 0; i < N; ++i) {
		if (order & (1 << i)) {
			ret += cost[i];
			for (int j = 0; j < 26; ++j) {
				target[j] -= cnt[i][j];
			}
		}
	}

	for (int i = 0; i < 26; ++i) {
		if (target[i] > 0) {
			return -1;
		}
	}
	return ret;
}

void solve() {
	cin >> T >> N;
	for (int i = 0; i < N; ++i) {
		string tmp;
		cin >> cost[i] >> tmp;
		for (int j = 0; j < tmp.size(); ++j) {
			cnt[i][tmp[j] - 'A'] += 1;
		}
	}

	int ret = -1;
	for (int order = 0; order < (1 << N); ++order) {
		ret = min(ret, getOrder(order));
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