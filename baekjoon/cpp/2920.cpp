#include <iostream>
#include <cstdio>

using namespace std;

string solve() {
	int board[8], i, d;
	for (i = 0; i < 8; i++)
		cin >> board[i];
	d = board[1] - board[0];
	if (d != 1 && d != -1)
		return "mixed";
	for (i = 2; i < 8; i++) {
		if (board[i] - board[i - 1] != d)
			return "mixed";
	}
	if (d == 1)
		return "ascending";
	else
		return "descending";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}