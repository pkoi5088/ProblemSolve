#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 1000000
#define endl '\n'

using namespace std;

vector<int> tree[MAX];
int dp[2][MAX];
int N;
//dfs의 방문 노트를 찾기 위한 배열
bool visit[MAX] = { false };

int dfs(int adapt, int n) {
	if (dp[adapt][n] != -1) {
		return dp[adapt][n];
	}
	dp[adapt][n] = adapt;
	for (int i = 0; i < tree[n].size(); ++i) {
		int next = tree[n][i];
		if (visit[next] == false) {
			visit[next] = true;
			if (adapt) {
				dp[adapt][n] += min(dfs(0, tree[n][i]), dfs(1, tree[n][i]));
			}
			else {
				dp[adapt][n] += dfs(1, tree[n][i]);
			}
			visit[next] = false;
		}
	}
	return dp[adapt][n];
}

void solve() {
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		tree[a - 1].push_back(b - 1);
		tree[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < N; ++i) {
		dp[0][i] = dp[1][i] = -1;
	}

	visit[0] = true;
	cout << min(dfs(0, 0), dfs(1, 0)) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
