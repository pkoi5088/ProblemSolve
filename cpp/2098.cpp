#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 16000001
#define MAX 16
#define endl '\n'

using namespace std;

//dp[n][route]: n에서 route를 경유했을 때 최소비용
int graph[MAX][MAX], dp[MAX][1 << MAX];
int N, goal;

//bfs를 쓰면 메모리초과 발생
//현재위치가 now이고 route를 거쳤을 때 최소비용 찾기
int dfs(int now, int route) {
	if (dp[now][route] != -1) {
		return dp[now][route];
	}
	if (route == goal) {
		if (graph[now][0] == 0) {
			return dp[now][route] = INF;
		}
		else {
			return dp[now][route] = graph[now][0];
		}
	}

	int tmp = INF;
	for (int i = 0; i < N; ++i) {
		if ((route & (1 << i)) == 0 && graph[now][i] != 0) {
			tmp = min(tmp, dfs(i, route | (1 << i)) + graph[now][i]);
		}
	}
	return dp[now][route] = tmp;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < (1 << N); ++j) {
			dp[i][j] = -1;
		}
	}
	goal = (1 << N) - 1;
	cout << dfs(0, 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
