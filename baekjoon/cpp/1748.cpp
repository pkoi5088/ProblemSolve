#include <iostream>
#define endl '\n'

using namespace std;

void solve() {
	int start = 0, end = 10, cnt = 1, N, ret = 0;
	cin >> N;
	while (true) {
		if (start <= N && N < end) {
			ret += (N - start + 1) * cnt;
			break;
		}
		ret += (end - start) * cnt;
		cnt += 1;
		start = end;
		end *= 10;
	}
	cout << ret - 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
