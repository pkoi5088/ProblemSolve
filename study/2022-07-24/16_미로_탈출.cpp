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

int min(int a,int b){
    if(a==-1) return b;
    if(b==-1) return a;
    return a<b?a:b;
}

//0:정순, 1:역순
int graph[MAX][MAX][2];
int table[MAX], cache[MAX];

void init() {
	for (int i = 0; i < MAX; ++i)
		table[i] = -1;
	for (int i = 0; i < MAX; ++i)
		cache[i] = INF;
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			graph[i][j][0] = graph[i][j][1] = -1;
		}
	}
}

int getType(int from, int to, int route) {
	int tmp1 = route & (1 << from), tmp2 = route & (1 << to);
	if (tmp1 == 0 && tmp2 != 0) return 1;
	else if (tmp2 == 0 && tmp1 != 0) return 1;
	return 0;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
	init();
	for (int i = 0; i < traps.size(); ++i) {
		table[traps[i] - 1] = i;
	}

	for (int i = 0; i < roads.size(); ++i) {
		int a = roads[i][0] - 1, b = roads[i][1] - 1, c = roads[i][2];
		graph[a][b][0] = min(graph[a][b][0],c);
		if (table[a] != -1 || table[b] != -1)
			graph[b][a][1] = min(graph[b][c][0],c);
	}

	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push(Node(start-1, 0, 0));
	cache[start-1] = 0;
	while (!pq.empty()) {
		int now = pq.top().idx, route = pq.top().route, dist = pq.top().dist;
		pq.pop();

		if (dist > cache[now])
			continue;
		if (now == end-1)
			return dist;

		if (table[now] != -1) {
			route ^= (1 << now);
		}
		for (int next = 0; next < n; ++next) {
			if (now == next) continue;
			int nextCost = graph[now][next][getType(now, next, route)];
			if (nextCost == -1 || (dist + nextCost >= cache[next] && table[next] == -1)) continue;
			pq.push(Node(next, route, dist + nextCost));
			cache[next] = dist + nextCost;
		}
	}
}