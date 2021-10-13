#include <iostream>
#define MAX 46
#define endl '\n'

using namespace std;

void solve() {
	int f[MAX], N;
	f[0] = 0, f[1] = 1;
	for (int i = 2; i < MAX; ++i)
		f[i] = f[i - 2] + f[i - 1];
	cin >> N;
	cout << f[N];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
