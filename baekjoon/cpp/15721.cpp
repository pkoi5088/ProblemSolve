#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/15721
*/

void solve() {
	int A, T, flag, idx = 0, circle = 1;
	cin >> A >> T >> flag;
	while (T) {
		//뻔
		if (flag == 0) T -= 1;
		if (T == 0) {
			cout << idx;
			return;
		}
		idx += 1;
		idx %= A;
		//데기
		if (flag == 1) T -= 1;
		if (T == 0) {
			cout << idx;
			return;
		}
		idx += 1;
		idx %= A;
		//뻔
		if (flag == 0) T -= 1;
		if (T == 0) {
			cout << idx;
			return;
		}
		idx += 1;
		idx %= A;
		//데기
		if (flag == 1) T -= 1;
		if (T == 0) {
			cout << idx;
			return;
		}
		idx += 1;
		idx %= A;
		//뻔
		for (int i = 0; i <= circle; ++i) {
			if (flag == 0) T -= 1;
			if (T == 0) {
				cout << idx;
				return;
			}
			idx += 1;
			idx %= A;
		}
		//데기
		for (int i = 0; i <= circle; ++i) {
			if (flag == 1) T -= 1;
			if (T == 0) {
				cout << idx;
				return;
			}
			idx += 1;
			idx %= A;
		}
		circle += 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}