#include <iostream>
#define endl "\n"

using namespace std;

void solve() {
	int N;
	cin >> N;
	int a = 1000001, b = -1, t;
	while (N--) {
		cin >> t;
		a = a > t ? t : a;
		b = b < t ? t : b;
	}
	cout << a * b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}