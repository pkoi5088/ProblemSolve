#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 4000
#define endl '\n'

using namespace std;

vector<long long> a, b;
int num[4][MAX];
int N;

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> num[0][i] >> num[1][i] >> num[2][i] >> num[3][i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			a.push_back(num[0][i] + num[1][j]);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			b.push_back(num[2][i] + num[3][j]);
		}
	}
	sort(a.begin(), a.end());

	long long result = 0;
	for (int i = 0; i < b.size(); ++i) {
		auto lower = lower_bound(a.begin(), a.end(), -b[i]);
		auto upper = upper_bound(a.begin(), a.end(), -b[i]);
		result += (upper - lower);
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
