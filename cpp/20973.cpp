#include <iostream>
#define endl '\n'

using namespace std;

void solve() {
	int index[26], cnt = 1;
	string cowphabet, hear;
	cin >> cowphabet >> hear;

	for (int i = 0; i < cowphabet.size(); ++i)
		index[cowphabet[i] - 'a'] = i;
	for (int i = 0; i < hear.size(); ++i) {
		if (i - 1 >= 0 && index[hear[i - 1] - 'a'] >= index[hear[i] - 'a']) {
			cnt += 1;
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
