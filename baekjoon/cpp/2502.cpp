#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 30
#define endl '\n'

using namespace std;

int cntA[MAX] = { 0 }, cntB[MAX] = { 0 };

void solve() {
	int D, K, A = 0, B;
	cin >> D >> K;
	cntA[0] = cntB[1] = 1;
	for (int i = 2; i < D; ++i) {
		cntA[i] = cntA[i - 1] + cntA[i - 2];
		cntB[i] = cntB[i - 1] + cntB[i - 2];
	}

	while (K % cntB[D - 1] != 0) {
		A += 1;
		K -= cntA[D - 1];
	}
	B = K / cntB[D - 1];
	cout << A << endl << B;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
