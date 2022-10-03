#include <iostream>
#define endl '\n'
#define MOD 1000000007

using namespace std;

/*
	https://www.acmicpc.net/problem/11401
*/

long long fpow(long long a, long long x) {
	if (x == 0) return 1;
	if (x % 2) return (fpow(a, x - 1) * a) % MOD;
	long long ret = fpow(a, x / 2);
	return (ret * ret) % MOD;
}

void solve() {
	long long N, K, A = 1, B = 1;
	cin >> N >> K;
	for (long long i = 1; i <= N; ++i) {
		A *= i;
		A %= MOD;
	}
	for (long long i = 1; i <= K; ++i) {
		B *= i;
		B %= MOD;
	}
	for (long long i = 1; i <= N - K; ++i) {
		B *= i;
		B %= MOD;
	}
	
	long long ret;
	ret = (A * fpow(B, MOD - 2)) % MOD;
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}