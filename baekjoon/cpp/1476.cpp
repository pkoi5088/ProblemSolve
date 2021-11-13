#include <iostream>
#define endl '\n'

using namespace std;

void solve() {
	int E, S, M, ret = 1;
	cin >> E >> S >> M;
	while (true) {
		if ((ret - 1) % 15 + 1 == E && (ret - 1) % 28 + 1 == S && (ret - 1) % 19 + 1 == M)
			break;
		ret += 1;
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
