#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2231
*/

int function(int N) {
	for (int i = 0; i < N; ++i) {
		int tmp = i, m = i;
		while (m != 0) {
			tmp += m % 10;
			m /= 10;
		}
		if (tmp == N) return i;
	}
	return 0;
}

void solve() {
	int N;
	cin >> N;
	cout << function(N);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}