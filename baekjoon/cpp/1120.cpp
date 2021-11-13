#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	string A, B;
	cin >> A >> B;
	int ret = 51;
	for (int i = 0; i < B.size() - A.size() + 1; ++i) {
		int cnt = 0;
		for (int j = 0; j < A.size(); ++j) {
			if (A[j] != B[i + j])
				cnt += 1;
		}
		ret = min(ret, cnt);
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
