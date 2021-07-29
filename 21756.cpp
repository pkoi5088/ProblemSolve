#include <iostream>
#define endl '\n'

using namespace std;

void solve() {
	int N, tmp = 1;
	cin >> N;
	while (tmp <= N) {
		tmp = tmp * 2;
	}
	cout << tmp / 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
