#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_N 100
#define MAX_M 10001
#define endl '\n'

using namespace std;

struct node {
	int now, cost, time;
	node(int inNow, int inCost, int inTime) :now(inNow), cost(inCost), time(inTime) {}
};

struct cmp {
	bool operator()(node n1, node n2) {
		return n1.time > n2.time;
	}
};

void solve() {
	//to,{cost,time}
	vector<pair<int, pair<int, int>>> graph[MAX_N];
	//dist[i][j]: i를 j원 이하로 갈수있는 최소시간
	int dist[MAX_N][MAX_M];
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i) {
		int u, v, c, d;
		cin >> u >> v >> c >> d;
		graph[u - 1].push_back({ v - 1,{c,d} });
	}
	memset(dist, -1, sizeof(dist));

	priority_queue<node, vector<node>, cmp> pq;
	pq.push(node(0, 0, 0));
	dist[0][0] = 0;
	while (!pq.empty()) {
		int now = pq.top().now, cost = pq.top().cost, time = pq.top().time;
		pq.pop();
		if (dist[now][cost] < time) continue;
		for (int i = 0; i < graph[now].size(); ++i) {
			int nextNode = graph[now][i].first, nextCost = cost + graph[now][i].second.first, nextTime = time + graph[now][i].second.second;
			if (nextCost > M) continue;
			if (dist[nextNode][nextCost] == -1 || dist[nextNode][nextCost] > nextTime) {
				//update
				pq.push(node(nextNode, nextCost, nextTime));
				for (int j = nextCost; j <= M; ++j) {
					if (dist[nextNode][j] == -1 || dist[nextNode][j] > nextTime)
						dist[nextNode][j] = nextTime;
				}
			}
		}
	}
	if (dist[N - 1][M] == -1) cout << "Poor KCM" << endl;
	else cout << dist[N - 1][M] << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
