#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 2500
#define endl '\n'

using namespace std;

//dp[i][j]: [i:j]구간의 문자열이 팰린드롬인가?
int dp[MAX][MAX] = { 0 }, result[MAX] = { 0 };
string S;

int check(int a, int b) {
	if (dp[a][b] != -1)
		return dp[a][b];
	if (a == b)
		return dp[a][b] = 1;
	if (a + 1 == b)
		return dp[a][b] = (S[a] == S[b]);
	if (S[a] == S[b])
		return dp[a][b] = check(a + 1, b - 1);
	return dp[a][b] = 0;
}

void solve() {
	cin >> S;
	for (int i = 0; i < S.size(); ++i) {
		for (int j = 0; j < S.size(); ++j) {
			dp[i][j] = -1;
		}
	}
	int N = S.size();
	for (int i = 0; i < N; ++i) {
		result[i] = (i == 0 ? 1 : result[i - 1] + 1);
		//i==j가 가능해 최소 한번은 팰린드롬 발생
		for (int j = 0; j < i + 1; ++j) {
			if (check(j, i)) {
				result[i] = (j == 0 ? 1 : min(result[i], result[j - 1] + 1));
			}
		}
	}
	cout << result[N - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
