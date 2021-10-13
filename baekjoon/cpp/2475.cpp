#include <iostream>
#include <cstdio>

using namespace std;

int solve() {
	int sum = 0, x;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		sum += x * x;
	}
	return sum % 10;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}