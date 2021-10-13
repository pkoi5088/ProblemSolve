#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	int cnt = 0, i = 0, j = 0, N, M;
	string a, b;
	getline(cin, a);
	getline(cin, b);
	N = a.size(), M = b.size();
	while (i < N - M + 1) {
		j = 0;
		while (j < M) {
			if (a[i + j] != b[j])
				break;
			j++;
		}
		if (j == M) {
			cnt++;
			i += M;
		}else{
			i++;
		}
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
