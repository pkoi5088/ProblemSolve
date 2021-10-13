#include <iostream>
#define MAX 1000
#define endl '\n'

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int query(int* psum, int i, int j) {
	if (i == 0) return psum[j];
	return psum[j] - psum[i - 1];
}

void solve() {
	int num[MAX], psum[MAX];
	int N, ret;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	psum[0] = num[0];
	for (int i = 1; i < N; ++i) {
		psum[i] = psum[i - 1] + num[i];
	}

	ret = num[0];
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			ret = max(ret, query(psum, i, j));
		}
	}
	cout << ret << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
