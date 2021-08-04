#include <iostream>
#define MAX 1000001
#define MOD 1000000000
#define endl '\n'

using namespace std;

void solve() {
	int fibo[MAX] = { 0, }, n;
	fibo[1] = 1;
	for (int i = 2; i < MAX; ++i)
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
	cin >> n;
	if (n >= 0) cout << !!n << endl;
	else cout << (abs(n) % 2 == 1 ? 1 : -1) << endl;
	cout << fibo[abs(n)];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
