#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

/*
    https://www.acmicpc.net/problem/16236
*/

class Node {
public:
	int x, y, dist;
	Node(int ix, int iy, int id) :x(ix), y(iy), dist(id) {};
};

struct cmp {
	bool operator()(Node n1, Node n2) {
		if (n1.dist == n2.dist) {
			if (n1.x == n2.x)
				return n1.y > n2.y;
			else
				return n1.x > n2.x;
		}
		else {
			return n1.dist > n2.dist;
		}
	}
};

int graph[20][20] = { 0 }, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
bool visit[20][20] = { false };
int N, nowX, nowY, nowSize = 2, grow = 2;

void reset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
		}
	}
}

Node getNext() {
	priority_queue<Node, vector<Node>, cmp> pq;
	queue<Node> q;
	reset();
	q.push(Node(nowX, nowY, 0));
	visit[nowX][nowY] = true;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, dist = q.front().dist;
		q.pop();

		if (!pq.empty() && pq.top().dist < dist) {
			break;
		}

		//다음 칸
		for (int l = 0; l < 4; l++) {
			int nx = x + dx[l], ny = y + dy[l];
			//범위내에 있고
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				//먹을때
				if (visit[nx][ny] == false && graph[nx][ny] != 0 && graph[nx][ny] < nowSize) {
					pq.push(Node(nx, ny, dist + 1));
					visit[nx][ny] = true;
				}
				//이동할 때
				else if (visit[nx][ny] == false && graph[nx][ny] <= nowSize) {
					q.push(Node(nx, ny, dist + 1));
					visit[nx][ny] = true;
				}
			}
		}
	}

	if (pq.empty())
		return Node(-1, -1, -1);
	else
		return pq.top();
}

int solve() {
	int result = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 9) {
				nowX = i; nowY = j;
			}
		}
	}

	while (true) {
		Node next = getNext();
		if (next.x == -1 && next.y == -1)
			return result;
		graph[nowX][nowY] = 0;
		graph[next.x][next.y] = 9;
		nowX = next.x;
		nowY = next.y;
		result += next.dist;
		if (--grow == 0) {
			nowSize += 1;
			grow = nowSize;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}
