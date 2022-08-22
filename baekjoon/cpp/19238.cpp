#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define INF 2000000000

using namespace std;

/*
	https://www.acmicpc.net/problem/19238
*/

struct Person {
	pair<int, int> loc, goal;
	int cost;
};

vector<Person> person;
vector<bool> finish;
vector<vector<int>> arr;
int N, M, fuel;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

int getDist(int sx, int sy, int gx, int gy) {
	vector<vector<bool>> visit(N, vector<bool>(N, false));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {sx,sy},0 });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second, dist = q.front().second;
		q.pop();

		if (x == gx && y == gy) {
			return dist;
		}

		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny] || arr[nx][ny] == 1) continue;
			q.push({ {nx,ny},dist + 1 });
			visit[nx][ny] = true;
		}
	}
	return INF;
}

//최단거리 idx반환
int getNext(int x, int y) {
	int ret = -1, retDist = 0;
	for (int i = 0; i < M; ++i) {
		if (finish[i]) continue;
		int nextDist = getDist(x, y, person[i].loc.first, person[i].loc.second);
		if (ret == -1 || retDist > nextDist) {
			ret = i;
			retDist = nextDist;
		}
		else if (retDist == nextDist) {
			if (person[ret].loc.first > person[i].loc.first) {
				ret = i;
			}
			else if (person[ret].loc.first == person[i].loc.first) {
				if (person[ret].loc.second > person[i].loc.second) {
					ret = i;
				}
			}
		}
	}
	if (retDist == INF) return -1;
	return ret;
}

void solve() {
	cin >> N >> M >> fuel;
	person.resize(M); finish.resize(M);
	arr.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	int x, y;
	cin >> x >> y;
	x -= 1; y -= 1;
	for (int i = 0; i < M; ++i) {
		cin >> person[i].loc.first >> person[i].loc.second;
		cin >> person[i].goal.first >> person[i].goal.second;
		person[i].loc.first -= 1; person[i].loc.second -= 1;
		person[i].goal.first -= 1; person[i].goal.second -= 1;
		person[i].cost = getDist(person[i].loc.first, person[i].loc.second, person[i].goal.first, person[i].goal.second);
	}

	int cnt = 0;
	while (cnt < M) {
		int idx = getNext(x, y);
		if (idx == -1) break;
		int cost = getDist(x, y, person[idx].loc.first, person[idx].loc.second) + person[idx].cost;
		if (cost <= fuel) {
			finish[idx] = true;
			x = person[idx].goal.first, y = person[idx].goal.second;
			fuel += 2 * person[idx].cost - cost;
			cnt += 1;
		}
		else {
			break;
		}
	}
	if (cnt == M)
		cout << fuel;
	else
		cout << -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}