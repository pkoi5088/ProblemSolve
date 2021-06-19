#include <iostream>
#include <utility>
#include <vector>
#include <queue>

#define INF 1000000001

using namespace std;

int function(vector<pair<int, int>>* board, int* dist, int& start, int& end) {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_q;

	p_q.push({ 0,start });
	
	while (!p_q.empty()) {
		int cdist = p_q.top().first;
		int cVertex = p_q.top().second;
		p_q.pop();

		for (int i = 0; i < board[cVertex].size(); i++) {
			if (board[cVertex][i].first + dist[cVertex] < dist[board[cVertex][i].second]) {
				dist[board[cVertex][i].second] = board[cVertex][i].first + dist[cVertex];
				p_q.push({ board[cVertex][i].first,board[cVertex][i].second });
			}
		}
	}
	return dist[end];
}

int main() {
	int N, M, start, end;
	cin >> N >> M;

	vector<pair<int,int>>* board = new vector<pair<int, int>>[N + 1];
	int* dist = new int[N + 1];
	for (int i = 0; i <= N; i++)
		dist[i] = INF;

	for (int i = 0; i < M; i++) {
		int t1, t2, d;
		cin >> t1 >> t2 >> d;
		board[t1].push_back({ d,t2 });
	}

	cin >> start >> end;
	cout << function(board, dist, start, end);
	return 0;
}