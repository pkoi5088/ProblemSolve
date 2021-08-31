#include <iostream>
#define MAX 50
#define MOD 1000000007
#define endl '\n'

using namespace std;

long long getFact(int n) {
	long long ret = 1;
	for (long long i = 1; i < n + 1; ++i) {
		ret *= i;
		ret %= MOD;
	}
	return ret;
}

long long getPower(int n, int k) {
	if (k == 1) return n;
	long long tmp = getPower(n, k / 2);
	if (k % 2) return (((long long)n * tmp) % MOD * tmp) % MOD;
	else return (tmp * tmp) % MOD;
}

void solve() {
	int N, K;
	cin >> N >> K;
	cout << (getFact(N) % MOD * getPower(getFact(K) * getFact(N - K), MOD - 2) % MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
