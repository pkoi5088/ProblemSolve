#include <iostream>
#define endl '\n'

using namespace std;

void solve() {
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		if (b % a == 0) cout << "factor\n";
		else if (a % b == 0)  cout << "multiple\n";
		else cout << "neither\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
