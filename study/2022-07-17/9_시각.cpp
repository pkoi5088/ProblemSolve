#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/18312
*/

int N, K;

bool check(int n) {
	int sec, minute, hour;
	sec = n % 60;
	n /= 60;
	minute = n % 60;
	n /= 60;
	hour = n;
	if (sec % 10 == K || sec / 10 == K) return true;
	if (minute % 10 == K || minute / 10 == K) return true;
	if (hour % 10 == K || hour / 10 == K) return true;
	return false;
}

void solve() {
	cin >> N >> K;
	int ret = 0;
	for (int i = 0; i < (N + 1) * 3600; ++i) {
		if (check(i)) ret += 1;
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