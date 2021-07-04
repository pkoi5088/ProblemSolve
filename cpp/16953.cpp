#include <iostream>

using namespace std;

int solve() {
	int A, B, cnt = 0;
	cin >> A >> B;

	while (1) {
		if (B == A)
			return cnt + 1;
		else if(B < A)
			break;

		if (B % 2 == 0)
			B = B / 2;
		else if (B % 10 == 1)
			B = B / 10;
		else
			break;
		cnt += 1;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << solve();
	return 0;
}