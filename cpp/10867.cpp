#include <iostream>
#include <algorithm>
#define MAX 100001
#define INF 10000
#define endl '\n'

using namespace std;

int num[MAX];
int N;

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i];
	sort(num, num + N);
	num[N] = INF;
	for (int i = 0; i < N; ++i) {
		if (num[i] != num[i + 1]) {
			cout << num[i] << ' ';
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
