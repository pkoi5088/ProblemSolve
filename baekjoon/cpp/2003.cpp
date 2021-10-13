#include <iostream>
#define MAX 10000
#define endl '\n'

using namespace std;

int N, M, A[MAX], psum[MAX];
int pleft = 0, pright = 0;

int getSum(int l, int r) {
	if (l == r) return A[r];
	if (l == 0) return psum[r];
	return psum[r] - psum[l - 1];
}

void solve() {
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	psum[0] = A[0];
	for (int i = 1; i < N; ++i)
		psum[i] = psum[i - 1] + A[i];

	while (pleft <= pright && pright < N) {
		int r = getSum(pleft, pright);
		if (r == M) {
			cnt++;
			pright++;
		}
		else if (r < M) {
			pright++;
		}
		else
			if (pleft < pright)
				pleft++;
			else
				pright++;
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
