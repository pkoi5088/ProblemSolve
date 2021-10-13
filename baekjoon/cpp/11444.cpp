#include <iostream>
#include <vector>
#define endl "\n"
#define MOD 1000000007

using namespace std;

vector<long long int> mul(vector<long long int>v1, vector<long long int>v2) {
	vector<long long int> ret(4);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			long long int tmp = 0;
			for (int k = 0; k < 2; ++k) {
				tmp += v1[2 * i + k] * v2[2 * j + k];
				tmp %= MOD;
			}
			ret[2 * i + j] = tmp;
		}
	}
	return ret;
}

vector<long long int> f(vector<long long int> v,long long int N) {
	if (N == 1) return v;
	vector<long long int> tmp = f(v, N / 2);
	if (N % 2) return mul(mul(tmp, tmp), v);
	else return mul(tmp, tmp);
}

void solve() {
	long long int N;
	cin >> N;
	vector<long long int> v(4), tmp;
	v[0] = v[1] = v[2] = 1;
	v[3] = 0;
	tmp = f(v, N);
	cout << tmp[1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}