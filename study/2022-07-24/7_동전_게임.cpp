#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/9079
*/

int min(int a, int b) {
	if (a == -1) return b;
	if (b == -1) return a;
	return a < b ? a : b;
}

int getCount(int a) {
	int ret = 0;
	while (a != 0) {
		ret += a % 2;
		a /= 2;
	}
	return ret;
}

bool check(vector<vector<int>> arr, int a, int b, int c) {
	int cnt = 0;
	while (a != 0) {
		if (a % 2) {
			for (int i = 0; i < 3; ++i) {
				arr[cnt][i] = !arr[cnt][i];
			}
		}
		a /= 2;
		cnt += 1;
	}

	cnt = 0;
	while (b != 0) {
		if (b % 2) {
			for (int i = 0; i < 3; ++i) {
				arr[i][cnt] = !arr[i][cnt];
			}
		}
		b /= 2;
		cnt += 1;
	}

	if (c % 2) {
		for (int i = 0; i < 3; ++i) {
			arr[i][i] = !arr[i][i];
		}
	}
	if (c / 2) {
		for (int i = 0; i < 3; ++i) {
			arr[i][2 - i] = !arr[i][2 - i];
		}
	}


	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (arr[i][j] != arr[0][0]) return false;
		}
	}
	return true;
}

void solve() {
	vector<vector<int>> arr = { {0,0,0}, {0,0,0}, {0,0,0} };
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			char c;
			cin >> c;
			if (c == 'H') {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = 1;
			}
		}
	}

	int ret = -1;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (check(arr, i, j, k)) {
					ret = min(ret, getCount(i) + getCount(j) + getCount(k));
				}
			}
		}
	}
	cout << ret << endl;
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