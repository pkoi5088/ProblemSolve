#include <iostream>
#define MAX 1003
#define endl '\n'

using namespace std;

int cnt[10][8] = {
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};

int getCnt(int now, int after, int K) {
	int ret = 0;
	while (K--) {
		for (int i = 0; i < 7; ++i) {
			if (cnt[now % 10][i] != cnt[after % 10][i]) ret += 1;
		}
		now /= 10;
		after /= 10;
	}
	return ret;
}

void solve() {
	int N, K, P, X, ret = 0;
	cin >> N >> K >> P >> X;
	for (int i = 1; i <= N; ++i) {
		if (i == X) continue;
		if (getCnt(X, i, K) <= P) {
			ret++;
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
