#include <iostream>
#include <algorithm>
#define MAX 7
#define endl '\n'

using namespace std;

int num[MAX], tmp[MAX];
int N, M, idx = 0;

void pick(int n) {
	tmp[idx++] = num[n];
	if (idx == M) {
		for (int i = 0; i < idx; ++i) {
			cout << tmp[i] << ' ';
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < N; ++i)
			pick(i);
	}
	idx--;
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> num[i];
	sort(num, num + N);
	for (int i = 0; i < N; ++i) {
		pick(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
