#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#define MAX 10
#define endl '\n'

using namespace std;

struct Node {
	int bx, by, rx, ry, dist;
	Node(int ibx, int iby, int irx, int iry, int id)
		:bx(ibx), by(iby), rx(irx), ry(iry), dist(id) {}
};

string board[MAX];
bool visit[MAX][MAX][MAX][MAX] = { false };
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int N, M;

void solve() {
	int bx, by, rx, ry, ox, oy;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> board[i];
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == 'B') {
				bx = i; by = j; board[i][j] = '.';
			}
			else if (board[i][j] == 'R') {
				rx = i; ry = j; board[i][j] = '.';
			}
			else if (board[i][j] == 'O') {
				ox = i; oy = j;
			}
		}
	}

	int result = -1;
	queue<Node> q;
	q.push(Node(bx, by, rx, ry, 0));
	visit[bx][by][rx][ry] = true;
	while (!q.empty()) {
		bx = q.front().bx, by = q.front().by;
		rx = q.front().rx, ry = q.front().ry;
		int dist = q.front().dist;
		q.pop();
		if (dist > 10) continue;

		if (rx == ox && ry == oy && !(bx == ox && by == oy)) {
			if (result == -1) result = dist;
			else result = min(result, dist);
		}
		else if (bx == ox && by == oy) {
			continue;
		}

		//위
		int nbx = bx, nby = by, nrx = rx, nry = ry;
		while (true) {
			if (board[nbx - 1][nby] == '#' || (nbx == ox && nby == oy)) {
				break;
			}
			nbx += -1;
		}
		while (true) {
			if (board[nrx - 1][nry] == '#' || (nrx == ox && nry == oy)) {
				break;
			}
			nrx += -1;
		}
		if (nbx == nrx && nby == nry && !(nbx == ox && nby == oy)) {
			if (bx > rx) nbx += 1;
			else nrx += 1;
		}
		if (visit[nbx][nby][nrx][nry] == false) {
			q.push(Node(nbx, nby, nrx, nry, dist + 1));
			visit[nbx][nby][nrx][nry] = true;
		}

		//아래
		nbx = bx, nby = by, nrx = rx, nry = ry;
		while (true) {
			if (board[nbx + 1][nby] == '#' || (nbx == ox && nby == oy)) {
				break;
			}
			nbx += 1;
		}
		while (true) {
			if (board[nrx + 1][nry] == '#' || (nrx == ox && nry == oy)) {
				break;
			}
			nrx += 1;
		}
		if (nbx == nrx && nby == nry && !(nbx == ox && nby == oy)) {
			if (bx < rx) nbx += -1;
			else nrx += -1;
		}
		if (visit[nbx][nby][nrx][nry] == false) {
			q.push(Node(nbx, nby, nrx, nry, dist + 1));
			visit[nbx][nby][nrx][nry] = true;
		}

		//왼쪽
		nbx = bx, nby = by, nrx = rx, nry = ry;
		while (true) {
			if (board[nbx][nby - 1] == '#' || (nbx == ox && nby == oy)) {
				break;
			}
			nby += -1;
		}
		while (true) {
			if (board[nrx][nry - 1] == '#' || (nrx == ox && nry == oy)) {
				break;
			}
			nry += -1;
		}
		if (nbx == nrx && nby == nry && !(nbx == ox && nby == oy)) {
			if (by > ry) nby += 1;
			else nry += 1;
		}
		if (visit[nbx][nby][nrx][nry] == false) {
			q.push(Node(nbx, nby, nrx, nry, dist + 1));
			visit[nbx][nby][nrx][nry] = true;
		}

		//오른쪽
		nbx = bx, nby = by, nrx = rx, nry = ry;
		while (true) {
			if (board[nbx][nby + 1] == '#' || (nbx == ox && nby == oy)) {
				break;
			}
			nby += 1;
		}
		while (true) {
			if (board[nrx][nry + 1] == '#' || (nrx == ox && nry == oy)) {
				break;
			}
			nry += 1;
		}
		if (nbx == nrx && nby == nry && !(nbx == ox && nby == oy)) {
			if (by < ry) nby += -1;
			else nry += -1;
		}
		if (visit[nbx][nby][nrx][nry] == false) {
			q.push(Node(nbx, nby, nrx, nry, dist + 1));
			visit[nbx][nby][nrx][nry] = true;
		}
	}

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
