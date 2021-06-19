#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

bool check[1000001] = { false };
long long offset, M;

void solve() {
	cin >> offset >> M;
	for (long long i = 2; i <= sqrt(M); i++) {
		long long start = (offset / (i * i) + !!(offset % (i * i))) * i * i;
		for (; start <= M; start += i * i) {
			check[start - offset] = true;
		}
	}
	int cnt = 0;
	for (int i = 0; i <= M - offset; i++) {
		if (check[i] == false) {
			cnt += 1;
		}
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
