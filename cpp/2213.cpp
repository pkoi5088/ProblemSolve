#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 10000
#define endl "\n"

using namespace std;

vector<int> graph[MAX];
int dp[MAX][2], arr[MAX];

int getDP(int n, int type, int parent) {
	int& ret = dp[n][type];
	if (ret != -1) return ret;

	ret = arr[n] * type;
	for (int& next : graph[n]) {
		if (next == parent) continue;
		if (type == 0) ret += max(getDP(next, 0, n), getDP(next, 1, n));
		else ret += getDP(next, 0, n);
	}
	return ret;
}

void solve(){
	memset(dp, -1, sizeof(dp));
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	cout << max(getDP(0, 0, -1), getDP(0, 1, -1)) << endl;

	vector<int> ret;
	queue<pair<int, pair<int, bool>>> q;
	if (dp[0][0] < dp[0][1]) {
		ret.push_back(0);
		q.push({ 0,{-1,true} });
	}
	else
		q.push({ 0,{-1,false} });
	while (!q.empty()) {
		int now = q.front().first, parent = q.front().second.first;
		bool flag = q.front().second.second;
		q.pop();

		for (int& next : graph[now]) {
			bool nextFlag = false;
			if (next == parent) continue;
			if (flag == false && dp[next][0] < dp[next][1]) {
				ret.push_back(next);;
				nextFlag = true;
			}
			q.push({ next,{now,nextFlag} });
		}
	}
	sort(ret.begin(), ret.end());
	for (int& a : ret) {
		cout << a + 1 << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}