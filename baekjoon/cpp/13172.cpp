#include <iostream>
#define endl '\n'
#define MOD 1000000007

using namespace std;

/*
	https://www.acmicpc.net/problem/13172
*/

long long fpow(long long a, long long x) {
	if (x == 0) return 1;
	if (x % 2) return (a * fpow(a, x - 1)) % MOD;
	long long ret = fpow(a, x / 2) % MOD;
	return (ret * ret) % MOD;
}

//first: 분자, second: 분모
void solve() {
	int N;
	long long ret = 0;

	cin >> N;
	while (N--) {
		long long n, s;
		cin >> n >> s;
		ret += (s * fpow(n, MOD - 2)) % MOD;
	}

	cout << ret % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}