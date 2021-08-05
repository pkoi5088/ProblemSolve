#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10001
#define endl '\n'

using namespace std;

//dp[i][0]: i번 마을을 선택하지 않았을 때 최대 값
int dp[MAX][2], people[MAX];
int N;
vector<int> graph[MAX];

int getDP(int now, int type, int parent) {
	int& ret = dp[now][type];
	if (ret != -1) return ret;

	ret = people[now] * type;
	for (int i = 0; i < graph[now].size(); ++i) {
		int next = graph[now][i];
		if (next == parent) continue;
		if (type == 0) {
			ret += max(getDP(next, 0, now), getDP(next, 1, now));
		}
		else
			ret += getDP(next, 0, now);
	}
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> people[i];
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cout << max(getDP(1, 0, -1), getDP(1, 1, -1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
