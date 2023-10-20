#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

void solve() {
	int N, cnt = 0, total = 0;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		cnt += v[i] / 2;
		total += v[i];
	}

	if (total % 3 || cnt < total / 3) {
		cout << "NO";
		return;
	}
	cout << "YES";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}