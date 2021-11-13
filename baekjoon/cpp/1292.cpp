#include <iostream>
#define endl '\n'

using namespace std;

void solve() {
	int A, B, cnt = 1, ret = 0;
	cin >> A >> B;
	for (int i = 1;; ++i) {
		for (int j = 0; j < i; ++j) {
			if (cnt >= A && cnt <= B)
				ret += i;
			else if (cnt > B) {
				cout << ret;
				return;
			}
			cnt += 1;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
