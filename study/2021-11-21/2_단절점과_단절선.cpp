#include <iostream>
#define MAX 100000
#define endl '\n'

using namespace std;

int near[MAX] = { 0, };
int N, Q;

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		near[a - 1] += 1;
		near[b - 1] += 1;
	}
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int t, k;
		cin >> t >> k;
		if (t == 1) {
			if (near[k - 1] >= 2) {
				cout << "yes" << endl;
			}
			else {
				cout << "no" << endl;
			}
		}
		else {
			cout << "yes" << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
