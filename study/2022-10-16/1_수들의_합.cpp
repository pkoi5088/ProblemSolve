#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1789
*/

void solve() {
	long long N = 1, S;
	cin >> S;
	while (N * (N + 1) / 2 <= S)
		N += 1;
	cout << N - 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}