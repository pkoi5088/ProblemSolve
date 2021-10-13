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
#define MAX 100000
#define INF 400000000
#define endl '\n'

using namespace std;

int num[MAX], dp[MAX][5][5];
int N = 0;

int pick(int n, int left, int right) {
	if (n == N) return 0;
	else if (dp[n][left][right] != -1) return dp[n][left][right];
	
	//이미 밟고 있을 때
	if (num[n] == left || num[n] == right)
		return dp[n][left][right] = pick(n + 1, left, right) + 1;

	//왼발
	int l = INF, r = INF;
	if (left == 0) {
		l = pick(n + 1, num[n], right) + 2;
	}
	else {
		int dist = abs(num[n] - left);
		if (dist == 1 || dist == 3) l = pick(n + 1, num[n], right) + 3;
		else if (dist == 2) l = pick(n + 1, num[n], right) + 4;
	}
	
	//오른발
	if (right == 0) {
		r = pick(n + 1, left, num[n]) + 2;
	}
	else {
		int dist = abs(num[n] - right);
		if (dist == 1 || dist == 3) r = pick(n + 1, left, num[n]) + 3;
		else if (dist == 2) r = pick(n + 1, left, num[n]) + 4;
	}
	return dp[n][left][right] = min(l, r);
}

void solve() {
	memset(dp, -1, sizeof(dp));
	while (true) {
		cin >> num[N];
		if (num[N] == 0)
			break;
		N += 1;
	}
	cout << pick(0, 0, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
