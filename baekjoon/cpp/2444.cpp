#include <iostream>
#define endl '\n'

using namespace std;

void solve() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < N - i; ++j)
			cout << ' ';
		for (int j = 0; j < 2 * i - 1; ++j)
			cout << '*';
		cout << endl;
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j)
			cout << ' ';
		for (int j = 0; j < 2 * (N - i) - 1; ++j)
			cout << '*';
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
