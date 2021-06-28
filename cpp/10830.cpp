#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MOD 1000
#define endl '\n'

using namespace std;

int N;

vector<vector<int>> operator* (vector<vector<int>> m1, vector<vector<int>> m2) {
	vector<vector<int>> R = m1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int tmp = 0;
			for (int k = 0; k < N; ++k) {
				tmp += m1[i][k] * m2[k][j];
			}
			R[i][j] = tmp % MOD;
			tmp = 0;
		}
	}
	return R;
}

vector<vector<int>> pow(vector<vector<int>> m, long long B) {
	if (B == 1)
		return m;
	else if (B % 2 == 1) {
		vector<vector<int>> R = pow(m, B / 2);
		return m * R * R;
	}
	else {
		vector<vector<int>> R = pow(m, B / 2);
		return R * R;
	}
}

void solve() {
	vector<vector<int>> mat, result;
	long long B;
	cin >> N >> B;
	mat.resize(N);
	for (int i = 0; i < N; ++i) {
		mat[i].resize(N);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> mat[i][j];
		}
	}
	result = pow(mat, B);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << result[i][j] % MOD << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
