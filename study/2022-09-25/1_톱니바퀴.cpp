#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/14891
*/

string gear[4];

void left(int n, int dir) {
	if (n > 0 && gear[n][6] != gear[n - 1][2]) {
		left(n - 1, -dir);
	}
	if (dir == 1) {
		gear[n] = gear[n][7] + gear[n];
		gear[n].pop_back();
	}
	else {
		gear[n] = gear[n] + gear[n][0];
		gear[n].erase(gear[n].begin());
	}
}

void right(int n, int dir) {
	if (n < 3 && gear[n][2] != gear[n + 1][6]) {
		right(n + 1, -dir);
	}
	if (dir == 1) {
		gear[n] = gear[n][7] + gear[n];
		gear[n].pop_back();
	}
	else {
		gear[n] = gear[n] + gear[n][0];
		gear[n].erase(gear[n].begin());
	}
}

void rotate(int n, int dir) {
	if (n > 0 && gear[n][6] != gear[n - 1][2]) {
		left(n - 1, -dir);
	}
	if (n < 3 && gear[n][2] != gear[n + 1][6]) {
		right(n + 1, -dir);
	}
	if (dir == 1) {
		gear[n] = gear[n][7] + gear[n];
		gear[n].pop_back();
	}
	else {
		gear[n] = gear[n] + gear[n][0];
		gear[n].erase(gear[n].begin());
	}
}

void solve() {
	int k, result = 0;
	for (int i = 0; i < 4; ++i)
		cin >> gear[i];
	cin >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		rotate(a - 1, b);
	}
	for (int i = 0; i < 4; ++i) {
		if (gear[i][0] == '1') {
			result += (1 << i);
		}
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
