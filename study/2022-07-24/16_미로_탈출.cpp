#include <string>
#include <vector>
#include <queue>
#define MAX 1000
#define INF 1000000000

using namespace std;

struct Node {
	int idx, route, dist;
	Node(int id, int ir, int idist) {
		idx = id;
		route = ir;
		dist = idist;
	}
};

struct cmp {
	bool operator()(Node n1, Node n2) {
		return n1.dist > n2.dist;
	}
};

int min(int a, int b) {
	if (a == -1) return b;
	if (b == -1) return a;
	return a < b ? a : b;
}

//0:정순, 1:역순
int graph[MAX][MAX][2];
int table[MAX], cache[MAX][(1 << 10)];

void init() {
	for (int i = 0; i < MAX; ++i)
		table[i] = -1;
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < (1 << 10); ++j) {
			cache[i][j] = INF;
		}
	}
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			graph[i][j][0] = graph[i][j][1] = -1;
		}
	}
}

int getType(int from, int to, int route) {
	int fromIdx = table[from], toIdx = table[to];
	//둘다 트랩이 아닐 때
	if (fromIdx == -1 && toIdx == -1) return 0;
	//둘다 트랩일 때
	else if (fromIdx != -1 && toIdx != -1) {
		//둘중 하나만 밟은 상태면
		if (!(route & (1 << fromIdx)) || !(route & (1 << toIdx))) return 1;
		else return 0;
	}
	//from만 트랩일 때
	else if (fromIdx != -1) {
		if (route & (1 << fromIdx))
			return 1;
		return 0;
	}
	else {
		if (route & (1 << toIdx))
			return 1;
		return 0;
	}
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
	init();
	for (int i = 0; i < traps.size(); ++i) {
		table[traps[i] - 1] = i;
	}

	for (int i = 0; i < roads.size(); ++i) {
		int a = roads[i][0] - 1, b = roads[i][1] - 1, c = roads[i][2];
		graph[a][b][0] = min(graph[a][b][0], c);
		if (table[a] != -1 || table[b] != -1)
			graph[b][a][1] = min(graph[b][a][1], c);
	}

	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push(Node(start - 1, 0, 0));
	cache[start - 1][0] = 0;
	while (!pq.empty()) {
		int now = pq.top().idx, route = pq.top().route, dist = pq.top().dist;
		pq.pop();

		if (dist > cache[now][route])
			continue;
		if (now == end - 1)
			return dist;

		for (int next = 0; next < n; ++next) {
			if (now == next) continue;
			int nextCost = graph[now][next][getType(now, next, route)];
			int nextRoute = route;
			if (table[next] != -1) {
				nextRoute ^= (1 << table[next]);
			}
			if (nextCost == -1 || dist + nextCost >= cache[next][nextRoute]) continue;
			pq.push(Node(next, nextRoute, dist + nextCost));
			cache[next][nextRoute] = dist + nextCost;
		}
	}
}