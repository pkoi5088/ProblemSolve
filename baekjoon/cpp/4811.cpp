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
#define endl '\n'

using namespace std;

long long dp[31][31];

//w는 한조각 h는 반조각
long long pick(int w, int h) {
	if (w == -1 || h == -1) return 0;
	if (dp[w][h] != -1) return dp[w][h];
	else if (w < h) return dp[w][h] = 0;
	return dp[w][h] = pick(w, h - 1) + pick(w - 1, h);
}

void solve() {
	int T;
	while (true) {
		cin >> T;
		if (!T)
			break;
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 1;
		cout << pick(T, T) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
