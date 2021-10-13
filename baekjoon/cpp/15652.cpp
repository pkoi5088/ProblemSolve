#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 1500
#define endl '\n'

using namespace std;

int N, M;

void f(string& S) {
	if (S.size() == M) {
		for (int i = 0; i < S.size(); ++i) {
			cout << S[i] << ' ';
		}
		cout << endl;
	}
	else {
		int B = S.back() - '0';
		for (int i = B; i <= N; ++i) {
			S.push_back(i + '0');
			f(S);
			S.pop_back();
		}
	}
}

void solve() {
	string result = "";
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		result.push_back(i + '0');
		f(result);
		result.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
