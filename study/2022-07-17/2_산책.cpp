#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define MAX 10000

using namespace std;

/*
	https://www.acmicpc.net/problem/22868
*/

bool graph[MAX][MAX] = { false, };
bool visit[MAX] = { false };
int N, M;

int function(int S, int E) {
	bool check[MAX] = { false };
	queue<pair<int, vector<int>>> q;
	q.push({ S,{S} });
	check[S] = true;
	while (!q.empty()) {
		int idx = q.front().first;
		vector<int> route = q.front().second;
		q.pop();

		if (idx == E) {
			for (int i = 0; i < route.size(); ++i) {
				visit[route[i]] = true;
			}
			visit[route[0]] = false;
			return route.size() - 1;
		}

		for (int i = 0; i < N; ++i) {
			if (graph[idx][i] == false || check[i] || visit[i]) continue;
			vector<int> tmp = route;
			tmp.push_back(i);
			q.push({ i,tmp });
			check[i] = true;
		}
	}
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = true;
		graph[b - 1][a - 1] = true;
	}
	int S, E, ret = 0;
	cin >> S >> E;
	ret += function(S - 1, E - 1);
	ret += function(E - 1, S - 1);
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}