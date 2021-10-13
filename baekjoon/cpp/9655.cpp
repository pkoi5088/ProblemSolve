#include <iostream>

using namespace std;

void solve() {
	int N;
	cin >> N;
	if (N % 4 == 1 || N % 4 == 3)
		cout << "SK";
	else
		cout << "CY";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}