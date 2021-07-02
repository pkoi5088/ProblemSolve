#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#define INF 1001
#define endl '\n'

using namespace std;

void pick(vector<int>& light, int x, int y) {
	light[x] ^= (1 << y);
	if (x != 0) light[x - 1] ^= (1 << y);
	if (x != 9) light[x + 1] ^= (1 << y);
	if (y != 0) light[x] ^= (1 << (y - 1));
	if (y != 9) light[x] ^= (1 << (y + 1));
}

void solve() {
	vector<int> light(10, 0);
	for (int i = 0; i < 10; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < 10; ++j) {
			if (s[j] == 'O') {
				light[i] |= (1 << j);
			}
		}
	}
	
	int result = INF;
	for (int first = 0; first < (1 << 10); ++first) {
		vector<int> tmp = light;
		int cnt = 0;
		for (int i = 0; i < 10; ++i) {
			if (first & (1 << i)) {
				pick(tmp, 0, i);
				cnt += 1;
			}
		}

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (tmp[i] & (1 << j)) {
					pick(tmp, i + 1, j);
					cnt += 1;
				}
			}
		}
		if (tmp[9] != 0) cnt = INF;
		result = min(result, cnt);
	}
	cout << (result == INF ? -1 : result);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
