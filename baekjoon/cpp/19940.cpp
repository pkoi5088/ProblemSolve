#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	int button[5] = { 0 };
	int N;
	cin >> N;
	button[0] += N / 60;
	N %= 60;
	if (N % 10 == 5) {
		if (N / 10 <= 3) {
			button[3] += N % 10;
		}
		else {
			button[4] += 10 - N % 10;
			N += 10;
		}
	}
	else {
		if (N % 10 < 5) {
			button[3] += N % 10;
		}
		else {
			button[4] += 10 - N % 10;
			N += 10;
		}
	}
	N /= 10;
	if (N <= 3) {
		button[1] += N;
	}
	else {
		button[2] += 6 - N;
		button[0] += 1;
	}

	for (int i = 0; i < 5; ++i) {
		cout << button[i] << ' ';
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
