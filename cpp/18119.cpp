#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	vector<unsigned int> original;
	int N, M, mind = 0xfffffff;
	cin >> N >> M;
	original.resize(N, 0);
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); ++j) {
			original[i] |= (1 << (s[j] - 'a'));
		}
	}

	for (int i = 0; i < M; ++i) {
		int x, cnt = 0;
		char c;
		cin >> x >> c;
		if (x == 1) {
			mind &= ~((unsigned int)1 << (c - 'a'));
		}
		else {
			mind |= ((unsigned int)1 << (c - 'a'));
		}

		for (int i = 0; i < N; ++i) {
			if ((original[i] & mind) == original[i]) {
				cnt += 1;
			}
		}
		cout << cnt << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
